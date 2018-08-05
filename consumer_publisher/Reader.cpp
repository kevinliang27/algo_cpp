#include<iostream>
#include<iomanip>
#include<string>
#include<cerrno>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<Constants.h>
#include<Pipe.h>
#include<thread>
#include<functional>
#include<sstream>
#include<vector>

using namespace std;

vector<string> readPipe(int fd) {
    vector<string> ret;   
    ostringstream line;
    char buf[BlockSize+1];
    int readed = BlockSize;
    while(readed) {
        readed = read(fd, buf, sizeof(buf) -1);
        buf[readed] = 0;
        line << buf;
        cout << "readed:" << readed <<", now buffer:"<< buf 
             << ", line:" << line.str() << endl;
        if (readed == 0 || buf[readed -1] == 0) {
            if (line.str().size() > 0 ) ret.emplace_back(line.str());
            line = ostringstream();

            //cout << "add line:" << line.str() << " to vector" << endl;
        }
    }
    //cout<<"finish reading" << endl;
    return ret;
}

void consume(const char* fifoName) {

    bool running = true;
    while(running) 
    {
        cout << "start reading" << endl;
        NamedPipe pipe(fifoName, O_RDONLY);
        auto lines = readPipe(pipe.fd());
        for (auto line : lines) {
            cout << line << endl;
            if (line == "quit") running = false;
        }
    }
    cout << "Reader completed" << endl;
}

int main()
{
    mkfifo(MyFifo, 0666);
    thread readerThread(bind(consume, MyFifo));
     
    readerThread.join();
}

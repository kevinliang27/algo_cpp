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
#include<fstream>
#include<cstring>

using namespace std;

void publish(const char* fifoName, const char* fileName) {

    ifstream ifs(fileName, ifstream::in);
    while(ifs.good() && !ifs.eof()) 
    {
        //cout << "Please input:";
        string line;
        getline(ifs, line);
        cout << "read line:"<< buf << endl;
        NamedPipe pipe(fifoName, O_WRONLY);
        write(pipe.fd(), buf, BlockSize);


        /*
        for (size_t s = 0;s<=line.size();s+=BlockSize) {
            char buf[BlockSize+1];
            memset(buf, 0, sizeof(buf));
            int len = (line.size() - s+1) < BlockSize ? line.size() -s+1 : BlockSize;
            memcpy(buf, line.c_str() + s, len);
            cout << "block size:" << len << ", read:"<< buf << endl;
            NamedPipe pipe(fifoName, O_WRONLY);
            write(pipe.fd(), buf, BlockSize);
        }
        */
        cout << "ifs.good:" << ifs.good() << ", ifs.eof:" << ifs.eof() << endl;
    }
    cout << "publisher completed" << endl;
}

int main()
{
    mkfifo(MyFifo, 0666);
    thread publishThread(bind(publish, MyFifo, "source.txt"));
     
    publishThread.join();
}

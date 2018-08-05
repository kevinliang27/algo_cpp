#include<iostream>
#include<iomanip>
#include<string>
#include<cerrno>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<Constants.h>


using namespace std;

int main()
{
    const char* myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char arr1[80];
    string  arr2;
    while(1)
    {
        cout << "Please input:";
        cin >> arr2;
        cout << "finish reading" << endl;
        //int fd = open(myfifo, O_WRONLY);
        int fd = open(myfifo, O_RDWR);
        cout << "open:" << fd << endl;
        write(fd, arr2.c_str(),  arr2.size()+1);
        cout << "write complete:" << fd << endl;
        //close(fd);
        //fd = open(myfifo, O_RDONLY);
        //fd = open(myfifo, O_RDWR);
        read(fd,arr1,sizeof(arr1));
        cout << "User2 :" << arr1 << endl;
        close(fd);
    }
    cout << "Hello world:"<< Info << endl;
}

#include <Pipe.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

NamedPipe::NamedPipe(const char* name, int flag) {
    d_fd = open(name, flag);
}

NamedPipe::~NamedPipe() {
    if (d_fd > 0) close(d_fd);
}

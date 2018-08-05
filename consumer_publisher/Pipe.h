#ifndef NAMED_PIPE
#define NAMED_PIPE
class NamedPipe {
    int d_fd = 0;
public:
    NamedPipe(const char* name, int flag);
    int fd() {return d_fd;}
    ~NamedPipe();
};
#endif


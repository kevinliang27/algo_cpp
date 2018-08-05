g++ -Wall -std=c++14 -pthread -I. -o ~/bin/reader Pipe.cpp Constants.cpp Reader.cpp 2>&1 | tee /tmp/br.out

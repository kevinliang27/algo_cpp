g++ -Wall -std=c++14 -pthread -I. -o ~/bin/publisher Pipe.cpp Constants.cpp Publisher.cpp 2>&1 | tee /tmp/bp.out

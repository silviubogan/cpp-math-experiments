#!/bin/bash
g++ main.cpp -o build/cpp-math-experiments -std=c++11
# explicit c++11 because of this warning:
# warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11 [enabled by default]
#  int type = -1; // (in a struct)

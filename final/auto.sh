#!/bin/bash
cd ../grammer
make
cd ../final
./jecc hello2.c hello2.s
gcc -o hello2 hello2.s
./hello2
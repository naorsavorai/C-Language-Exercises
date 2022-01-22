#! /usr/bin/bash

make 
chmod -r unexefile.txt
./seek.out 2 file1.txt file2.txt file3.txt unexefile.txt emptyfile.txt 
chmod +r unexefile.txt

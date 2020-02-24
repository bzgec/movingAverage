#!/bin/bash

compile=$(gcc -I./ -o example example.c movingAverage.c -g3)

if [ $? != 0 ]
then
    echo "Compiling FAILED"
    echo $compile
else
	echo "Compiling successful"
	./example
fi

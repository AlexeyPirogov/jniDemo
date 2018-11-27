#!/usr/bin/env bash

rm -r build/ dist/
mkdir -p build dist
gcc -shared -c -g -I/usr/lib/jvm/jdk-11.0.1/include -I/usr/lib/jvm/jdk-11.0.1/include/linux -fPIC -MMD -MP -MF "build/JNIDemo.o.d" -o build/JNIDemo.o src/cpp/JNIDemo.c
gcc -shared -o dist/libJNIDemo.so build/JNIDemo.o -fPIC
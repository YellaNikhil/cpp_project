#! /bin/sh

rm -rf build/;
cmake -DGLFW_BUILD_DOCS=OFF -S . -B build/
#! /bin/sh

rm -rf build/;
echo "Removed the build folder and its contents"
cmake -DGLFW_BUILD_DOCS=OFF -S . -B build/
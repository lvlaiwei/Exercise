#! /bin/sh 

lib_dir=$(find -name "lib")
for i in ${lib_dir}; do
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/$(echo ${i} | sed 's/\.\///')
done



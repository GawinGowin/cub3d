#!/bin/bash

current_dir=$(pwd)

mkdir -p lib include temp_____
cd temp_____ || exit
git clone https://github.com/42Paris/minilibx-linux.git

cd minilibx-linux || exit
make

mv *.a $current_dir/lib/
mv mlx.h $current_dir/include/

cd $current_dir || exit
rm -rf temp_____

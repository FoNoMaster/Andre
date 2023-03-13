#!/bin/bash
sort_name=$1
g++ "$sort_name"_sort.cpp -o sortal
echo sorting
./sortal
echo creating frames
python3 all_txt_to_png.py
echo creating gif
python3 png_to_gif.py
rm *txt
rm *png
echo done

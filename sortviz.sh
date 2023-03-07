#!/bin/bash
g++ bubble_sort.cpp -o bubble
echo sorting
./bubble
echo creating frames
python3 all_txt_to_png.py
echo creating gif
python3 png_to_gif.py
echo done

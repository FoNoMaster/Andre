# Andre - sorting algoritms vizualization
Andre vizualizes some of the most common sorting alghoritms by creating a gif file

It's a little project for MIPT classes so don't expect much.
Also, gifs may seem to slow for you, but you actually can't change that since .save() method has some wierd duration restrictions, so if you try to set it lower, the value will be ignored and gif would be painfully slow. Unfortunatly, there are a lot of constructions relying on specific file names (since there would be 2000+ .txt files, and even more .png files). Sorting .cpp files MUST create files named like "name" + iteration(int number) + ".txt" and "name" must be EXACTLY 11 symbols, since we have to later use the file name as a string. The .gif will have a name like "0" + "name" + ".gif". The paths to files also must be relative, since there might be some wierd errors when compiling .sh file. Also, you can only sort 100 or 256 numbers, in other cases .py files will ignore uploaded .txt files. It was done, so one column wouldn't be able to be 1.5 pixels long or something even worse than that.

In order to create a gif, run ./sortviz.sh sort_name, where sort_name might be (without ""!) "bubble"(not recommended), "bitonic"(cool one), "merge", "quick", "selection" and whatever you might want to add. Before running this command, make sure you have Pillow and numpy installed.
The whole process might take from 10 seconds to a couple minutes.

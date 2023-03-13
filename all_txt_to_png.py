from PIL import Image, ImageDraw
import glob
import numpy as np
 

files = glob.glob("*.txt")
for i in files:
    new_file = np.loadtxt(i, dtype=int)
    size = len(new_file)
    if size == 100:
        w, h = 960, 540
        img = Image.new("RGB", (w, h))
        img1 = ImageDraw.Draw(img)
        for j in range(100):
            shape = [(31+9*j, 520),(38+9*j, 520-new_file[j]*5)]
            img1.rectangle(shape, fill="#ffff33", outline="red")
        image_name = i[:-4] + ".png"
        img.save(image_name)
    elif size == 256:
        w, h = 1920, 1080
        img = Image.new("RGB", (w, h))
        img1 = ImageDraw.Draw(img)
        for j in range(256):
            shape = [(64+7*j, 1052),(69+7*j, 1052-new_file[j]*4)]
            img1.rectangle(shape, fill="#ffff33", outline="red")
        image_name = i[:-4] + ".png"
        img.save(image_name)

the_file = files[0][:-5] + "10000.txt"
test_test_file = np.loadtxt(files[0], dtype=int)
size = len(test_test_file)
test_file = [x+1 for x in range(size)]
if size == 100:
    for i in range(100):
        w, h = 960, 540
        img = Image.new("RGB", (w, h))
        img1 = ImageDraw.Draw(img)
        for j in range(100):
            shape = [(31+9*j, 520),(38+9*j, 520-test_file[j]*5)]
            if j > i:
                img1.rectangle(shape, fill="#ffff33", outline="red")
            else:
                img1.rectangle(shape, fill="red", outline="red")
        image_name = the_file[:11] + str(int(the_file[11:-4])+1+i) + ".png"
        img.save(image_name)
if size == 256:
    for i in range(256):
        w, h = 1920, 1080
        img = Image.new("RGB", (w, h))
        img1 = ImageDraw.Draw(img)
        for j in range(256):
            shape = shape = [(64+7*j, 1052),(69+7*j, 1052-test_file[j]*4)]
            if j > i:
                img1.rectangle(shape, fill="#ffff33", outline="red")
            else:
                img1.rectangle(shape, fill="red", outline="red")
        image_name = the_file[:11] + str(int(the_file[11:-4])+1+i) + ".png"
        img.save(image_name)





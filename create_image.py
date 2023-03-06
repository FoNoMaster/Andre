import random
import math
from PIL import Image, ImageDraw
import numpy as np

file_name = input()
arr = np.loadtxt(file_name, dtype=int)
# arr = [i+1 for i in range(100)]
# random.shuffle(arr)

# creating new Image object
w, h = 960, 540
img = Image.new("RGB", (w, h))

# create rectangle image   
img1 = ImageDraw.Draw(img)
for i in range(100):
    shape = [(31+9*i, 520),(38+9*i, 520-arr[i]*5)]
    img1.rectangle(shape, fill="#ffff33", outline="red")
# img.show()
image_name = file_name[:-4] + ".png"
img.save(image_name)


from PIL import Image, ImageDraw
import glob
import numpy as np
 

files = glob.glob("*.txt")
for i in files:
    new_file = np.loadtxt(i, dtype=int)
    w, h = 960, 540
    img = Image.new("RGB", (w, h))
    img1 = ImageDraw.Draw(img)
    for j in range(100):
        shape = [(31+9*j, 520),(38+9*j, 520-new_file[j]*5)]
        img1.rectangle(shape, fill="#ffff33", outline="red")
    image_name = i[:-4] + ".png"
    img.save(image_name)


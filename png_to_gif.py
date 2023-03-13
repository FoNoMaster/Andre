from PIL import Image
import glob


def sort_func(x):
    return int(x[11:-4])

# Create the frames
frames = []
imgs = glob.glob("*.png")
imgs.sort(key=sort_func)
for i in imgs:
    new_frame = Image.open(i)
    frames.append(new_frame)
 
# Save into a GIF file that loops forever
gif_name = "0" + imgs[0][:-5] + ".gif"
frames[0].save(gif_name, format='GIF',
                append_images=frames[1:],
                save_all=True,
                duration=20, loop=0)
# if you try to ser duration lower, the value might be ignored
# but i can't guarantee that 20ms is the fastest you can get

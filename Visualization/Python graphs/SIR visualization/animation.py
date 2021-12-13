import matplotlib
import matplotlib.animation as animation
import matplotlib.pyplot as plt
import numpy as np
from os import listdir
from os.path import isfile, join
import os

# changes dir
os.chdir("E:\python charts\Visualization\Python graphs\SIR visualization")

# opens csv file
file = "dataoutputanimation.csv"
data = open(file, "r", encoding='utf-8-sig').read()

# splits chunks
chunk_separator_string = '\n\n'

# adds chunk split to string
chunks = data.split(chunk_separator_string)

# remove last chunk
chunks = chunks[:-1]

# writes each chunk to gen_xx.csv file
print("Writing temp files...\n")
for idx, chunk in enumerate(chunks):
    f = open("temp/gen_" + str(idx) + ".csv", "w")
    f.write(chunk)
    f.close()

# get a list of all files in temp
temp_folder = 'temp'
file_list = [f for f in listdir(temp_folder) if isfile(join(temp_folder, f))]

# generate new list
SIR_frames = []

# read in each file from list into numpy array
for idx, file in enumerate(file_list):
    iteration = np.genfromtxt("temp\\" + file, delimiter=',')
    # append array into frames
    SIR_frames.append(iteration)

                        # Color Sequence -  Empty, Infected, Dead, Buried, Susceptible
my_cmap = matplotlib.colors.ListedColormap(["Blue", "Green", "Yellow", "Orange", "Red"])

# animate function
def animate(i):
    ax.clear()
    print("Iteration = "+str(i)+"  \r")#, end='\r')
    ax.contourf(SIR_frames[i], 100, cmap=my_cmap, vmin=0, vmax=4)
    return fig,

# generate animation and save to file
print("Generating Animation...\n")
fig, ax = plt.subplots(figsize=(8, 6))
ani = animation.FuncAnimation(fig, animate, frames=len(SIR_frames), interval=50)
# fps is frames per second of gif
ani.save('SIR_animation.gif', writer='pillow', fps=4)
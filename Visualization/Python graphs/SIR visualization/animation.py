import matplotlib
import matplotlib.animation as animation
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from os import listdir
from os.path import isfile, join
import os



os.chdir("/home/kian/Parallel Computing/Cellular Automata/EbolaCellularAutomata/CellularAutomata/Visualization/Python graphs/SIR visualization")
file = "/home/kian/Parallel Computing/Cellular Automata/EbolaCellularAutomata/CellularAutomata/dataoutputanimation.csv"
data = open(file, "r", encoding='utf-8-sig').read()

chunk_separator_string = '\n\n'
chunks = data.split(chunk_separator_string)
chunks = chunks[:-1]
for idx, chunk in enumerate(chunks):
    f = open("temp/gen_" + str(idx) + ".csv", "w")
    f.write(chunk)
    f.close()

temp_folder = '/home/kian/Parallel Computing/Cellular Automata/EbolaCellularAutomata/CellularAutomata/Visualization/Python graphs/SIR visualization/temp'
file_list = [f for f in listdir(temp_folder) if isfile(join(temp_folder, f))]
SIR_frames = []
print("Writing temp files...\n")
for idx, file in enumerate(file_list):
    iteration = np.genfromtxt("temp//" + file, delimiter=',')
    SIR_frames.append(iteration)
# print(SIR_frames)

                        # Color Sequence -  Empty, Infected, Dead, Buried, Susceptible
my_cmap = matplotlib.colors.ListedColormap(["Blue", "Green", "Yellow", "Orange", "Red"])
# add new colour

def animate(i):
    ax.clear()
    print("Iteration = "+str(i)+"  ", end='\r')
    ax.contourf(SIR_frames[i], 100, cmap=my_cmap, vmin=0, vmax=4)
    # change vmax to 5 for new var
    return fig,

print("Generating Animation...\n")
fig, ax = plt.subplots(figsize=(8, 6))
ani = animation.FuncAnimation(fig, animate, frames=len(SIR_frames), interval=50)
ani.save('SIR_animation.gif', writer='pillow', fps=2)
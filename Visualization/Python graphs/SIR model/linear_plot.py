import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# read csv
data = pd.read_csv("E:\python charts\Visualization\Python graphs\SIR model\dataoutput.csv")


data['pop'] = np.vectorize(sum, signature="(m)->()")(data[data.columns])

# creates figure obj, can change size of plot
fig = plt.figure(figsize=[15,8])
ax = fig.add_subplot(111, axisbelow=True)

# plotting the data variables
ax.plot(data.index, data.Sus, 'r', lw=2, label='Susceptible')
ax.plot(data.index, data['inf'], 'g', lw=2, label='Infected')
ax.plot(data.index, data.rem, 'b', lw=2, label='Removed')
# ax.plot(data.index, data.dead, lw=2, label='Dead & Infectious')S
# ax.plot(data.index, data['empty'], lw=2, label='Empty') // g is colour, lw = linewidth, label is in legend,

# set x label
ax.set_xlabel('Iterations', fontdict={'fontsize': 14})
ax.set_ylabel('Number', fontdict={'fontsize': 14})

# set x axis range
ax.set_xlim(0,75)
# set y axis range
ax.set_ylim(0,1000000)


ax.yaxis.set_tick_params(length=0)
ax.xaxis.set_tick_params(length=0)

# adding grid lines
ax.grid(visible=True, which='major', ls='-')

# legend label
legend = ax.legend(prop={'size': 14})

# plot title
legend.get_frame().set_alpha(0.5)

# plot title
plt.title("SIR Simulation Results", fontdict={'fontsize': 18})

# save plot to png
plt.show()
plt.savefig("SIR_graph_1.png")

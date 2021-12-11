import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv("/home/kian/Parallel Computing/Cellular Automata/EbolaCellularAutomata/CellularAutomata/dataoutput.csv")

data['pop'] = np.vectorize(sum, signature="(m)->()")(data[data.columns])

fig = plt.figure(figsize=[15,8])
ax = fig.add_subplot(111, axisbelow=True)

ax.plot(data.index, data.Sus, 'r', lw=2, label='Alive & Uninfected')
ax.plot(data.index, data['inf'], 'g', lw=2, label='Infected')
ax.plot(data.index, data.rem, 'b', lw=2, label='Dead & Buried')
ax.plot(data.index, data.dead, lw=2, label='Dead & Infectious')
# ax.plot(data.index, data['empty'], lw=2, label='Empty')

ax.set_xlabel('Iterations', fontdict={'fontsize': 14})
ax.set_ylabel('Number', fontdict={'fontsize': 14})

ax.set_xlim(0,75)
ax.set_ylim(0,1000000)

# ax.set_xlim(0,max(data.index))
ax.yaxis.set_tick_params(length=0)
ax.xaxis.set_tick_params(length=0)

ax.grid(visible=True, which='major', ls='-')
legend = ax.legend(prop={'size': 14})
legend.get_frame().set_alpha(0.5)

plt.title("SIR Simulation Results", fontdict={'fontsize': 18})

plt.show()
plt.savefig("SIR_graph_1")

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

from pprint import pprint

data = pd.read_csv("/home/kian/Parallel Computing/Cellular Automata/EbolaCellularAutomata/CellularAutomata/dataoutputanimation.csv")

data = open(file, "r", encoding='utf-8-sig').read()

# Determines columns and generates chunk seperator string, then splits into chunks
chunks = data.split('\n\n')
pprint(chunks)
import networkx as nx
import random
import matplotlib.pyplot as plt

G = nx.DiGraph()

r = lambda: (random.random() / 2) + 0.5

colors = {}
scc = {}
with open('nodes.txt') as file:
    for line in file:
        x = line.split()
        nd = x[0]
        s = x[1]
        if s not in colors.keys():
            colors[s] = (random.random(),random.random(),random.random())
        scc[nd] = s
        G.add_node(nd, color=colors[scc[nd]])

default = 'black'

nodes = G.nodes()

with open('edges.txt') as file:
    for line in file:
        x = line.split()
        nd1 = x[0]
        nd2 = x[1]
        if scc[nd1] == scc[nd2]:
            G.add_edge(nd1, nd2, color=colors[scc[nd1]])
        else:
            G.add_edge(nd1, nd2, color=default)

            
edges,color = zip(*nx.get_edge_attributes(G,'color').items())
nodes,ncolor = zip(*nx.get_node_attributes(G,'color').items())
plt.figure(figsize=(20,10))
nx.draw_networkx(G, edge_list=edges, edge_color=color, node_color=ncolor)
plt.savefig("img/graph.png") # save as png
plt.show()
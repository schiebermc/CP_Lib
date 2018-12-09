import sys
sys.setrecursionlimit(2000)
from itertools import combinations
from copy import deepcopy

class DynamicDirectedGraph():
    
    def __init__(self, n):

        # init n nodes
        self.G = {}
        for i in range(n):
            self.G[i] = set([])

        self.Gr = {}
        for i in range(n):
            self.Gr[i] = set([])
        
    def add_edge(self, node1, node2):
        self.G[node1].add(node2)
        self.Gr[node2].add(node1)

    def delete_node(self, node1):

        # delete all connections to this node
        for node2 in self.Gr[node1]:
            self.G[node2].remove(node1)
        
        # delete node from graph
        del self.G[node1]
        del self.Gr[node1]


def get_fastest_deletion(graph, steps=None):

    if(len(graph.G) == 0):
        return steps 

    if(steps == None):
        steps = []

    deletable_nodes = [val for val in graph.G if len(graph.G[val]) == 0]
    
    assert len(deletable_nodes) != 0
    if(len(deletable_nodes) == 1):
        
        steps.append((1, deletable_nodes[0]))
        new_graph = deepcopy(graph)
        graph.delete_node(deletable_nodes[0])
        return get_fastest_deletion(new_graph, steps)

    else:

        # to do this correctly, all pairs must be considered..
        best = [float('inf'), None]
        for node1, node2 in combinations(deletable_nodes, 2):
            
            tmp_steps = deepcopy(steps)
            tmp_steps.append((2, node1, node2))

            new_graph = deepcopy(graph)
            new_graph.delete_node(node1)
            new_graph.delete_node(node2)

            final_steps = get_fastest_deletion(new_graph, tmp_steps)
            best = [len(final_steps), final_steps] if len(final_steps) < best[0] else best

            print(best)
        return best[1]



if __name__ == "__main__":

    n, m = [int(val) for val in input().split()]

    g = DynamicDirectedGraph(n)

    for i in range(m):

        node1, node2 = [int(val) for val in input().split()]
        g.add_edge(node1-1, node2-1)


    print(g.G) 
    get_fastest_deletion(g)       



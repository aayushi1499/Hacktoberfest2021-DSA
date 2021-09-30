# filename : Graph.py 

# ------------------------------------------------------------------------------------  

class Graph: 

    def __init__(self, number_of_vertex, number_of_edges, is_directed = False, is_weighted = False):
        self.number_of_vertices = number_of_vertex 
        self.number_of_edges = number_of_edges 
        self.is_directed = is_directed 
        self.is_weighted = is_weighted 
        self.graph_list = [[] for i in range(self.number_of_vertices)]
        self.initGraph() # initlize the Graph. 


    def initGraph(self): 
        for egde in range(self.number_of_edges): 
            edge_data = list(map(input("").split(" "), int()))
            if not self.is_weighted: 
                start = edge_data[0]
                end = edge_data[1]
                self.graph_list[start-1].append(end - 1) 
            else: 
                # TODO : Work on Weighted Graph or make a seprate class for it, with different initGraph method. 
                pass 


# ------------------------------------------------------------------------------------------- 

class GraphNode: 

    def __init__(self): 
        self.start = None 
        self.end = None 
        self.weight = None 
    
    
        

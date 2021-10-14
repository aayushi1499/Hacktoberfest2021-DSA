package daa.assignment;

import java.util.*;   

class KruskalAlgorithm {
    
    int vertices, edges;
    Edge[] edgeArr;
    
    class Edge implements Comparable<Edge> {  
        int source, destination, weight;  
  
        @Override
        public int compareTo(Edge edgeToCompare) {  
            return this.weight - edgeToCompare.weight;  
        }  
    };  
  
    class Subset {  
        int parent, value;  
    };  
   
    KruskalAlgorithm(int vertices, int edges) {  
        this.vertices = vertices;  
        this.edges = edges;  
        edgeArr = new Edge[this.edges];  
        for (int i = 0; i < edges; ++i)  
            edgeArr[i] = new Edge();
    }  
      
    public void applyKruskal() {   
        Edge finalResult[] = new Edge[vertices];  
        int newEdge = 0;
        int index;
        
        for (index = 0; index < vertices; ++index) {
            finalResult[index] = new Edge();
        }

        Arrays.sort(edgeArr);  
        
        Subset subsetArray[] = new Subset[vertices];  
          
        //Allocate memory to create vertices subsets
        for (index = 0; index < vertices; ++index) {
            subsetArray[index] = new Subset();
        }
 
        for (int vertex = 0; vertex < vertices; ++vertex) {  
            subsetArray[vertex].parent = vertex;  
            subsetArray[vertex].value = 0;  
        }
        
        index = 0;  
          
        //Pick the smallest edge from the edges and increment the index for next iteration  
        while (newEdge < vertices - 1) {
            // create an instance of Edge for next edge  
            Edge nextEdge = new Edge();
            nextEdge = edgeArr[index++];  
              
            int nextSource = findSetOfElement(subsetArray, nextEdge.source);  
            int nextDestination = findSetOfElement(subsetArray, nextEdge.destination);  
              
            //if the edge doesn't create cycle after including it, we add it in the result and increment the index  
            if (nextSource != nextDestination) {  
                finalResult[newEdge++] = nextEdge;  
                performUnion(subsetArray, nextSource, nextDestination);  
            }  
        }
        
        for (index = 0; index < newEdge; ++index) {
            System.out.println(finalResult[index].source + " - " + finalResult[index].destination + ": " + finalResult[index].weight);  
        }
    }  
      
    //Get set of an element  
    public int findSetOfElement(Subset subsetArray[], int i) {
        if (subsetArray[i].parent != i) {
            subsetArray[i].parent = findSetOfElement(subsetArray, subsetArray[i].parent);
        }
        
        return subsetArray[i].parent;  
    }  
      
    //Perform union of two sets  
    public void performUnion(Subset subsetArray[], int sourceRoot, int destinationRoot) {  
        int nextSourceRoot = findSetOfElement(subsetArray, sourceRoot);  
        int nextDestinationRoot = findSetOfElement(subsetArray, destinationRoot);  
  
        if (subsetArray[nextSourceRoot].value < subsetArray[nextDestinationRoot].value) { 
            subsetArray[nextSourceRoot].parent = nextDestinationRoot;
            
        }else if (subsetArray[nextSourceRoot].value > subsetArray[nextDestinationRoot].value) {
            subsetArray[nextDestinationRoot].parent = nextSourceRoot;
            
        }else {  
            subsetArray[nextDestinationRoot].parent = nextSourceRoot;  
            subsetArray[nextSourceRoot].value++;  
        }  
    }  
   
    public static void main(String[] args) {  
        int vertices, edges;  

        Scanner sc = new Scanner(System.in);  
        System.out.println("Enter number of vertices: ");  
        vertices = sc.nextInt();  
 
        System.out.println("Enter number of edges: ");    
        edges = sc.nextInt();  
          
        KruskalAlgorithm graph = new KruskalAlgorithm(vertices, edges);
          
        for(int i = 0; i < edges; i++){ 
            System.out.println("Enter source value for edge["+ i +"]: ");  
            graph.edgeArr[i].source = sc.nextInt();  
              
            System.out.println("Enter destination value for edge["+ i +"]: ");  
            graph.edgeArr[i].destination = sc.nextInt();  
              
            System.out.println("Enter weight for edge["+i+"]: ");  
            graph.edgeArr[i].weight = sc.nextInt();  
        }  

        graph.applyKruskal();
        
    }  

}
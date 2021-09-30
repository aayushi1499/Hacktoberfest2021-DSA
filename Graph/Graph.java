// ------------------------------------------------------------------------- 

import java.util.ArrayList; 
import java.util.Scanner; 

public class Graph {

    
    private ArrayList<ArrayList<Integer>> graph; 
    private int number_of_vertex; 
    private int number_of_edge; 
    private boolean isDirected; 


    public Graph(int vertex, int edges, boolean isDirected) {
        this.number_of_vertex = vertex; 
        this.number_of_edge= edges; 
        this.isDirected = isDirected; 
        this.graph = new ArrayList<ArrayList<Integer>>(); 

        for(int i = 0; i < this.number_of_vertex; i++) {
            this.graph.add(new ArrayList<Integer>()); 
        }
        System.out.println("-----");
        Scanner graphInput = new Scanner(System.in); 
        for(int i = 0;i < this.number_of_edge; i++) {
            int source = -1, end = -1; 
            source = graphInput.nextInt(); 
            end = graphInput.nextInt(); 
            graph.get(source - 1).add(end - 1); 
            if(!isDirected) {
                graph.get(end - 1).add(source - 1); 
            }
        }
        graphInput.close(); 
    }


    // -------------------------- print Graph data. 
    public void printGraph() {
        for(int i  = 0; i < this.number_of_vertex; i++) {
            for(int vertex : this.graph.get(i)) {
                System.out.print(vertex + 1 + ", "); 
            }
            System.out.println(); 
        }
    }

}





 

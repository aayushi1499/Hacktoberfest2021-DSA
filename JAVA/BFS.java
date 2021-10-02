/**
Breadth First Search
**/
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class BFS {
    private int vertices;
    private LinkedList[] adjacentMatrix;

   public BFS(int vertices) {
        this.vertices = vertices;
        adjacentMatrix = new LinkedList[vertices];
        for (int i = 0; i < vertices; i++) {
            adjacentMatrix[i] = new LinkedList<>();
        }
    }

    public void addEdges(int u,int v){
       adjacentMatrix[u].add(v);
    }

    public void breadthFirstSearch(int searchVertex){
       boolean[] isVisited=new boolean[vertices];
       LinkedList<Integer> queue=new LinkedList<>();
        List<Integer> getBFS=new ArrayList<>();
       isVisited[searchVertex]=true;
       queue.add(searchVertex);
       while (!queue.isEmpty()){
           searchVertex=queue.poll();
           getBFS.add(searchVertex);
        for (int newVertex : (Iterable<Integer>) adjacentMatrix[searchVertex]) {
            if (!isVisited[newVertex]) {
                isVisited[newVertex] = true;
                queue.add(newVertex);
            }
        }}
       for (int i=0;i<getBFS.size()-1;i++){
           System.out.print(getBFS.get(i)+"-->");
       }
        System.out.println(getBFS.get(getBFS.size()-1));
    }

    public static void main(String[] args) {
      //5 vertex
        BFS bfs=new BFS(5);
      //connect the nodes
        bfs.addEdges(0, 1);
        bfs.addEdges(0, 2);
        bfs.addEdges(1, 2);
        bfs.addEdges(2, 0);
        bfs.addEdges(2, 3);
        bfs.addEdges(3, 3);
      //start point
        bfs.breadthFirstSearch(2);
      
    }
}

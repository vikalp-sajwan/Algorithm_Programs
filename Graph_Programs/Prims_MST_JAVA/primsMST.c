import java.util.*;

class GraphNode{
	int weight;
	int neighbour;
	GraphNode next;
	
	GraphNode(int weight, int neighbour){
		this.weight = weight;
		this.neighbour = neighbour;
		this.next = null;
	}
}

class Graph{
	ArrayList<GraphNode> al;
	GraphNode temp;
	
	boolean visited[];
	
	Graph(int size){
		al = new ArrayList<GraphNode>(Collections.nCopies(size, null));
		visited = new boolean[size];
	}
	
	void insert(int x, int y, int weight){
		temp = al.get(x-1);
		if(temp == null){
			al.set(x-1, new GraphNode(weight, y-1));
			return;
		}
		while(temp.next!=null){
			temp=temp.next;
		}
		temp.next = new GraphNode(weight, y-1);
		
		
	}
	
	long getPrimsSum(int start){
		long sum = 0;
		int visitedCount = al.size();
		
		visited[start-1] = true;
        visitedCount--;
		
        while(visitedCount>0){
        	sum += getClosest();
        	
        	visitedCount--;
        }
        
        return sum;
	}
	
	int getClosest(){
		// greater than the possible max dist
		int min = 1000000;
		int closestVertex = 0;

		for(int i=0; i<al.size(); i++){
			if(visited[i] == false)
				continue;
			temp = al.get(i);
			while(temp!=null){
				if(visited[temp.neighbour]==false && temp.weight<min){
					min = temp.weight;
					closestVertex = temp.neighbour;
				}
				temp = temp.next;
			}
		}
		visited[closestVertex] = true;
		return min;
		
	}
}

public class Solution {

    public static void main(String[] args) {
        @SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        Graph graph = new Graph(n);
       
        long primsSum = 0;
        int x, y, w, start;
        while(m>0){
            x = sc.nextInt();
            y = sc.nextInt();
            w = sc.nextInt();
            
            graph.insert(x, y, w);
            graph.insert(y, x, w);
                      
            m--;
        }
        start = sc.nextInt();
        
        primsSum = graph.getPrimsSum(start);
        System.out.println(primsSum);

        
    }
}

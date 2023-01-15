/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Question 01 : Constructing a directed graph
 
*/

#include<stdio.h>
#include <stdlib.h>

// Defining stack array for performing DFS


struct node
{
	int vertex;
	struct node* next;

};

struct Graph
{
	int numVertices;
	struct node** adjLists;

	int * visited;

};

struct node* createNode(int n)
{
	struct node* Node= malloc(sizeof(struct node));

	Node->vertex=n;
	Node->next=NULL;

	return Node;
}

// Creating a graph *Undirected* when the number of vertices is given :

struct Graph* createGraph(int total_vertices)
{

  // First Allocating space for a graph and adding the info of toal vertices

  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = total_vertices;

  // Adding space for the adjLists and the visited list

  graph->adjLists = malloc(total_vertices * sizeof(struct node*));
  graph->visited = malloc(total_vertices * sizeof(int));

  int i;

  // Initiating them to NULL

  for (i = 0; i < total_vertices; i++)
  {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;

}


// Creating a function which will add the edges to the graph

void addEdge(struct Graph* graph, int src, int dest)
{
  // Add edge from src to dest

  struct node* newNode = createNode(dest);

  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;

}

void addDirectionalEdge(struct Graph* graph, int src, int dest)
{
	struct node* newNode;

  // Add edge from dest to src

  newNode = createNode(src);

  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;

}

void DFS(struct Graph* graph, int sink)
{
   // No time 
}


int main()
{
	// Hardcoding the graph with size 6 as Directed in the question

	struct Graph* graph;
	graph = createGraph(6);

	// Adding the edges to the vertices

	addEdge(graph,1,2);
	addEdge(graph,2,3);
	addEdge(graph,3,4);
	addEdge(graph,6,3);
	addEdge(graph,1,6);
	addEdge(graph,6,5);
	addEdge(graph,5,3);


	// Now assuming the sink to be vertex 1, Cpnstructing a new directed graph from all the vertx to sink

	// Let the new directed graph be graph_modified

	// Initializing the new graph :

	struct Graph* graph_modified;
	graph_modified = createGraph(6);


	/* Logic : We Will transverse through the original graph using dfs starting from 1 which is the sink and whenever we reach the end
				and have to perform a pop, we will consider the stack before the pop and then store every pair of edges starting from the 
				bottom of the stack ( which will be the sink ) and create the edges in the graph_modified graph and then repeat the process every time
				we have to make the pop we will get all the  paths to the sink															*/

	/* Easier way to do it with a larger time complexity : 
				Once we create the AdjList of the graph, consider the AdjList of the sink node ( In this case 1 ) and jsut transverse
				through it and every time u find a node other than the isnk node make a directed connection between them so that all the elements
				finally have a connection with the sink element 																			*/

	// Did not get time to implement even the second logic properly 


	return 0;


}

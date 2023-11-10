/* Name: Bannuru Rohit Kumar Reddy
   Roll: 21CS30011
   Machine: 41
   Department: Computer Science and Engineering

   Question 02 : Choosing flowers such that gardens connected by path have different flowers
 
*/


#include<stdio.h>
#include<stdlib.h>

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
	int * color;

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
  graph->color = malloc(total_vertices * sizeof(int));

  int i;

  // Initiating them to NULL

  // ** Initializing the node index to 0 and the color index to 4 (4 so that we get the exact answer as the one in the question) as indicated in the question ** 

  for (i = 0; i < total_vertices; i++)
  {
    graph->adjLists[i] = NULL;

    graph->visited[i] = 0;
    graph->color[i] = 1;
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

// Function to find a different collor when an array of 3 colors is given

int Assign_color(int color_neighbour[])
{
	int i,j,temp,total;

	if(color_neighbour[1]<color_neighbour[2])
	{
		temp=color_neighbour[2];
		color_neighbour[2]=color_neighbour[1];
		color_neighbour[1]=temp;
	}

	if(color_neighbour[1]<color_neighbour[3])
	{
		temp=color_neighbour[3];
		color_neighbour[3]=color_neighbour[1];
		color_neighbour[1]=temp;
	}

	if(color_neighbour[2]<color_neighbour[3])
	{
		temp=color_neighbour[3];
		color_neighbour[3]=color_neighbour[2];
		color_neighbour[2]=temp;
	}

	return color_neighbour[1]+1;

}

// Using modified BFS to transverse the graph and assign color to each node : 

void bfs_Modified(struct Graph* graph, int Initialvertex)
{

	int i;
	int color_neighbour[3];    // This array is used to store the colors of the neighbouring gardens
	for(i=1;i<4;i++) color_neighbour[i]=0;     // Initializing it to 0


  graph->visited[Initialvertex] = 1;


  int x=1;  // For finding the number of neighbours

    struct node* temp = graph->adjLists[Initialvertex];

    while (temp)
    {
      int adjVertex = temp->vertex;

        color_neighbour[x] = graph->color[adjVertex];
        x++;

      temp = temp->next;

    }

    // printf("vnkrndvrne\n");


  	// Once we find all the colors of the neighbors we need to assign a color which is different from all of them to the current node

    graph->color[Initialvertex] = Assign_color(color_neighbour);
}

int main()
{
	int n,N;

	printf("Enter the value of n: ");
	scanf("%d",&n);

	// Creating a graph with n vertices to represent the garden :

	struct Graph* graph;
	graph=createGraph(n);

	printf("Enter the number of bidrectional paths which are to be taken as input: ");
	scanf("%d",&N);

	printf("Enter pairs of %d bidrectional paths \n",N);

	int i,temp1,temp2;

	for(i=0;i<N;i++)
	{
		scanf("%d",&temp1);
		scanf("%d",&temp2);

		// Adding a edge between the 2 vertices 

		addEdge(graph,temp1,temp2);

	}

	// Now using the modified BFS search algorithm which will only transverse till the next neighbours to transverse through the garden and assign colors to the gardens :

	// Here we have to apply the modified bfs search to all the nodes starting from 1 and we are only allowed to change the color of the previous elements

		for(i=1;i<n;i++)
		{
			bfs_Modified(graph,i);
		}

	// Printing the colors of the gardens :

	printf("[");
	for(i=0;i<n;i++)
	{
		printf("%d,",graph->color[i]);
	}
	printf("\b]");


	return 0;


}
// C program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

// Number of vertices in the graph
#define V 9

// A utility function to find the vertex with minimum
// distance value, from the set of vertices not yet included
// in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[])
{
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t\t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the
				// shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest distance from src to i is
	// finalized

	// Initialize all distances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist);
}

// driver's code
int main()
{
	/* Let us create the example graph discussed above */
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

	// Function call
	dijkstra(graph, 0);

	return 0;
}


//bfs
typedef struct q{
    int size;
    int f;
    int r;
    int *a;
}que;


que* initialize(int n){
    que* q=(que*)malloc(sizeof(que));
    q->size=n;
    q->f=q->r=-1;
   q->a=(int*)malloc(n*sizeof(int));
    return q;

}

void enque(que* q,int n){
    if(q->r==(q->size-1)) {printf("queue full"); return;}
    q->a[++(q->r)]=n;
}

int deque(que* q){
    if(q->f==q->r) {printf("queue empty"); return 0;}
    q->f++;
    return q->a[q->f];
}

int main()
{
    que* q=initialize(50);
    int n=5;
    int j;
    int v[5]={0,0,0,0,0};
    int a[5][5]={
    {0,1,0,1,0},
    {1,0,0,1,0},
    {0,0,0,1,1},
    {1,1,1,0,0},
    {0,0,1,0,0},
};
    int arr[900];
    int i=2;
    arr[0]=i;
    int k=1;
    enque(q,i);
    v[i]=1;
        while(q->f!=q->r){
                i=deque(q);
            for(j=0;j<n;j++){
                if(a[i][j]!=0 && v[j]==0){
                    enque(q,j);
                    v[j]=1;
                    arr[k]=j;k++;

                }
                
            }

        }

        for(i=0;i<n;i++) printf("%d-> ",arr[i]);
        return 0;
}



//DFS

int g[8][8]={
    {0,1,0,0,1,0,0,0},
    {0,0,1,0,1,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,1,0,0,1,0,0,0},
    {0,0,0,1,0,0,0,0},
    {1,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,0,1},
    {0,0,0,0,0,1,1,0}
};
int visited[10]={0,0,0,0,0,0,0,0,0,0};

typedef struct{
    int n;
    struct node *next;
}node;


void explore(int g[][8])
{

}

void DFS(int i)
{
    printf("%d  ",i);
    visited[i]=1;
    for(int j=0;j<8;j++)
    {
        if(g[i][j] && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        if(!visited[i])
        DFS(i);
    }
}

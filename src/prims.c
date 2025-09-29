#include<stdio.h>
#include<stdbool.h>
#include<limits.h>



int findMinVertex(int weights[], bool visited[], int n) {
	int i;
	int minVertex = -1; 
	for (i = 0; i <n; i++) {
		if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex])) 
		{
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(int v, int edges[v][v]) {
	int parent[v];
	int weight[v];
	bool visited[v];
	int i;
	int j;
	parent[0] = -1;
	weight[0] = 0;
	for(i = 1; i <v; i++) {
		visited[i] = false;
		weight[i] = INT_MAX;
	}
	for (i = 0; i < v; i++) 
	{
		int minVertex = findMinVertex(weight, visited, v);
		visited[minVertex] = true;
		for (j = 0; j < v; j++) 
		{
			if(edges[minVertex][j] != 0 && !visited[j]) 
			{
				if(edges[minVertex][j] < weight[j]) 
				{
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}
	int minCost=0;
	int k = 1;
	for (i = 1; i < v; i++) 
	{
		minCost = minCost + weight[i];
		if (parent[i] < i) 
		{
			printf("Edge %d:(%d %d) Cost:%d\n", k, parent[i], i, weight[i]);
		}
		else 
		{
			printf("Edge %d:(%d %d) Cost:%d\n", k, i, parent[i], weight[i]);
		}
		k++;
	}
	printf("\nMinimum cost is:%d", minCost);
}

int main() 
{ 
	int e, i, v, j;
	printf("Enter the no of Vertices:");
    scanf("%d",&v);   
	printf("Enter the no of Edges:");
    scanf("%d",&e); 
	int edges[v][v]; 
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			edges[i][j]=0;
		}
	}
	for (i = 0; i < e; i++) 
	{ 
		int v1; 
		int v2;
		printf("Enter the value of v1 for Edge %d:", i+1);
    	scanf("%d",&v1);
    	printf("Enter the value of v2 for Edge %d:", i+1);
    	scanf("%d",&v2);
		int weight;
		printf("Enter Cost of Edge (%d, %d):", v1, v2);
		scanf("%d",&weight);
		edges[v1][v2] = weight; 
		edges[v2][v1] = weight;
		printf("\n"); 
	}
	prims(v, edges);
	return 0;
}


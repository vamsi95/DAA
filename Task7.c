.	#include <stdio.h>
2.	#include <limits.h>
3.	 
4.	#define V 5
5.	 
6.	int minKey(int key[], int mstSet[]) {
7.	    int min = INT_MAX, min_index;
8.	    int v;
9.	    for (v = 0; v < V; v++)
10.	        if (mstSet[v] == 0 && key[v] < min)
11.	            min = key[v], min_index = v;
12.	 
13.	    return min_index;
14.	}
15.	 
16.	int printMST(int parent[], int n, int graph[V][V]) {
17.	    int i;
18.	    printf("Edge   Weight\n");
19.	    for (i = 1; i < V; i++)
20.	        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
21.	}
22.	 
23.	void primMST(int graph[V][V]) {
24.	    int parent[V]; // Array to store constructed MST
25.	    int key[V], i, v, count; // Key values used to pick minimum weight edge in cut
26.	    int mstSet[V]; // To represent set of vertices not yet included in MST
27.	 
28.	    // Initialize all keys as INFINITE
29.	    for (i = 0; i < V; i++)
30.	        key[i] = INT_MAX, mstSet[i] = 0;
31.	 
32.	    // Always include first 1st vertex in MST.
33.	    key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
34.	    parent[0] = -1; // First node is always root of MST
35.	 
36.	    // The MST will have V vertices
37.	    for (count = 0; count < V - 1; count++) {
38.	        int u = minKey(key, mstSet);
39.	        mstSet[u] = 1;
40.	 
41.	        for (v = 0; v < V; v++)
42.	 
43.	            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
44.	                parent[v] = u, key[v] = graph[u][v];
45.	    }
46.	 
47.	    // print the constructed MST
48.	    printMST(parent, V, graph);
49.	}
50.	 
51.	int main() {
52.	    /* Let us create the following graph
53.	     2    3
54.	    (0)--(1)--(2)
55.	     |   / \   |
56.	    6| 8/   \5 |7
57.	     | /     \ |
58.	    (3)-------(4)
59.	     9          */
60.	    int graph[V][V] = { { 0, 2, 0, 6, 0 }, { 2, 0, 3, 8, 5 },
61.	            { 0, 3, 0, 0, 7 }, { 6, 8, 0, 0, 9 }, { 0, 5, 7, 9, 0 }, };
62.	 
63.	    primMST(graph);
64.	 
65.	    return 0;
66.	}

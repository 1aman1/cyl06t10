__graphs__

* prioritizing adjacency list over adjacency matrix for implementations.

* including sample graph datasets for list & matrix both.

__Relationship between number of edges and vertices__

* G(V,E) 
directed => E = V×(V-1)
undirected => E = V×(V-1)/2
connected => E = V-1
complete => E = V×(V-1)/2

__tips__

* visited lookup is not required for a Directed Acyclic Graph.

* Although for cyclic graphs, it becomes necessary to use the visited lookup while traversing graph.

* for finding nodes or gathering shortest distances, it is beneficial to use BFS over DFS.

* find more test graphs to evaluate algorithms present in sample file 'Z-sample-input-sets'
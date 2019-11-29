A graph structure depicting transfers of funds between different bank accounts. 
The graph provides a mechanism that can help monitor cash flow, clarify poly / triangular transfers, and understand customer group formation.

Characteristics of Graphs in Brief: The basic components of the structure are:
1. Nodes have specific names (eg alphanumeric strings that represent usernames or account numbers).
2. Edges / vertices have a specific direction and 'weight' known.
3. There may be multiple edges with the same direction between two nodes which may have the same numerical weight. Each of these edges represents a deal.
4. One node can be connected to one or many others. How big this crowd can be is not known and can naturally increase / decrease dynamically.
5. New edges can be inserted at any time.
6. There is generally no limit to the number of vertices and edges.
7. Figure 1 shows a representative state of the structure. In this figure there is a transfer of 1,340 monetary units from the kji account to the kfc.
8. The number of expected insertions / increments (and / or deletions) of vertices and edges in the structure is not known from the outset.
9. The graph must be strongly connected.


![](Screenshot_4.png)

Program Interface Description: After the program is called, the user can interact with a prompt through which the following commands can be called:
1. i (nsert) Ni introduced a new node Ni. 
2. (i) n (sert) Ni Nj weight introduced an edge between Ni and Nj with weight weight. The nodes Ni and Nj may appear for the first time in the structure. 
3. d (elete) Ni deleted from the graph the node node as well as all incoming / outgoing edges (and weights).
4. (de) l (ete) Ni Nj weight erased the edge between Ni and Nj by weight. If there are multiple edges with the same weight, delete one of the existing ones. If no weight is specified, all existing edges between Ni and Nj are deleted.
5. m (odify) Ni Nj weight nweight changed the weight weight to the new nweight value. If there are multiple edges with the same weight value convert the first one you will find. 
6. r (eceiving) Ni presented all the transactions that the node Ni receives as an input. 
7. c (irclefind) Ni finds out if the node Ni is involved in simple cycles and presents them. 
8. f (indcircles) Ni k finds if the node Ni is involved in circular dealings with others. However, the minimum amount that each acne should have is k units (minimum weight).
9. t (raceflow) Ni Nj l Finds potential diffusions starting at the node Ni and ending at the Nj node. L gives the maximum length of the path to the number of edges to be traversed. 
10. e (xit) the program simply terminates after first assembling all the space it has occupied in memory.
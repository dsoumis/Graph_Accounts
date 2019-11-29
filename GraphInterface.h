#ifndef GRAPHINTERFACE_H
#define GRAPHINTERFACE_H
    #include "Graph.h"
    struct node_of_graph* create_graph();
    void addEdge(struct node_of_graph **, char* , char* ,  int );
    void print(struct node_of_graph **);
    void graph_insert_last(struct node_of_graph **, BANK_ACC );
    void delete_node(struct node_of_graph **, BANK_ACC );
    void delete_weight(struct node_of_graph **, BANK_ACC , BANK_ACC , int );
    void modify_weight(struct node_of_graph **, BANK_ACC , BANK_ACC , int, int );
    void receiving(struct node_of_graph **, BANK_ACC );
    void simplecirclefind(struct node_of_graph **, BANK_ACC );
    void circlefind(struct node_of_graph **, BANK_ACC,int );
    void traceflow(struct node_of_graph **,BANK_ACC,BANK_ACC,int);
    void end_of_graph(struct node_of_graph **);
#endif

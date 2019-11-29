#ifndef Graph_H
#define Graph_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //to use booleans
#include "StackInterface.h" //to use a data structure of a stack
typedef char* BANK_ACC;
typedef struct adjacency_list_node{ //Struct for node in adjacency lists
    BANK_ACC destination;
    int weight;
    bool visited;
    struct adjacency_list_node *next_node;
}adjNode;

struct node_of_graph {
    BANK_ACC bank_account;
    adjNode *current_head; //Current head of adjacency list of bank_account
    //In circlefind we use only values 0(not visited) and 1(visited) to find simple cycles.
    // In findcircles we use 0(not visited),
    // 1(visited but not parsed all the nodes that is connected with),
    // 2(completely visited)
    short int  visited;
    struct node_of_graph *next;
};
#endif

#include "Graph.h"
adjNode *new_adjNode(char* destination, int weight){
    adjNode *newNode=(adjNode*)malloc(sizeof(adjNode));
    newNode->destination=malloc(strlen(destination)+1);
    strcpy(newNode->destination,destination);
    newNode->weight=weight;
    newNode->next_node=NULL;
    return newNode;
}
struct node_of_graph* create_graph(){
    struct node_of_graph* graph_head=NULL;
    return graph_head;
};

void graph_insert_last(struct node_of_graph **graph_head, BANK_ACC bank_account) {
    // Create a temp pointer
    struct node_of_graph *tmp;
    tmp=*graph_head;
    if ( tmp != NULL ) {
        // Nodes already present in the graph
        // Parse to end of list
        while (tmp->next!= NULL ) {
            if(strcmp(tmp->bank_account,bank_account)==0) {
                printf("Node |%s| Exists\n", bank_account);
                return;
            }
            tmp = tmp->next;
        }
        struct node_of_graph *newNode=(struct node_of_graph *)malloc(sizeof(struct node_of_graph)); //Create a new node
        newNode->bank_account=malloc(strlen(bank_account)+1);
        strcpy(newNode->bank_account,bank_account);
        newNode->current_head=NULL;
        newNode->next=NULL;
        // Point the last node to the new node
        tmp->next=newNode;
    }
    else {
        // First node in the list
        struct node_of_graph *newNode=(struct node_of_graph *)malloc(sizeof(struct node_of_graph));
        newNode->bank_account=malloc(strlen(bank_account)+1);
        strcpy(newNode->bank_account,bank_account);
        newNode->current_head=NULL;
        newNode->next=NULL;
        *graph_head = newNode;
    }
    printf("Inserted |%s|\n",bank_account);
}


void addEdge(struct node_of_graph **graph_head, BANK_ACC source_bank_account, BANK_ACC destination_bank_account, int money) {
    struct node_of_graph *tmp_source_graph,*tmp_destination_graph;
    while(1) {
        tmp_source_graph=*graph_head;
        tmp_destination_graph=*graph_head;
        while (tmp_source_graph != NULL) {
            if (strcmp(tmp_source_graph->bank_account,source_bank_account)==0) {
                bool exists = false;
                while (tmp_destination_graph != NULL) {
                    if (strcmp(tmp_destination_graph->bank_account,destination_bank_account)==0) { //Search if the destination bank account exists in the graph
                        exists = true;
                        break;
                    }
                    tmp_destination_graph = tmp_destination_graph->next;
                }
                if (exists == false) {
                    graph_insert_last(graph_head, destination_bank_account); //If destination bank account doesn't exist add it to the graph
                }

                adjNode *newNode = new_adjNode(destination_bank_account, money);
                newNode->next_node = tmp_source_graph->current_head;       //and then add it to the adjacency list of source bank account
                tmp_source_graph->current_head = newNode;
                printf("Inserted |%s| ->%d->|%s|\n",source_bank_account,money,destination_bank_account);
                return;
            }
            tmp_source_graph = tmp_source_graph->next;
        }
        graph_insert_last(graph_head, source_bank_account); //If source bank account doesn't exist add it to the graph
    }
}


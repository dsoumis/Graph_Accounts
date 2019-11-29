#include "Graph.h"
void print(struct node_of_graph **graph_head){
    struct node_of_graph *tmp_source_graph;
    tmp_source_graph=*graph_head;
    while (tmp_source_graph!= NULL) {
        printf("|%s|\n", tmp_source_graph->bank_account);
        adjNode *temp=tmp_source_graph->current_head;
        while (temp!=NULL){
            printf("- %d->|%s|\n",temp->weight,temp->destination);
            temp=temp->next_node;
        }
        tmp_source_graph= tmp_source_graph->next;
        printf("\n");
    }
}


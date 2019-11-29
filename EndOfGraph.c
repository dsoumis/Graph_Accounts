#include "Graph.h"
void end_of_graph(struct node_of_graph **graph_head){
    printf("exit program\n");
    struct node_of_graph *tmp_source_graph;
    tmp_source_graph=*graph_head;
    adjNode *position_in_adjlist;
    while (tmp_source_graph != NULL){
        position_in_adjlist=tmp_source_graph->current_head;
        while (position_in_adjlist!=NULL){
            tmp_source_graph->current_head = tmp_source_graph->current_head->next_node; //Move the head to the next node so the list begins from next node
            free(position_in_adjlist);
            position_in_adjlist=tmp_source_graph->current_head;
        }
        (*graph_head)=(*graph_head)->next;
        free(tmp_source_graph);
        tmp_source_graph=*graph_head;
    }
}

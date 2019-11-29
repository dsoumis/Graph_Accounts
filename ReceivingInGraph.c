#include "Graph.h"
void receiving(struct node_of_graph **graph_head, BANK_ACC node){
    struct node_of_graph *tmp_source_graph;
    adjNode *position_in_adjlist;
    tmp_source_graph=*graph_head;
    bool no_receiving_edges=true;
    bool node_exists=false;
    bool dummy=false;
    while (tmp_source_graph != NULL){
        if(strcmp(tmp_source_graph->bank_account,node)==0)
            node_exists=true;
        position_in_adjlist=tmp_source_graph->current_head;
        while (position_in_adjlist!=NULL){
            if(strcmp(position_in_adjlist->destination,node)==0) {
                if(!dummy) {
                    printf("Rec-edges |%s|->%d->|%s|\n", tmp_source_graph->bank_account, position_in_adjlist->weight,
                           position_in_adjlist->destination);
                    dummy = true;
                }else
                    printf("|%s|->%d->|%s|\n", tmp_source_graph->bank_account, position_in_adjlist->weight, position_in_adjlist->destination);
                no_receiving_edges = false;
            }
            position_in_adjlist=position_in_adjlist->next_node;
        }
        tmp_source_graph = tmp_source_graph->next;
    }
    if(!node_exists)
        printf("|%s| does not exist - abort-r\n",node);
    else{
        if(no_receiving_edges)
            printf("No-rec-edges |%s|\n",node);
    }
}


#include "Graph.h"
void delete_node(struct node_of_graph **graph_head,BANK_ACC node){
    struct node_of_graph *tmp_source_graph,*prev;
    bool node_exists=false;
    prev=NULL;
    tmp_source_graph=*graph_head;
    adjNode *position_in_adjlist;
    adjNode *previous=NULL;
    bool first_node;
    while (tmp_source_graph != NULL){
        position_in_adjlist=tmp_source_graph->current_head;
        first_node=true;
        while (position_in_adjlist!=NULL){
            if(strcmp(position_in_adjlist->destination,node)==0) {
                if (first_node) {                                                                //If the node is the first in the adjacency list
                    tmp_source_graph->current_head = tmp_source_graph->current_head->next_node; //Move the head to the next node so the list begins from next node
                    free(position_in_adjlist->destination);
                    free(position_in_adjlist);
                    position_in_adjlist=tmp_source_graph->current_head;
                } else {
                    previous->next_node = position_in_adjlist->next_node; //Connect the previous node with the next node of the one we want to delete
                    free(position_in_adjlist->destination);
                    free(position_in_adjlist);
                    position_in_adjlist=previous->next_node;
                }
                continue; //Continue is being used because previous and position_in_adjlist as well as first_node values should not be changed
            }
            previous=position_in_adjlist;
            position_in_adjlist=position_in_adjlist->next_node;
            first_node=false;
        }
        if(strcmp(tmp_source_graph->bank_account,node)==0){
            node_exists=true;
            position_in_adjlist=tmp_source_graph->current_head;
            while (position_in_adjlist!=NULL){
                tmp_source_graph->current_head = tmp_source_graph->current_head->next_node; //Move the head to the next node so the list begins from next node
                free(position_in_adjlist->destination);
                free(position_in_adjlist);
                position_in_adjlist=tmp_source_graph->current_head;
            }
            prev->next=tmp_source_graph->next;
            printf("- Deleted |%s|\n",tmp_source_graph->bank_account);
            free(tmp_source_graph->bank_account);
            free(tmp_source_graph);
            tmp_source_graph=prev->next;
            continue; //Continue is used because tmp_source_graph should not be changed as it already has the updated value
        }
        prev=tmp_source_graph;
        tmp_source_graph = tmp_source_graph->next;
    }
    if(node_exists==false)
        printf("Node |%s| does not exist - abort-d;\n",node);
}
void delete_weight(struct node_of_graph **graph_head, BANK_ACC source_bank_account, BANK_ACC destination_bank_account, int money){
    struct node_of_graph *tmp_source_graph;
    bool destination_exists=false;
    bool weight_exists=false;
    tmp_source_graph=*graph_head;
    while (tmp_source_graph!=NULL) {
        if(strcmp(tmp_source_graph->bank_account,source_bank_account)==0)
            break;
        tmp_source_graph = tmp_source_graph->next;
    }
    if(tmp_source_graph==NULL) { //In case there is no node
        printf("|%s| does not exist - abort-l;\n", source_bank_account);
        return;
    }
    adjNode *position_in_adjlist;
    adjNode *previous=NULL;
    bool first_node;
    position_in_adjlist=tmp_source_graph->current_head;
    first_node=true;
    while (position_in_adjlist!=NULL){
        if(strcmp(position_in_adjlist->destination,destination_bank_account)==0 ) {
            destination_exists=true;
            if(position_in_adjlist->weight==money) {
                weight_exists=true;
                if (first_node) {                                                                //If the node is the first in the adjacency list
                    tmp_source_graph->current_head = tmp_source_graph->current_head->next_node; //Move the head to the next node so the list begins from next node
                    free(position_in_adjlist->destination);
                    free(position_in_adjlist);
                } else {
                    previous->next_node = position_in_adjlist->next_node; //Connect the previous node with the next node of the one we want to delete
                    free(position_in_adjlist->destination);
                    free(position_in_adjlist);
                }
                printf("Del-vertex |%s|->%d->|%s|\n",source_bank_account,money,destination_bank_account);
                return;
            }
        }
        if(strcmp(position_in_adjlist->destination,destination_bank_account)==0 && money==-1){ //Delete all edges
            destination_exists=true;
            weight_exists=true;
            if (first_node) {                                                                //If the node is the first in the adjacency list
                tmp_source_graph->current_head = tmp_source_graph->current_head->next_node; //Move the head to the next node so the list begins from next node
                printf("Del-vertex |%s|->%d->|%s|\n",source_bank_account,position_in_adjlist->weight,destination_bank_account);
                free(position_in_adjlist->destination);
                free(position_in_adjlist);
                position_in_adjlist = tmp_source_graph->current_head;
            } else {
                previous->next_node = position_in_adjlist->next_node; //Connect the previous node with the next node of the one we want to delete
                printf("Del-vertex |%s|->%d->|%s|\n",source_bank_account,position_in_adjlist->weight,destination_bank_account);
                free(position_in_adjlist->destination);
                free(position_in_adjlist);
                position_in_adjlist = previous->next_node;
            }
            continue;
        }
        previous=position_in_adjlist;
        position_in_adjlist=position_in_adjlist->next_node;
        first_node=false;
    }
    if(destination_exists==false) {
        printf("|%s| does not exist - abort-l;\n", destination_bank_account);
        return;
    }
    if(weight_exists==false)
        printf("|%s|->%d->|%s| does not exist - abort-l;\n",source_bank_account,money,destination_bank_account);
}


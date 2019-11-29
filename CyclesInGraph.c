#include "Graph.h"
bool flagc;
void print_the_stackc(struct node_in_stack** stack,BANK_ACC wanted_node){
    struct node_in_stack *stack2 = NULL;
    BANK_ACC k;
    int w;
    while ((*stack) != NULL) {
        k = pop(stack, &w);
        push(&stack2, k, w); //We use stack2 to print the cycle in the right order
    }
    if(!flagc)
        printf("\n- Cir-found |%s|", wanted_node);
    else
        printf("|%s|",wanted_node);
    while (stack2 != NULL) {
        k = pop(&stack2, &w); //Copy to another stack for correct order printing
        printf("->%d->|%s|", w, k);
        push(stack, k, w); //Then push the values back to the stack to find the remaining cycles(if they exist)
        free(k);
    }
    printf("\n");
}
void traverse_in_graph(struct node_of_graph **graph_head,adjNode **current_node,struct node_in_stack** stack,BANK_ACC wanted_node,int min_weight) {
    struct node_of_graph *tmp_source_graph = *graph_head;
    int w;
    BANK_ACC free_ptr;
    adjNode *pos_in_adjlist;
    while (strcmp(tmp_source_graph->bank_account, (*current_node)->destination) != 0) { //We find the position in the graph_list of the current node's adjacency list
        tmp_source_graph = tmp_source_graph->next;
    }

    pos_in_adjlist = tmp_source_graph->current_head;
    while (pos_in_adjlist != NULL){
        if(pos_in_adjlist->visited==0) //If there is at least one not visited node then we assign value 2
            break;
        pos_in_adjlist = pos_in_adjlist->next_node;
    }
    if(pos_in_adjlist==NULL)
        tmp_source_graph->visited=2;
    else
        tmp_source_graph->visited = 1;

    push(stack, tmp_source_graph->bank_account, (*current_node)->weight); //Node is being pushed in the stack with the weight which is connected to the previous node
    (*current_node)->visited=1;
    if (strcmp(tmp_source_graph->bank_account, wanted_node) == 0) {
        //if (strcmp((*stack)->acc, wanted_node) == 0) { //If the top value of stack has the value of the wanted node then we have created a cycle
            print_the_stackc(stack, wanted_node);
            flagc = true;
        //}
    }


    if (tmp_source_graph->visited == 2) { //If a node is completely visited
        if(exists_in_stack(stack,tmp_source_graph->bank_account,(*current_node)->weight)==0) { //If it does not exist again in the stack zero all visits of it and its adjacency list
            //If the node exists in the stack we don't want to zero its values as it is being partly used
            tmp_source_graph->visited = 0;
            pos_in_adjlist = tmp_source_graph->current_head;
            while (pos_in_adjlist != NULL) {
                pos_in_adjlist->visited = 0;
                pos_in_adjlist = pos_in_adjlist->next_node;
            }
        }
        free_ptr = pop(stack, &w);
        free(free_ptr);
        return;
    }


    pos_in_adjlist = tmp_source_graph->current_head;
    while (pos_in_adjlist != NULL) { //We parse the adjacency list of the node
         if (pos_in_adjlist->weight > min_weight && pos_in_adjlist->visited==0) { //Here we check for the limit of the weight
             traverse_in_graph(graph_head,&pos_in_adjlist, stack, wanted_node, min_weight); //Recursively we call the function until we find our cycle
             pos_in_adjlist->visited=0;
         }
        if(pos_in_adjlist->weight <= min_weight){
            pos_in_adjlist->visited=1; //We assign 1 although it is never visited actually because we want to know that there aren't any nodes left that we didn't take onto consideration
        }
        pos_in_adjlist = pos_in_adjlist->next_node;
    }
    if(exists_in_stack(stack,tmp_source_graph->bank_account,(*current_node)->weight)==0) {
        tmp_source_graph->visited = 0;
        pos_in_adjlist = tmp_source_graph->current_head;
        while (pos_in_adjlist != NULL) {
            pos_in_adjlist->visited = 0;
            pos_in_adjlist = pos_in_adjlist->next_node;
        }
    }
    free_ptr = pop(stack, &w);
    free(free_ptr);
}
void circlefind(struct node_of_graph **graph_head, BANK_ACC node,int k){
    struct node_of_graph *tmp_source_graph=*graph_head;
    struct node_of_graph *save=NULL;
    struct node_in_stack* root_of_stack=NULL; //The stack is initialized
    adjNode *position_in_adjlist,*pos;
    flagc=false;
    while (tmp_source_graph!=NULL){
        tmp_source_graph->visited=0;
        position_in_adjlist=tmp_source_graph->current_head;
        while (position_in_adjlist!=NULL){
            position_in_adjlist->visited=0;
            position_in_adjlist=position_in_adjlist->next_node;
        }
        if(strcmp(tmp_source_graph->bank_account,node)==0)
            save=tmp_source_graph; //Finds the position of the node that we want to be in a cycle
        tmp_source_graph = tmp_source_graph->next;
    }
    if(save==NULL){ //Error message
        printf("|%s| does not exist - abort-r\n",node);
        return;
    }
    if(save->current_head==NULL) { //When a node has not an adjacency list doesn't have a cycle
        printf("No-circle-found involving |%s| %d\n", node,k);
        return;
    }

    position_in_adjlist=save->current_head;
    while (position_in_adjlist!=NULL) {
        if(position_in_adjlist->weight>k) {

            //Everytime our source nodes explores the next neighbour we reinitialize everything
            tmp_source_graph=*graph_head;
            while (tmp_source_graph!=NULL) {
                tmp_source_graph->visited = 0;
                pos = tmp_source_graph->current_head;
                while (pos != NULL) {
                    pos->visited = 0;
                    pos = pos->next_node;
                }
                tmp_source_graph=tmp_source_graph->next;
            }
            free_stack(&root_of_stack);

            traverse_in_graph(graph_head, &position_in_adjlist, &root_of_stack, node, k); //Call the recursive function
        }
        position_in_adjlist = position_in_adjlist->next_node;
    }
    if(flagc==false)
        printf("No-circle-found involving |%s| %d\n", node,k);
    free_stack(&root_of_stack);
}


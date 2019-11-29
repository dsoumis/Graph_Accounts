#include "Graph.h"
bool flag;
void print_the_stacks(struct node_in_stack** stack,BANK_ACC wanted_node){
    struct node_in_stack* stack2=NULL;
    char *k;
    int w;
    while ((*stack)!=NULL){
        k=pop(stack,&w);
        push(&stack2,k,w); //We use stack2 to print the cycle in the right order
    }
    if(!flag)
        printf("\nCir-found |%s|",wanted_node);
    else
        printf("|%s|",wanted_node);
    while (stack2!=NULL){
        k=pop(&stack2,&w); //Copy to another stack for correct order printing
        printf("->%d->|%s|",w,k);
        push(stack,k,w); //Then push the values back to the stack to find the remaining cycles(if they exist)
        free(k);
    }
    printf("\n");
}
void traverse_in_graph_simply(struct node_of_graph **graph_head,adjNode **current_node,struct node_in_stack** stack,BANK_ACC wanted_node){
    struct node_of_graph *tmp_source_graph=*graph_head;
    int w;
    adjNode *pos_in_adjlist;
    BANK_ACC free_ptr;

    while (strcmp(tmp_source_graph->bank_account,(*current_node)->destination)!=0){ //We find the position in the graph_list of the current node's adjacency list
        tmp_source_graph = tmp_source_graph->next;
    }

    if(exists_in_stack(stack,tmp_source_graph->bank_account,(*current_node)->weight)==0)
        push(stack,tmp_source_graph->bank_account,(*current_node)->weight); //Node is being pushed in the stack with the weight which is connected to the previous node
    if(strcmp((*stack)->acc,wanted_node)==0) { //If the top value of stack has the value of the wanted node then we have created a cycle
        print_the_stacks(stack,wanted_node);
        flag=true;
        free_ptr=pop(stack,&w); //In order to avoid duplicate results
        free(free_ptr);
        return;
    }


    if(tmp_source_graph->visited==1 && strcmp(tmp_source_graph->bank_account,wanted_node)!=0){ //If the node is already visited remove it from the stack so the simple cycle is correct
        free_ptr=pop(stack,&w);
        free(free_ptr);
        return;
    }
    tmp_source_graph->visited=1;
    pos_in_adjlist=tmp_source_graph->current_head;
    while (pos_in_adjlist!=NULL) { //We parse the adjacency list of the node
        traverse_in_graph_simply(graph_head, &pos_in_adjlist, stack, wanted_node); //Recursively we call the function until we find our cycle
        pos_in_adjlist = pos_in_adjlist->next_node;
    }
    tmp_source_graph->visited = 0; //If there are no other nodes unvisited in the adjacency list we mark the node and the adjacency list as unvisited
    pos_in_adjlist = tmp_source_graph->current_head; //As it will no longer be in our stack
    while (pos_in_adjlist != NULL) {
        pos_in_adjlist->visited = 0;
        pos_in_adjlist = pos_in_adjlist->next_node;
    }
    free_ptr=pop(stack,&w);
    free(free_ptr);
}
void simplecirclefind(struct node_of_graph **graph_head, BANK_ACC node){
    struct node_of_graph *tmp_source_graph=*graph_head;
    struct node_of_graph *save=NULL;
    struct node_in_stack* root_of_stack=NULL; //The stack is initialized
    flag=false;
    while (tmp_source_graph!=NULL){
        tmp_source_graph->visited=0; //Initializes that all nodes are not visited
        if(strcmp(tmp_source_graph->bank_account,node)==0)
            save=tmp_source_graph; //Finds the position of the node that we want to be in a simple cycle
        tmp_source_graph = tmp_source_graph->next;
    }
    if(save==NULL){ //Error message
        printf("|%s| does not exist - abort-r\n",node);
        return;
    }
    if(save->current_head==NULL) { //When a node has not an adjacency list doesn't have a simple cycle
        printf("No-circle-found |%s|\n", node);
        return;
    }
    adjNode *position_in_adjlist=save->current_head;
    while (position_in_adjlist!=NULL) {
        traverse_in_graph_simply(graph_head, &position_in_adjlist, &root_of_stack, node); //Call the recursive function
        position_in_adjlist = position_in_adjlist->next_node;
    }
    if(flag==false)
        printf("No-circle-found |%s|\n", node);
    free_stack(&root_of_stack);
}


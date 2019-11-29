#include "Stack.h"

void push(struct node_in_stack** root,char* acc,int weight) {
    struct node_in_stack* node=(struct node_in_stack*)malloc(sizeof(struct node_in_stack));
    node->acc=malloc(strlen(acc)+1);
    strcpy(node->acc,acc);
    node->weight=weight;
    node->next = *root;
    *root = node;
}

char* pop(struct node_in_stack** root,int *w) {
    if (*root==NULL)
        return "-1";
    struct node_in_stack* temp = *root;
    *root = (*root)->next;
    char *popped=malloc(strlen(temp->acc)+1);
    strcpy(popped,temp->acc);
    *w=temp->weight;
    free(temp->acc);
    free(temp);
    return popped;
}

void free_stack(struct node_in_stack** root){
    while (*root!=NULL) {
        struct node_in_stack *temp = *root;
        *root = (*root)->next;
        free(temp->acc);
        free(temp);
    }
}

short int exists_in_stack(struct node_in_stack** root,char* acc,int weight){
    struct node_in_stack* temp = *root;
    while (temp!=NULL){
        if(strcmp(temp->acc,acc)==0 && temp->weight==weight)
            return 1;
        temp=temp->next;
    }
    return 0;
}
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
    #include "Stack.h"
    void push(struct node_in_stack** ,char* ,int);
    char* pop(struct node_in_stack**,int * );
    void free_stack(struct node_in_stack** );
    short int exists_in_stack(struct node_in_stack** ,char* ,int );
#endif

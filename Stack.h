#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node_in_stack{
    char* acc;
    int weight;
    struct node_in_stack* next;
};
#endif

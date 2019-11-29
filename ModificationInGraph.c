#include "Graph.h"
void modify_weight(struct node_of_graph **graph_head, BANK_ACC source_bank_account, BANK_ACC destination_bank_account, int current_money,  int money){
    bool source_exist=false;
    bool dest_exist=false;
    bool money_exist=false;
    struct node_of_graph *tmp_source_graph;
    tmp_source_graph=*graph_head;
    adjNode *parse_of_adj;
    while (tmp_source_graph != NULL) {
        if (strcmp(tmp_source_graph->bank_account,source_bank_account)==0) {
            source_exist=true;
            parse_of_adj = tmp_source_graph->current_head;
            while (parse_of_adj!=NULL) {
                if (strcmp(parse_of_adj->destination,destination_bank_account)==0) {
                    dest_exist=true;
                    if(parse_of_adj->weight==current_money) {
                        money_exist=true;
                        printf("Mod-vertex |%s|->%d->|%s|\n", source_bank_account, money, destination_bank_account);
                        parse_of_adj->weight = money;                               //update the money transfer
                        return;
                    }
                }
                parse_of_adj = parse_of_adj->next_node;
            }
        }
        tmp_source_graph=tmp_source_graph->next;
    }
    if(source_exist==false)
        printf("|%s| does not exist - abort-m;\n",source_bank_account);
    if(dest_exist==false){
        printf("|%s| does not exist - abort-m;\n",destination_bank_account);
        return;
    }
    if(money_exist==false)
        printf("|%s|->%d->|%s| does not exist - abort-m;",source_bank_account,current_money,destination_bank_account);
}
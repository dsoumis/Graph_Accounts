#include <stdio.h>
#include <unistd.h>
#include "GraphInterface.h"
int inputfile_add(struct node_of_graph **graph,char **argv,int j){
    char str1[100], str2[100], str3[100];
    int ll;

    FILE *fp;
    fp = fopen(argv[j], "r");
    if (fp == NULL) {
        printf("Problem in file opening\n");
        return 27;
    }
    while (fgets(str1,100,fp)) {
        sscanf(str1,"%s" "%s" "%d",str2,str3,&ll);
        addEdge(graph,str2,str3,ll);
    }
    fclose(fp);
}
int outputfile_add(struct node_of_graph **graph,char **argv,int j){
    FILE *fp;
    fp = fopen(argv[j], "w");
    if (fp == NULL) {
        printf("Problem in file opening\n");
        return 27;
    }
    //https://cboard.cprogramming.com/c-programming/127795-write-void-function-output-file.html The code below was found in the link
    int fd=fileno(fp), copy=dup(1);
    dup2(fd,1);
    print(graph);    // this one is to "outputfile".txt
    fflush(stdout);
    fclose(fp);
    dup2(copy,1); /* return stdout to normal */
}
void orders(struct node_of_graph **graph){
    char str1[100], str2[100];
    int value1, value2;
    //printf("Waiting for orders..\n");
    scanf("%s",str1);
    while(strcmp(str1,"e")!=0){
        if(strcmp(str1,"i")==0){
            scanf("%s",str1);
            graph_insert_last(graph,str1);
        }
        else if(strcmp(str1,"n")==0){
            scanf("%s",str1);
            scanf("%s",str2);
            scanf("%d",&value1);
            addEdge(graph,str1,str2,value1);
        }
        else if(strcmp(str1,"d")==0){
            scanf("%s",str1);
            delete_node(graph,str1);
        }
        else if(strcmp(str1,"l")==0){
            scanf("%s",str1);
            scanf("%s",str2);
            value1=getchar();
            if(value1==10) //10 is the ascii code of "Enter" which means the uses did not give a weight
                delete_weight(graph,str1,str2,-1);
            else { //If it is not an enter then the user uses space(ascii 32) and then a weight.
                scanf("%d",&value1); //So we read the weight here
                delete_weight(graph, str1, str2, value1);
            }
        }
        else if(strcmp(str1,"m")==0){
            scanf("%s",str1);
            scanf("%s",str2);
            scanf("%d",&value1);
            scanf("%d",&value2);
            modify_weight(graph,str1,str2,value1,value2);
        }
        else if(strcmp(str1,"r")==0){
            scanf("%s",str1);
            receiving(graph,str1);
        }
        else if(strcmp(str1,"c")==0){
            scanf("%s",str1);
            simplecirclefind(graph,str1);
        }
        else if(strcmp(str1,"f")==0){
            scanf("%s",str1);
            scanf("%d",&value1);
            circlefind(graph,str1,value1);
        }
        else if(strcmp(str1,"t")==0){
            scanf("%s",str1);
            scanf("%s",str2);
            scanf("%d",&value1);
            traceflow(graph,str1,str2,value1);
        }
        else if(strcmp(str1,"-o")==0){
            print(graph);
        }else{
            printf("Not available order\n");
        }
        //printf("Waiting for orders..\n");
        scanf("%s",str1);
    }
}
int main(int argc,char** argv) {
    struct node_of_graph *graph=create_graph();
    if(argc==1) {
        addEdge(&graph,"alv","ola",779);
        addEdge(&graph,"alv","mar",755);
        addEdge(&graph,"alv","mar",779);
        addEdge(&graph,"mar","ola",400);
        addEdge(&graph,"mar","alv",838);
        addEdge(&graph,"mar","myra",400);
        //addEdge(&graph,"e","a",500);
        circlefind(&graph,"alv",300);
    }else {
        int j = 1;
        if(argc==5) {
            int i = 1;
            while (strcmp(argv[j], "-i") != 0) {
                j++;
            }
            j++;
            inputfile_add(&graph,argv,j);
            while (strcmp(argv[i], "-o") != 0) {
                i++;
            }
            i++;
            outputfile_add(&graph,argv,i);
            orders(&graph);
        }else if(argc==3){
            while (strcmp(argv[j], "-i") != 0 && strcmp(argv[j], "-o") != 0) {
                j++;
            }
            if(strcmp(argv[j], "-i") == 0) {
                j++;
                inputfile_add(&graph,argv,j);
                orders(&graph);
            }else{
                j++;
                outputfile_add(&graph,argv,j);
                orders(&graph);
            }
        }
    }
    end_of_graph(&graph);
}

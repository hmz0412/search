#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear.h"
void query_arr(int *info,int *query,int info_len,int query_len){
    int i,j;
    for(i=0;i<query_len;i++){
        for(j=0;j<info_len;j++){
            if(query[i]==info[j]){
                break;
            }
        }
    }
}

link *insert_ll(link *L,int data){
    link *p=malloc(sizeof(link));
    p->data=data;
    p->next=L;
    return p;
}

void find_ll(link *L,int data){
    link *p=L;
    while(p){
        if(p->data==data){
            break;
        }
        p=p->next;
    }
}



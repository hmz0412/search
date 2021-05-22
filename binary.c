#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"

tree *insert_bst(tree *node,int data){
    if(node!=NULL){
        if(data<node->data){
            node->L=insert_bst(node->L,data);
        }
        else if(data>node->data){
            node->R=insert_bst(node->R,data);
        }
    }
    else{
        node=malloc(sizeof(tree));
        node->data=data;
        node->L=NULL;
        node->R=NULL;
    }
    return node;
}

void find_bst(tree *node,int data){
    tree *p=node;
    while(p){
        if(p->data==data){
            break;
        }
        else if(data<p->data){
            p=p->L;
        }
        else if(data>p->data){
            p=p->R;
        }
    }
}

int comp(const void *a,const void *b){
    return(*(int *)a-*(int *)b);
}

void query_bs(int *arr,int *query,int info_len,int query_len){
    int high,low,mid;
    int info,i;
    for(i=0;i<query_len;i++){
    high=info_len;
    low=0;
    info=query[i];
    while(low<high-1){
        mid=(high+low)/2;
        if(arr[mid]==info){
            break;
        }
        else if(arr[mid]>info){
            high=mid;
        }
        else{
            low=mid;
        }
    }
    if(low==high-1){
        if(arr[low]==info){
            continue;
        }
        else if(arr[high]==info){
            continue;
        }
    }
    }
}

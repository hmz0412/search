#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#define maxhash 1024
struct dnode *l_insert(struct dnode *L,int data){
    struct dnode *p;
    p=(struct dnode *)malloc(sizeof(struct dnode));
    p->data=data;
    p->next=L;
    return p;
}
void insert_hash(struct dnode **hTab,int data){
    int hv;
    struct dnode *dptr;
    hv = data % maxhash;
    dptr=hTab[hv];
    hTab[hv]=l_insert(dptr,data);
}
void l_find(struct dnode *L,int data){
    struct dnode *p;
    p=L;
    while(p){
        if(data==p->data) break;
        p=p->next;
    }
}
void find_hash(struct dnode **hTab,int data){
    int hv;
    struct dnode *dptr;
    hv=data % maxhash;
    dptr = hTab[hv];
    l_find(dptr,data);
}

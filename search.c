#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "linear.h"
#include "binary.h"
#include "hash.h"
#define ON 1
#define OFF 0
#define maxhash 1024
int main(int argc,char *argv[]){
    int i=0;
    int insert_data;
    int search_data;
    int bst=OFF;
    int bs=OFF;
    int arr=OFF;
    int ll=OFF;
    int hash=OFF;
    int *info_ins;
    int *info_que;
    link *list=NULL;
    tree *root=NULL;
    struct dnode **hTab;
    struct timeval start;
	struct timeval end;
    unsigned long  build_t,query_t,arr_t;
    hTab = (struct dnode **)malloc(sizeof(struct dnode *)*maxhash);
     for(i=0;i<maxhash;i++){
        hTab[i]=NULL;
    }
    if(argc>1){
        for(i=1;i<argc;i++){
            if(strcmp("-d",argv[i])==0){
                if(strcmp("1e4",argv[i+1])==0){
                    insert_data=10000;
                }
                else if(strcmp("1e5",argv[i+1])==0){
                    insert_data=100000;
                }
                else if(strcmp("1e6",argv[i+1])==0){
                    insert_data=1000000;
                }
                continue;
            }
            if(strcmp("-q",argv[i])==0){
                if(strcmp("1e3",argv[i+1])==0){
                    search_data=1000;
                }
                else if(strcmp("1e4",argv[i+1])==0){
                    search_data=10000;
                }
                else if(strcmp("1e5",argv[i+1])==0){
                    search_data=100000;
                }
                continue;
            }
            if(strcmp("-bst",argv[i])==0){
                bst=ON;
                continue;
            }
            if(strcmp("-bs",argv[i])==0){
                bs=ON;
                continue;
            }
            if(strcmp("-arr",argv[i])==0){
                arr=ON;
                continue;
            }
            if(strcmp("-ll",argv[i])==0){
                ll=ON;
                continue;
            }
            if(strcmp("-hash",argv[i])==0){
                hash=ON;
                continue;
            }
        }
        info_ins=malloc(sizeof(int)*insert_data);
        info_que=malloc(sizeof(int)*search_data);
        for(i=0;i<search_data;i++){
            info_que[i]=rand();
        }
        gettimeofday(&start, NULL);
        for(i=0;i<insert_data;i++){
            info_ins[i]=rand();
        }
        gettimeofday(&end, NULL);
        arr_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
        if(arr){
            printf("arr:\n");
            gettimeofday(&start, NULL);
            query_arr(info_ins,info_que,insert_data,search_data);
            gettimeofday(&end, NULL);
            query_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
            printf("building time: %f sec\n",arr_t/1000000.0);
            printf("query time: %f sec\n\n",query_t/1000000.0);
        }
        if(ll){
            printf("ll:\n");
            gettimeofday(&start, NULL);
            for(i=0;i<insert_data;i++){
                list=insert_ll(list,info_ins[i]);
            }
            gettimeofday(&end, NULL);
            build_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
            gettimeofday(&start, NULL);
            for(i=0;i<search_data;i++){
                find_ll(list,info_que[i]);
            }
            gettimeofday(&end, NULL);
            query_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
            printf("building time: %f sec\n",build_t/1000000.0);
            printf("query time: %f sec\n\n",query_t/1000000.0);
        }
        if(bst){
            printf("bst:\n");
            gettimeofday(&start, NULL);
            for(i=0;i<insert_data;i++){
                root=insert_bst(root,info_ins[i]);
            }
            gettimeofday(&end, NULL);
            build_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
            gettimeofday(&start, NULL);
            for(i=0;i<search_data;i++){
                find_bst(root,info_que[i]);
            }
            gettimeofday(&end, NULL);
            query_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
            printf("building time: %f sec\n",build_t/1000000.0);
            printf("query time: %f sec\n\n",query_t/1000000.0);
        }
        if(hash){
            printf("hash:\n");
            gettimeofday(&start, NULL);
            for(i=0;i<insert_data;i++){
                insert_hash(hTab,info_ins[i]);
            }
            gettimeofday(&end, NULL);
            build_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
            gettimeofday(&start, NULL);
            for(i=0;i<search_data;i++){
                find_hash(hTab,info_que[i]);
            }
            gettimeofday(&end, NULL);
            query_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec;
            printf("building time: %f sec\n",build_t/1000000.0);
            printf("query time: %f sec\n\n",query_t/1000000.0);
        }
        if(bs){
            printf("bs:\n");
            gettimeofday(&start, NULL);
            qsort((void *)info_ins,insert_data,sizeof(info_ins[0]),comp);
            gettimeofday(&end, NULL);
            build_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec+arr_t;
            gettimeofday(&start, NULL);
            query_bs(info_ins,info_que,insert_data,search_data);
            gettimeofday(&end, NULL);
            query_t=1000000*(end.tv_sec-start.tv_sec)+ end.tv_usec - start.tv_usec+arr_t;
            printf("building time: %f sec\n",build_t/1000000.0);
            printf("query time: %f sec\n\n",query_t/1000000.0);
        }
    }
}

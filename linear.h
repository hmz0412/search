struct node{
    int data;
    struct node *next;
};
typedef struct node link;


void query_arr(int *info,int *query,int info_len,int query_len);
link *insert_ll(link *L,int data);
void find_ll(link *L,int data);

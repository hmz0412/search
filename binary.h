struct Tnode{
    int data;
    struct Tnode* L;
    struct Tnode* R;
};
typedef struct Tnode tree;

tree *insert_bst(tree *node,int data);
void find_bst(tree *node,int data);
int comp(const void *a,const void *b);
void query_bs(int *arr,int *query,int info_len,int query_len);

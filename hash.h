struct dnode{
    int data;
    struct dnode *next;
};

struct dnode *l_insert(struct dnode *L,int data);
void insert_hash(struct dnode **hTab,int data);
void l_find(struct dnode *L,int data);
void find_hash(struct dnode **hTab,int data);

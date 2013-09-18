typedef struct listNode {
   char word[9];
   struct listNode *next;
} node_l;


typedef struct tnode {
   int wordSize;
   node_l *list;
   struct tnode *left, *right;
} node_t;

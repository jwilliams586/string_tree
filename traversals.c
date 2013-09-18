#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "node.h"
#include "traversals.h"

void traverseInorder(node_t *root, int level) {
   node_l *p;

   if(root != NULL) {
      traverseInorder(root->left, level + 1);

	  printf("%*c", level * 2, ' ');
      printf("%d %s",root->wordSize, root->list->word);

	  p = root->list;
	  //While still more words, print them
	  while(p->next) {
	     printf(" %s", p->next->word);
		 p = p->next;
	  }
	  printf("\n");

      traverseInorder(root->right, level + 1);
   }
}

void traversePostorder(node_t *root, int level) {
   node_l *p;

   if(root != NULL) {
      traversePostorder(root->left, level + 1);
	  traversePostorder(root->right, level + 1);

	  printf("%*c", level * 2, ' ');
	  printf("%d %s",root->wordSize, root->list->word);

	  p = root->list;
	  //While still more words, print them
	  while(p->next) {
	     printf(" %s", p->next->word);
		 p = p->next;
	  }
	  printf("\n");
   }
}

void traversePreorder(node_t *root, int level) {
   node_l *p;

   if(root != NULL) {
      printf("%*c", level * 2, ' ');
	  printf("%d %s",root->wordSize, root->list->word);

	  p = root->list;
	  //While still more words, print them
	  while(p->next) {
	     printf(" %s", p->next->word);
		 p = p->next;
	  }
	  printf("\n");

	  traversePreorder(root->left, level + 1);
	  traversePreorder(root->right, level + 1);
   }
}

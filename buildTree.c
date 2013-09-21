#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "node.h"
#include "buildTree.h"

node_t *treeInsert(node_t *T, node_t *z);
int treeSearch(node_t *x, int k, char word[]);

node_t *buildTree(FILE *fp)
{
   char input, buffer[1028];
   node_t *s, *root;
   int i = 0, length, srch, line = 1;

   root = NULL;

   memset(buffer, '\0', sizeof(buffer));

   if(fp) {
      while((input = fgetc(fp)) != EOF) {
		 if(isdigit(input) != 0 || isalpha(input) != 0 || isspace(input) != 0) {
			if(input == '\n') {
               line++;
			}
	        if(isspace(input)) {
		       length = strlen(buffer);

			   if(length > 8) {
			      printf("Error on line %d! String %s longer than 8 characters!\n", line, buffer);
				  exit(EXIT_FAILURE);
			   }

			   srch = 0;
			   // Search tree to see if node exists already
			   // and add word to that node if not a duplicate
			   srch = treeSearch(root, length, buffer);

			   // If node doesn't exists, create it and insert
			   if(!srch) {
			      // Create node if needed
			      s = (node_t *) malloc(sizeof(node_t));
			      s->list = (node_l *) malloc(sizeof(node_l));
			      s->wordSize = length;
			      s->left = NULL;
			      s->right = NULL;

			      strcpy(s->list->word, buffer);
			      s->list->next = NULL;

			      // Insert into tree
			      if(root == NULL) {
		             root = s;
			      } else {
			         root = treeInsert(root, s);
			      }
               }
			   // Clear buffer
			   memset(buffer, '\0', sizeof(buffer));
			   i = 0;
		    } else {
		       buffer[i] = input;
			   i++;
		    }
         } else {
            printf("Error on line %d! Char %c not a valid character!\n", line, input);
            exit(EXIT_FAILURE); 
		 }
	  }
   }

   fclose(fp);

   return root;
}

node_t *treeInsert(node_t *T, node_t *z) {
   if(T->right == NULL && z->wordSize > T->wordSize)
      T->right = z;
   else if(T->right != NULL && z->wordSize > T->wordSize)
	  treeInsert(T->right, z);
   if(T->left == NULL && z->wordSize < T->wordSize)
	  T->left = z;
   else if(T->left != NULL && z->wordSize < T->wordSize)
	  treeInsert(T->left, z);
   return T;
}

int treeSearch(node_t *x, int k, char word[]) {
   node_t *tmp;
   node_l *d;

   tmp = x;
   while(tmp != NULL) {
	  // If found correct node, insert word
	  // return if we find duplicate word at any point
      if(k == tmp->wordSize) {
	     d = tmp->list;
		 if(strcmp(d->word, word) == 0)
			return 0;
	     while(d->next) {
		    d = d->next;
			if(strcmp(d->word, word) == 0)
			   return 0;
	     }

	     d->next = (node_l *) malloc(sizeof(node_l));
	     strcpy(d->next->word, word);
	     return 1;
      }

      if(k < tmp->wordSize) {
		 tmp = tmp->left;
      } else {
		 tmp = tmp->right; 
      }
   }
   return 0;
}

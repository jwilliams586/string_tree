#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "node.h"
#include "buildTree.h"
#include "traversals.h"

int main(int argc, char *argv[])
{

   FILE *fp;
   node_t  *root;
   char *filename;

   root = NULL;

   // Read file if given, or read stdin
   if(argc == 1) {
	  fp = stdin;
	  printf("No file given, using stdin. Ctrl + D to end input.\n");
   } else {
	  filename = malloc(strlen(argv[1]) + 4);
	  strcpy(filename, argv[1]);
	  strcat(filename, ".dat");
	  fp = fopen(filename, "r");
   }

   if(!fp) {
      printf("Error: file [%s] did not open!\n", filename);
	  return 1;
   }

   root = buildTree(fp);

   printf("Preorder\n");
   traversePreorder(root, 0);
   printf("\nInorder\n");
   traverseInorder(root, 0);
   printf("\nPostorder\n");
   traversePostorder(root, 0);
   printf("\n");

   return 0;
}

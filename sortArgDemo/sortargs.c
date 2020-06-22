#include "bst.h"  
  
int main(int c, char **argv)	/* prints arguments in order */
{
  for (char **p = &argv[1]; *p; p++)
    bstInsert(&bstRoot, *p);
  bstPrint(bstRoot);
  bstClear(&bstRoot);
}

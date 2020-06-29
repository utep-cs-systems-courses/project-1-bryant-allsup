#include <stdio.h>
#include "tokenizer.c"
#include "history.c"
void
main(void)
{
  List *list =init_history();
  int boolean = 1;
  int *value = 0;
  char get[99];
  while(boolean)
    {
      printf(">");
      fgets(get,100,stdin);
      
      if(get[0]=='!')
	{
	  int r = 1;
	  char *history;
	  printf("%d\n",r);
	  history = get_history(list,r);
	  printf("%s \n",history);
	}
      else if (get[0]=='^')
	{
	  free_history(list);
	  printf("Freed history \n");
	  boolean=0;
	}
      else{
	add_history(list,get);
	char** token= tokenize(get);
	print_tokens(token);
	free_tokens(token);
	print_history(list);
      }
      
    }
}

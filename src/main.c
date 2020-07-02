#include <stdio.h>
#include "tokenizer.c"
#include "history.c"
void
main(void)
{
  List *list =init_history();
  int *value = 0;
  int boolean = 1;
  char get[100];
  fgets(get,100,stdin);
  char **token = tokenize(get);
  print_tokens(token);
  free_tokens(token);
  add_history(list,get);
  add_history(list,"howdy");
  add_history(list,"what is up");
  print_history(list);
  char *gotten =  get_history(list,2);//should retrieve user input
  printf("gotten: %s\n",gotten);
  free_history(list);


  /*
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
	  print_history(list);
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
  */
}

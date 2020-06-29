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
      add_history(list,get);
      char** token= tokenize(get);
      print_tokens(token);
      free_tokens(token);
    }
  print_history(list);
  free_history(list);
  
}

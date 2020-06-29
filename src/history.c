#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history(){
  Item *dummy = malloc(sizeof(Item));//cretes and allocates space for dummy
  dummy->id=0;//places id at 0
  dummy->next=NULL;//no connecting items
  char *str={"I am Dummy"};
  dummy->str=str;
  List *list = malloc(sizeof(List));//allocates space for a list
  list->root=dummy;//sets dummy as root
  return list;
}

void add_history(List *list, char *str){
  Item *current= list->root;
  while(current->next!=NULL){
    current=current->next;
  }
  int id =current->id;
    current->next = (Item *)malloc(sizeof(Item));
    current->next->id = id+1;
    current->next->str = str;
    current->next->next =NULL;
 
}
char *get_history(List *list, int id){
  Item *current= list->root;
  char *string;

  for(int i = 0;current->id!=i && current->next!=NULL;i++)
    {current=current->next;
  if(current->next->id==i){
      string = current->str;
      printf("History: %s \n",current->str);
      return string;
  }}
  printf("No String\n");
  return string;
}

void print_history(List *list){
  Item *current = list->root;
  while(current->next!=NULL){
      printf("%s: ",current->str);
      printf("id: %d\n",current->id);
      current = current->next;
  }
  if(current->next==NULL){
      printf("%s ",current->str);
      printf(" id: %d\n",current->id);
    }
}

void free_history(List *list){
  Item *current = list->root;
  Item *next = current->next;
  int id=0;
  while(next->next!=NULL) {//stops when next equal
    free(current);//frees current
    current=next;//sets current equal to next
    next=next->next;//sets next equal to next next
    }
    free (current);
    free (next);
}

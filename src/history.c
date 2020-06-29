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
  Item *temp = malloc(sizeof(Item));
  temp->str=str;
  temp->next=NULL;
  Item *current= list->root;
  int id = list->root->id+1;
  for(; current->next!=NULL; id++){
    current =current->next;
  }
  temp->id=id;
  if(current->next==NULL)
    {current->next=temp;}
  
 
}
char *get_history(List *list, int id){
  Item *current= list->root;
  char *string;

  while(current->id!=id && current->next!=NULL)
    {current=current->next;
  if(current->id==id){
      printf("%d\n",current->id);
      string = current->str;
      printf("We Found it\n");
      return string;
  }}
  printf("No String\n");
  return string;
}

void print_history(List *list){
  Item *current = list->root;
  while(current->next!=NULL){
      printf("%s ",current->str);
      printf(" id: %d\n",current->id);
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

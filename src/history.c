#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history(){
  Item *dummy = malloc(sizeof(Item));//cretes and allocates space for dummy
  dummy->id=0;//places id at 0
  dummy->next=NULL;//no connecting items
  dummy->str="First";
  List *list = malloc(sizeof(List));//allocates space for a list
  list->root=dummy;//sets dummy as root
  return list;
}

void add_history(List *list, char *str){
  Item *current= list->root;
  int id = 1;
  while(current->next!=NULL)
    {
      current=current->next;
      id++;
    }
  current->next = (Item *)malloc(sizeof(Item));//creating next node
  current=current->next;
  current->id = id;
  current->str = str;//setting attributes
  current->next =NULL;
}
char *get_history(List *list, int id){
  Item *current= list->root;
  if(id==0)
    {return current->str;}
  
  int number = current->id;// is 0
  while(number<id)
    {
      current=current->next;
      int number = current->id;
      printf("%d\n",number);
      if(++number==id){
	return current->next->str;
      }
      
    }
  
  char *notFound = {"No String found"};
  return notFound;
}

void print_history(List *list){
  Item *current = list->root;
  while(current->next!=NULL){
    printf("%d: %s \n",current->id,current->str);
    current = current->next;
  }
  printf("%d: %s \n",current->id,current->str);
}

void free_history(List *list){
  Item *current = list->root;
  Item *hold;
  while(current->next!=NULL) {//stops when next equal null
    hold=current;
    free(current);
    current = current->next;
    }
  free(current);//must free last current since stops early
  free(list);//free list
}

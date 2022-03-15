#include "history.h"
#include <stdlib.h>
#include <stdio.h>

List *init_history() {
  List *to_return;
  to_return =(List *) calloc(1, sizeof(List));
  return to_return;
}

void add_history(List *list, char *str) {
  //If list is empty, list->root will == 0
  if(list->root == 0) {
    //Create first list entry
    //All values initialized to 0
    list->root = (Item *) calloc(1, sizeof(Item));
    //Assign str to str in the root of list
    list->root->str = str;
    //No need to assign an id, it has been initialized to 0
    return;
  }
  Item *traverser = list->root;
  //Traverse Linked List
  while(traverser->next!= 0) {
    traverser = traverser->next;
  }
  //Create new link at end of list with all fields = 0
  traverser->next = (Item *) calloc(1, sizeof(Item));
  
  Item *new_link = traverser->next;
  new_link->id = traverser->id + 1;
  new_link->str = str;
  return;
}

char *get_history(List *list, int id){
  Item *traverser = list->root;
  while(traverser->id < id && traverser->next != 0){
    traverser = traverser->next;
  }
  if (traverser->id != id) {
    return 0;
  }else {
    return traverser->str;
  }
}

void print_history(List *list) {
  Item *traverser = list->root;
  while(traverser != 0){
    printf("%d. %s\n", traverser->id, traverser->str);
    traverser = traverser->next;
  }
}

void free_history(List *list) {
  Item *iter = list->root;
  if(iter == 0) {
    free(list);
    return;
  }
  Item *temp = iter->next;
  while(temp != 0) {
    free(iter->str);
    free(iter);
    iter = temp;
    temp = temp->next;
  }
  free(iter->str);
  free(iter);
  free(list);
  return;
}

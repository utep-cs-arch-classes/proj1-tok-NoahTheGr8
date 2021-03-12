#include <stdio.h>
#include <stdlib.h>
#include "history.h"


/* Initialize the linked list to keep the history.*/
List* init_history(){
  return (List*)malloc(sizeof(List) * 1);
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){

  //create a new node
  Item *item = (Item*)malloc(sizeof(Item) * 1);
  item->str = str;
  
  //if there is no head then set it to the head
  if (list->root == NULL){
    list->root = item;
  } 
  else{
    Item *curr = list->root;
    //traverse to the last element of the list
    int id = 0;
    while(curr->next != NULL){
      curr = curr->next;
      id++;
    }//while

    //set the values of the new node
    curr->next = item;
    item->id = id+1;
  }//else
  
}//add_history()

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){

  Item *curr = list->root;
  //traverse entire list to find desired link
  while( curr != NULL ){
    if( curr->id == id ){
      printf(" ** RETRIEVED LINK **\n");
      return curr->str;
    }
    curr = curr->next;
  }//while

  //if the id was not found in the list
  return NULL;
  
}//get_history()


/* Print the entire contents of the list. */
void print_history(List *list){

  Item *curr = list->root;//get the head of the list

  //traverse all elements until curr = NULL
  while(curr != NULL){
    printf("Input %d: %s\n", curr->id, curr->str);
    curr = curr->next;
  }//while
  
}//print_history()


/* Free the history list and the strings it references. */
void free_history(List *list){

  //Free all the links in the linked list
  Item *curr = list->root;
  Item *prev;

  //Analogy to process below: destroying a bridge behind you so that you can never go back 
  while(curr != NULL){
    prev = curr;
    curr = curr->next;

    free(prev->str);//free the string
    free(prev);//free the link
  }
  
  //Free the list
  free(list);
  
}//free_history()

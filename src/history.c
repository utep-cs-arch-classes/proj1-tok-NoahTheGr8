#include <stdio.h>
#include <stdlib.h>
#include "history.h"


/*

--------- TOP OF HEADER FILE --------- 

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;
 */

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
  
  //if there is no head then set it to the head
  if (list->root == NULL){
    printf("<<<< CREATED A NEW HEAD >>>\n");
    list->root = item;
    list->root->next = NULL;
    list->root->id = 0;
  }
    
  //else append node to the end linked list
 
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){


}

/* Print the entire contents of the list. */
void print_history(List *list){

  //curr navigates through the linked list
  Item *curr = list->root;

  while(curr != NULL){
    printf("Input %d: ", curr->id);
    printf("%s\n",curr->str);
    curr = curr->next;
  }
  
}//print_history()

/* Free the history list and the strings it references. */
void free_history(List *list){


}

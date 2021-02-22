#include <stdio.h>
#include "tokenizer.h"
#include "tokenizer.c"

#define LIMIT 100
/*
  runner.c - this is the file that starts the tokenizer application

 */

void main(){
  
  //Welcome User
  printf("GREETINGS USER\n");
  
  //Get Input
  char c;
  int ind = 0; //ind is index for storing chars in usr_input string
  char usr_input[LIMIT]; //Stores an input of size LIMIT
  printf("IN > ");
  while( (c=getchar()) != '\n' ){
    usr_input[ind] = c;
    printf("OUT > ");
    putchar(c);
    printf(" | SPACE CHAR: %d", space_char(c));
    printf(" | NON SPACE CHAR: %d" , non_space_char(c));
    ind++;
    printf("\n");
  
  }//while

  printf("Input: ");
  printf(usr_input);
  printf("\n");
  
  //passes the address since word_start parameter is a pointer
  
  char *ptr = word_start(usr_input);
  printf("Actual address of first char: %p\n", &usr_input[1]);
  printf("ptr address of first char: %p\n", ptr);
}//main

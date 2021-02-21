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
  while( (c=getchar()) != '\n' ){
    printf("> ");
    putchar(c);
    printf("| SPACE CHAR: %d", space_char(c));
    printf("| NON SPACE CHAR: %d" , non_space_char(c));
    printf("\n");

  }
}

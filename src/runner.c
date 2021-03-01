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
    /* USED FOR DEBUGGING
    printf("OUT > ");
    putchar(c);
    printf(" | SPACE CHAR: %d", space_char(c));
    printf(" | NON SPACE CHAR: %d" , non_space_char(c));
    printf("\n");
    */
    ind++;
  
  }//while

  printf("Input: ");
  printf(usr_input);
  printf("\n");
  
  /* USED FOR DEBUGGING
  printf("------------WORD START------------\n");
  //Assume you start on a space char
  char *ptr = word_start(usr_input);
  printf("*Actual address of first char: %p\n", &usr_input[3]);//FOR TESTING - change if you are user other inputs
  printf("ptr address of first char: %p\n", ptr);
  
  printf("------------WORD END------------\n");
  //Assume you start on a non_space char
  char *ptr1 = word_end(usr_input);
  printf("*Actual address of first space char: %p\n", &usr_input[3]);//change if you are using other inputs
  printf("ptr address of first space char: %p\n", ptr1);
  

  printf("------------COUNT WORDS------------\n");
  int totWords = count_words(usr_input);
  printf("Total Words in input> %d\n", totWords);
  printf("------------COPY STR------------\n");
  char *clone = copy_str(usr_input, 2);
  printf("USER INPUT address: %p\n", &usr_input);
  printf("COPIED address: %p\n", clone);

  printf("USER INPUT: %s\n", usr_input);
  //printf("USER INPUT size: %lu\n", sizeof(usr_input));
  printf("COPIED OUTPUT: %s\n", clone);
  //printf("COPIED OUTPUT size: %d\n", sizeof(clone));
  */
  
  printf("------------TOKENIZE------------\n");
  
  if(count_words(usr_input) != 0 ){
    char **tokens = tokenize(usr_input);
    print_tokens(tokens);
    free_tokens(tokens);
    print_tokens(tokens);//used to see if tokens are no longer there
  }
  else{
    printf("NO VALUES TO TOKENIZE\n");
  }
}//main

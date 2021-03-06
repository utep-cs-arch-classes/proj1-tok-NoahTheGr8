#include <stdio.h>
#include "tokenizer.h"
#include "tokenizer.c"

#define LIMIT 100
/*
  runner.c - this is the file that starts the tokenizer application

 */

void main(){

  char keep_going = 1;//updates if user wants to continue or end program
  while(keep_going){
    //Welcome User
    printf("GREETINGS USER\n");

    //---------------------- START WHILE  
    //Get Input
    char c;
    int ind = 0; //ind is index for storing chars in usr_input string
    char usr_input[LIMIT]; //Stores an input of size LIMIT
    printf("IN > ");
    while( (c=getchar()) != '\n' ){
      usr_input[ind] = c;
      ind++;  
    }//while

    printf("Input: ");
    printf(usr_input);
    printf("\n");
    
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

    //ASK USER IF THEY WANT TO DO IT AGAIN
    char kg;
    printf("\nTokenizer again? [y,n] > ");
    while( (c=getchar()) != '\n' ){
      kg = c; 
    }//while
    
    if(kg == 'n'){
      keep_going = 0;
      //will exit outter most while since user does not want to continue
    }
      
  }//END OUTTER WHILE


  }//main

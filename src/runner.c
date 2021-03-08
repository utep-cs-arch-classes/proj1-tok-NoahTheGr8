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
  
  //<CREATE LINKED LIST HERE>
  //List *list = init_history();
  char keep_going = 1;//updates if user wants to continue or end program
  while(keep_going){

    //---------------------- START WHILE  
    //Get Input
    char c;
    int ind = 0; //ind is index for storing chars in usr_input string
    char usr_input[LIMIT]; //Stores an input of size LIMIT
    printf("---------------------\n");
    printf("IN > ");
    while( (c=getchar()) != '\n' ){
      usr_input[ind] = c;
      ind++;  
    }//while
    //Add input to linked list here

    printf("Input: ");
    printf(usr_input);
    printf("\n");
    
    //------------TOKENIZE------------
    if(count_words(usr_input) != 0 ){
      char **tokens = tokenize(usr_input);
      print_tokens(tokens);
      free_tokens(tokens);
      //print_tokens(tokens);//used to see if tokens are no longer there
    }
    else{
      printf("NO VALUES TO TOKENIZE\n");
    }

    //ASK USER IF THEY WANT TO DO IT AGAIN
    char in;
    printf("\nTokenize again? [(y)es, (n)o, (h)ist] > ");
    while( (c=getchar()) != '\n' ){
      in = c; 
    }//while

    //Exit program if use does not want to keep going
    if(in == 'n'){
      keep_going = 0;
    }
    else{
      //reset the input before getting new input
      int i;
      for(i = 0; i < sizeof(usr_input)/sizeof(usr_input[0]); i++){
	usr_input[i] = 0;
      }
    }//else
    //Show previous inputs
    if(in == 'h'){
      // print_history(list);
    }
    
  }//END OUTTER WHILE

}//main

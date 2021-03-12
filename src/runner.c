#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.c"
#include "history.c"

#define LIMIT 100

void hist_req(char *input, List *list);

/*
  This is the file that starts the tokenizer application. Compile and run this program
  to start it. 
 */

void main(){

  //Welcome User
  printf("\n\t\t\t======== GREETINGS USER ========\n");
  printf("\t\t\tTOKENIZER  \\  STRING PARTITIONER\n");

  printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
  printf("GUIDE TO VALID INPUTS\n");
  printf("\t*   '!n'   - prints n'th input you entered (1'st input is considered as 0'th)\n");
  printf("\t*   '!'    - prints all the inputs you entered\n");
  printf("\t* <string> - tokenizes <string> and prints each token ('<','>' not required)\n");
  printf("\t*   'q'    - frees all memory in history for this program and EXITS\n");
  printf("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n");
  
  //Create a linked list that stores the history of inputs
  List *inp_hist = init_history();
  
  char keep_going = 1;//updates if user wants to continue or end program
  while(keep_going){
    
    //-------------- Get Input --------------
    char c;
    int ind = 0; //ind is index for storing chars in usr_input string
    char usr_input[LIMIT]; //Stores an input of size LIMIT
    
    printf("IN > ");
    while( (c=getchar()) != '\n' ){
      usr_input[ind] = c;
      ind++;  
    }//while

    //if user wants to quit program
    if((usr_input[0] == 'q') && (usr_input[1] == 0) ){
      
      keep_going=0;
    }
    //if user is requesting history
    else if(usr_input[0] == '!'){
      printf("OUT>\n");
      hist_req(usr_input , inp_hist);
    }
    //else user wants to tokenize
    else{
      printf("OUT>\n");
      //This will be for tokenizing
      //create a copy that will go into the linked list
      char *input = copy_str(usr_input, sizeof(usr_input) / sizeof(usr_input[0]));
      
      //Add input to linked list here
      add_history(inp_hist, input);
    
      //------------TOKENIZE------------
      if(count_words(usr_input) != 0 ){
	char **tokens = tokenize(usr_input);
	print_tokens(tokens);
	free_tokens(tokens);
      }//if
      else{
	printf("NO VALUES TO TOKENIZE\n");
      }//else
    }//else

    //reset the input before getting new input
      int i;
      for(i = 0; i < sizeof(usr_input)/sizeof(usr_input[0]); i++){
	usr_input[i] = 0;
      }//for

    
    printf("---------------------------\n");
  }//END OUTTER WHILE

  free_history(inp_hist);
  
  printf("\n\n\t\t\t======== FAREWELL USER ========\n\n");
  
}//main

//if the user is requesting history then go here
void hist_req(char *input, List *list){
  
  //print all if input is only exclamation mark
  if(input[1] == 0){
    print_history(list);
  }

  //print a specific input or link in the linked list
  else{
    //remove the exclamation point since we want to extract the id we want
    input++;
    
    char *id_start = word_start(input);
    char *id_end = word_end(id_start);
    char *req_id = copy_str( input ,(int)(id_end-id_start));

    //'id' is the requested id from the linked list we want to print | must convert string to int
    int id;
    sscanf(req_id, "%d", &id);

    //get the desired id or input from the linked list
    char *desired_input =  get_history(list, id);

    //prints vary according to input
    if(desired_input != NULL){
      printf("\tInput %d: %s\n", id , desired_input);
    }//if
    else{
      printf("\t *INVALID HISTORY ID*\n");
    }//else
    
  }//else

}//hist_req()

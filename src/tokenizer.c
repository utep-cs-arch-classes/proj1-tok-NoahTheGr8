/*
Author: R Noah Padilla
Last Updated: 2/28/21

Goal: complete space_char(), non_space_char(), word_start(),word_end(), and word_count(), copy_str(), tokenize(), free_tokens(), print_tokens()
 
Resources used: Class Book chapter 5 and lab recordings
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"


/* Return true (non-zero) if c is a whitespace characer
   (' ', '\t', or '\n').
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  
  int validity;
  if(c==' ' || c == '\t' || c== '\n'){
    validity = 1;
  } else{
    validity = 0;
  }
  return validity; 
}


/* Return true (non-zero) if c is a non-whitespace
   character (not space, tab, or newline).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c) {
  //var to store the whether c is nsc (a letter)
  int validity;
  if(c == ' ' || c == '\t' || c == '\n'){
    validity = 0;
  } else{
    validity = 1;
  }
  return validity;
}


/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words.
   str is assumed to be pointing to a space character */
// pointer to first nonspace char in first word s
char *word_start(char *str){

  /* USED FOR DEBUGGING
  //check if it doesnt contain any words
  printf("Local pointer address in word_start()> %p\n",&str);//prints *str address
  printf("Address that we are storing> %p\n",str);//prints contents in *str
  printf("First value of the address we are storing> %c\n",*str);//prints pointers stored address values
  printf("First values' address from address being stored from the word> %p\n", str);
  */

  //iterate using the pointer to access next value
  int i;
  for( i=0 ; *(str+i) != '\0'; i++){
    //printf("-Current ddress during iteration> %p\n",(str+i));//used for debugging
    //pass each char to nsc()
    if( non_space_char(*(str+i)) == 1 ){
        //printf("FIRST CHAR ENCOUNTERED AT> %p\n", (str+i));//used for debugging
	return (str+i);
    }
  }//for
  
  return '\0';

}//word start

/* Returns a pointer terminator to the first space character or string-terminator
   following str in a zero terminated string.
   str is assumed to be pointing to a non-space character*/
char *word_end(char *str){

  /* USED FOR DEBUGGING
  //check if it doesnt contain any words
  printf("Local pointer address in word_end()> %p\n",&str);//prints *str address
  printf("Address that we are storing in pointer> %p\n",str);//prints contents of address we are storing
  printf("First value of the address we are storing> %c\n",*str);//prints pointers stored first address values
  printf("First values' address being stored from the word> %p\n", str);
  */
  
  //iterate using the pointer to access next value
  int i = 0;

  while(1){
    //printf("-Current address during iteration> %p\n",(str+i));//used for debugging
    //pass each char to sc()
    if( (space_char(*(str+i)) == 1) || (*(str+i) == '\0') ){
        //printf("FIRST SPACE CHAR ENCOUNTERED AT> %p\n", (str+i)); //used for debugging
	return (str+i);
    }
    i++;
  }//while
  
}//word_end()


/* 
Counts the number of space seperated words in the string argument. 

I think of this function as a switch where 
everytime we see the start of a word, we lift the switch and when the word ends we drop the switch and increment the number of words we have

*/
int count_words(char *str){

  //Think of a switch we turn on/off = 1 word
  int words = 0;
  int swtch = 0;
  int i;
  for( i=0; *(str+i) != '\0'; i++){
    if(non_space_char(*(str+i))==1){
      swtch = 1;
    }
    if((swtch==1) && (space_char(*(str+i))==1)){
      words++;
      swtch=0;
    }
  }//for
  //if there was a word we didnt finish considering because of '\0'
  if(swtch == 1){
    words++;
  }
  return words;
  
}//count_words()


/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr>
 
"Returns len characters from src"

Returns the address of a subset of the word *intStr

NOTE: DOES NOT CONSIDER IF LEN IS GREATER THAN THE SIZE OF 'inStr' - assumes perfect scenario everytime
*/
char *copy_str(char *inStr, short len){
  
  //printf("Substring size: %d\n",len);//used for debugging
  //Allocate fresh memory | (len+1) indicates the substring plus the '\0' at the end
  char *clone = (char*)malloc(sizeof(char) * (len+1));
  int i; //keeps track of len
  for(i=0; i<len; i++){
    *(clone+i) = *(inStr+i); 
  }
  *(clone+(len)) = '\0';//set the last value to the zero terminator
  return clone;
}//copy_str()


/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str){
  
  printf("\n >> Tokenizing... <<\n");

  //Get number of words first
  int num_words = count_words(str);

  //Allocate memory for each word + zero terminator
  char **tokens;
  tokens = (char**)malloc(sizeof(char*) * (num_words+1) + 1);
    /* 
       -- Algorithm (influenced from lab 2/24/21)
               1) Get the word start and word end of str
	       2) Calcualate the distance in memory between start and end
	       3) Send word[start:end] to copy_str
	       4) Set step 3 to the array location of tokens
	       5) Repeat steps 1-4 with next word
     */
  
  int copied_words = 0;
  int ind = 0;//goes through to set the values of tokens array
  char *p_1;//points to address of the first letter of the next word from 'str'
  p_1 = word_start(str);
  char *p_2;//points to address of the first character after the last letter of p_1 from 'str'

  while( copied_words != num_words){

    //considers empty string and 1 input with 1 word and no spaces
    if((*p_1 == '\0')){
      break;
    }
    
    //get end of word
    p_2 = word_end(p_1);
  
    int dist = (int)(p_2-p_1);//calc len of word
    //printf("Distance between start and end: %d\n", dist);//used for debugging
    tokens[ind] = copy_str(p_1,dist);
    copied_words++;
    
    ind++;
    p_1 = word_start(p_2);//set the starting pointer to the last a value
  }//while

  tokens[ind] = '\0';//set the last value to z.t.
  
  printf(" >>...Done tokenizing<<\n");
  return tokens;

}//**tokenize()


/* Prints all tokens. */
void print_tokens(char **tokens){

  printf("\n ** PRINTING TOKENS... **\n");
  int i;
  for (i = 0; *(tokens+i) != 0 ; i++){
    printf("Token %d",i);
    printf(": %s\n",*(tokens+i));
  }//for
  printf(" ** ...DONE PRINTING **\n");
}//print_tokens()


/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens){
  printf("\n -- FREEING TOKENS...--\n");
  int i;
  for (i = 0; *(tokens+i) != 0 ; i++){
    free(*(tokens+i));//frees each token
    //printf("Token %d",i);//used for debugging
    //printf(": %s\n",*(tokens+i));//used for debugging
  }//for
  free(tokens);//frees the vector containing them
  printf(" -- ...DONE FREEING --\n");
  
}//free_tokens()

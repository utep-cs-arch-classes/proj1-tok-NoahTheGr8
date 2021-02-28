/*

Author: R Noah Padilla
Last Updated: 2/27/21

Goal: complete space_char(), non_space_char(), word_start(),word_end(), and word_count()
 
Resources used: Class Book chapter 5
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
  
  //check if it doesnt contain any words
  printf("Local pointer address in word_start()> %p\n",&str);//prints *str address
  printf("Address that we are storing> %p\n",str);//prints contents in *str
  printf("First value of the address we are storing> %c\n",*str);//prints pointers stored address values
  printf("First values' address from address being stored from the word> %p\n", str);
  
  //iterate using the pointer to access next value
  int i;
  for( i=0 ; *(str+i) != '\0'; i++){
    printf("-Current ddress during iteration> %p\n",(str+i));
    //pass each char to nsc()
    if( non_space_char(*(str+i)) == 1 ){
      printf("FIRST CHAR ENCOUNTERED AT> %p\n", (str+i));
	return (str+i);
    }
  }//for
  
  return '\0';

}//word start

/* Returns a pointer terminator to the first space character or string-terminator
   following str in a zero terminated string.
   str is assumed to be pointing to a non-space character*/
char *word_end(char *str){
  
  //check if it doesnt contain any words
  printf("Local pointer address in word_end()> %p\n",&str);//prints *str address
  printf("Address that we are storing in pointer> %p\n",str);//prints contents of address we are storing
  printf("First value of the address we are storing> %c\n",*str);//prints pointers stored first address values
  printf("First values' address being stored from the word> %p\n", str);
  
  //iterate using the pointer to access next value
  int i;
  for(i=0 ; *(str+i) != '\0'; i++){
    printf("-Current address during iteration> %p\n",(str+i));
    //pass each char to sc()
    if( space_char(*(str+i)) == 1 ){
      printf("FIRST SPACE CHAR ENCOUNTERED AT> %p\n", (str+i));
	return (str+i);
    }
  }//for
  
  return '\0';
}//word_end()

/* Counts the number of space seperated words in the string argument. 

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
  
  printf("Substring size: %d\n",len);
  //Allocate fresh memory | (len+1) indicates the substring plus the '\0' at the end
  char *clone = malloc(sizeof(char) * (len+1));
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
  
  //Get number of words first
  int words = count_words(str);

  //Allocate memory for a pointer pointing to its pointers | the outter most '+1' is the zero terminator for the list of tokens instead of zeroterminator for word
  char **tokens = malloc( ((sizeof(char*) * (words + 1)) + 1);

  int i = 0;//index to navigate through memory
  int copied_words = 0; //keeps track if we copied all the words
  char *ptr = str; //pointer to navigate through values from passed 'str'
  
  while(copied_words != words){

    //if we start at a space | if not starting at space, ptr is already in right place
    if( space_char(*ptr) == 1  ){
      printf("AT A SPACE\n");
      //get the word starting from pt
      ptr = word_start(str);
    }
    char *ending_char = word_end(str);

    printf("start letter: %c\n", *ptr);
    printf("end letter: %c\n", *ending_char);
    
    while(1){
      //if we are at the end of the word or input
      printf("1\n");
      if( (*ptr == *ending_char) || (*ptr == '\0') ){
	printf("in if");
	//**(tokens + i) = '\0';
	copied_words++;
	printf("**BREAKING OUT**\n", copied_words );
	break;
      }
      else{
	printf("in else");
	**(tokens + i) = *ptr;
      }
      printf("2\n");
      ptr++;
      i++;
    }//inner while
    printf("3\n");
  }//outter while

  //Set the last value in the pointer of pointers to the zero terminator
  **(tokens+words+1) = '\0';

  printf("Done tokenizing\n");


}//**tokenize()

/* Prints all tokens. */
void print_tokens(char **tokens){

  int i;
  for (i = 0; *(tokens+i) != '\0'; i++){
    printf("Token %d", i , ": %s\n", *(tokens+i));
  }//for
  
}//print_tokens()

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens){}//free_tokens()


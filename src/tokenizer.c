#include <stdio.h>

//symbolic constant
#define MAX 20
#define LIMIT 100
char arr[LIMIT];

void main(){
  /*
    First milestone - create a simple UI that takes in user input and shoots out 
    user input in same order
  */  
  char input[MAX];
  printf("* GREETINGS USER *\n");
  printf("> ");
  scanf("%s",input);
  printf("%s\n", input);
  
  /*
  //OSCARS WAY
  printf("> ");
  int i = 0;
    for(char input_char ; (input_char = getchar()) != '\n' && i < LIMIT;i++){
    arr[i] = input_char;
    //putchar(input_char);
  }
  printf("%s\n",arr);
  */
  
  /*
   TODO-  SPACE_CHAR AND NON_SPACE_CHAR
   */
 
}//main

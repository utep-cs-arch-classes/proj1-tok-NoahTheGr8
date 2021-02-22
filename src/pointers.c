#include <stdio.h>

int main(){
  char name = 'A';
  char *name_ptr = &name;

  //name address contents
  printf("A address> %p\n",&name);
  printf("A char value> %c\n",name);
  

  //name pointer address,contents, content value
  printf("ptr address> %p\n",&name_ptr);
  printf("ptr char value> %p\n",name_ptr);
  printf("ptr cont val> %c\n",*name_ptr);




  




  
    
}

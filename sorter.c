#define_GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main (){

  char * buffer;
  size_t buffSize = 64;

  getLine(&buffer, &buffSize, stdin);


  printf("Input was: %s", buffer);

  return 0;


}

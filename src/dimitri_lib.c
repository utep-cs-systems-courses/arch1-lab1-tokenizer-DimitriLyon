#include <stdio.h>
#include <stdlib.h>
#include "dimitri_lib.h"

int string_equals(char *str1, char *str2) {
  while(*str1 != 0 && *str2 != 0) {
    if(*str1 != *str2) {
      return 0;
    }
    str1++;
    str2++;
  }
  return *str1 == *str2;
}

//getchar can read the \n
char *get_userinput() {
  char *first = (char *) calloc(2, sizeof(char));
  char *second;
  //Size tracks number of bytes allocated for the array
  int size = 2;
  char c = getchar();
  first[0] = c;
  if(c == '\n') {
    return first;
  }
  while(c != '\n') {
    second = (char *)calloc(size + 1, sizeof(char));
    for(int i = 0; i < size; i++) {
      second[i] = first[i];
    }
    c = getchar();
    size++;
    second[size-2] = c;
    free(first);
    first = second;
  }
  //First is a char array that holds the entire string plus \n and a nul terminator.
  second = (char *) calloc(size-1, sizeof(char));
  for(int i = 0; i < size - 2; i++) {
    second[i] = first[i];
  }
  free(first);
  first = second;
  
  return first;
}
  


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len( char *source ){
  int counter = 0;
  char *cp = source;
  while(*cp){
    counter++;
    cp++;
  }
  return counter;
}
char * ncpy( char *dest, char *source, int n){
  int index = 0;
  while(n){
    dest[index] = source[index];
    n--;
    index++;
  }
  return dest;
}
char * cat( char *dest, char *source ){
  return 0;
}
int cmp( char *s1, char *s2 ){
  return 0;
}
char * chr( char *s, char c ){
  return 0;
}

int main(){
  char s1[100]="hello";
  char s2[200]="goodbye";

  printf("s1 length: %zu\n", strlen(s1));
  printf("s1 length: %i\n", len(s1));
  printf("s1 length: %zu\n", strlen(s2));
  printf("s1 length: %i\n", len(s2));

  //printf("s1 cpy: %s\n", strncpy(s2,s1,3)); //heldbye
  //printf("s1 cpy: %s\n", ncpy(s2,s1,3)); //heldbye
  //printf("s1 cpy: %s\n", strncpy(s1,s2,6)); //goodby
  //printf("s1 cpy: %s\n", ncpy(s1,s2,6)); //goodby
  
  return 0;
}

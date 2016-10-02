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
  char *start=dest;
  while(*source!=0){
    if(*dest==0){
      *dest=*source;
      *source++;
    }
    *(dest++);
  }
  return start;
}
int cmp( char *s1, char *s2 ){
  while( *s1 == *s2 ){
      *(s1++);
      *(s2++);
  }
  return *s1 - *s2;
}
char * chr( char *s, char c ){
  while(*s){
      if(*s == c){
          return s;
      }
      *s++;
  }
  return 0;
}

int main(){
  char s1[100]="hello";
  char s2[200]="goodbye";

  printf("s1 length: %zu\n", strlen(s1));
  printf("s1 length: %i\n", len(s1));
  printf("s2 length: %zu\n", strlen(s2));
  printf("s2 length: %i\n", len(s2));

  //printf("s1 cpy: %s\n", strncpy(s2,s1,3)); //heldbye
  //printf("s1 cpy: %s\n", ncpy(s2,s1,3)); //heldbye
  //printf("s1 cpy: %s\n", strncpy(s1,s2,6)); //goodby
  //printf("s1 cpy: %s\n", ncpy(s1,s2,6)); //goodby

  //printf("s1 cat: %s\n", strcat(s1,s2)); //hellogoodbye
  //printf("s1 cat: %s\n", cat(s1,s2)); //hellogoodbye
  //printf("s1 cat: %s\n", strcat(s2,s1)); //goodbyehello
  //printf("s1 cat: %s\n", cat(s2,s1)); //goodbyehello

  printf("s1(h) to s2(g): %i\n", strcmp(s1,s2)); //1
  printf("s1(g) to s2(h): %i\n", cmp(s1,s2)); //-1
  printf("s2(g) to s1(h): %i\n", strcmp(s2,s1)); //-1
  printf("s2(g) to s1(h): %i\n", cmp(s2,s1)); //-1

  printf("chr s1, l: %s\n", strchr(s1,'l')); //llo
  printf("chr s1, l: %s\n", chr(s1,'l')); //llo
  printf("chr s1, e: %s\n", strchr(s1,'e')); //ello
  printf("chr s1, e: %s\n", chr(s1,'e')); //ello
  printf("chr s2, d: %s\n", strchr(s2,'d')); //dbye
  printf("chr s2, d: %s\n", chr(s2,'d')); //dbye
  printf("chr s2, z: %s\n", strchr(s2,'z'));
  printf("chr s2, z: %s\n", strchr(s2,'z'));

  return 0;
}

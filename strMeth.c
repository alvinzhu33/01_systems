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
char * cpy( char *dest, char *source){
    char *start = dest;
    while(*source){
        *dest = *source;
        *dest++;
        *source++;
    }
    *dest = *source;
    return start;
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
char * ncat( char *dest, char *source , int n){
  char *start=dest;
  while(n){
    if(*dest==0){
      *dest=*source;
      *source++;
      n--;
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
int ncmp( char *s1, char *s2, int n){
    while( *s1 == *s2 ){
        *(s1++);
        *(s2++);
        n--;
        if(n==0){
            return 0;
        }
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
char * str( char *s, char *c){
    while(*s){
        if(*s == *c){
            char *startS = s;
            char *startC = c;
            while( *startS == *startC){
                *startS++;
                *startC++;
                if(*startC == 0){
                    return s;
                }
            }
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
  printf("s2 length: %i\n\n", len(s2));

  //printf("s1 copy to s2: %s\n", strcpy(s2, s1)); //hello
  //printf("s1 copy to s2: %s\n", cpy(s2, s1)); //hello
  //printf("s2 cpy to s1: %s\n", strcpy(s1,s2)); //goodbye
  //printf("s2 cpy to s1: %s\n", cpy(s1,s2)); //goodbye

  //printf("s1 ncpy3 to s2: %s\n", strncpy(s2,s1,3)); //heldbye
  //printf("s1 ncpy3 to s2: %s\n", ncpy(s2,s1,3)); //heldbye
  //printf("s2 ncpy6 to s1: %s\n", strncpy(s1,s2,6)); //goodby
  //printf("s2 ncpy6 to s1: %s\n", ncpy(s1,s2,6)); //goodby

  //printf("s2 cat to s1: %s\n", strcat(s1,s2)); //hellogoodbye
  //printf("s2 cat to s1: %s\n", cat(s1,s2)); //hellogoodbye
  //printf("s1 cat to s2: %s\n", strcat(s2,s1)); //goodbyehello
  //printf("s1 cat to s2: %s\n", cat(s2,s1)); //goodbyehello

  //printf("s2 cat2 to s1: %s\n", strncat(s1,s2,2)); //hellogo
  //printf("s2 cat2 to s1: %s\n", ncat(s1,s2, 2)); //hellogo
  //printf("s1 cat4 to s2: %s\n", strncat(s2,s1,4)); //goodbyehell
  //printf("s1 cat4 to s2: %s\n\n", ncat(s2,s1,4)); //goodbyehell

  char n1[10]="grace";
  char n2[10]="gracious";
  printf("s1(h) to s2(g): %i\n", strcmp(s1,s2)); //1
  printf("s1(g) to s2(h): %i\n", cmp(s1,s2)); //-1
  printf("s2(g) to s1(h): %i\n", strcmp(s2,s1)); //-1
  printf("s2(g) to s1(h): %i\n", cmp(s2,s1)); //-1
  printf("grace to gracious: %i\n", strcmp(n1, n2)); //-4
  printf("grace to gracious: %i\n", cmp(n1, n2)); //-4
  printf("grace cmp4 gracious: %i\n", strncmp(n1, n2, 4)); //0
  printf("grace cmp4 gracious: %i\n", ncmp(n1, n2, 4)); //0
  printf("grace cmp5 gracious: %i\n", strncmp(n1, n2, 5)); //-4
  printf("grace cmp5 gracious: %i\n\n", ncmp(n1, n2, 5)); //-4

  printf("chr s1, l: %s\n", strchr(s1,'l')); //llo
  printf("chr s1, l: %s\n", chr(s1,'l')); //llo
  printf("chr s1, e: %s\n", strchr(s1,'e')); //ello
  printf("chr s1, e: %s\n", chr(s1,'e')); //ello
  printf("chr s2, d: %s\n", strchr(s2,'d')); //dbye
  printf("chr s2, d: %s\n", chr(s2,'d')); //dbye
  printf("chr s2, z: %s\n", strchr(s2,'z')); //null
  printf("chr s2, z: %s\n\n", strchr(s2,'z')); //null

  printf("str s1, el: %s\n", strstr(s1, "el")); //ello
  printf("str s1, el: %s\n", str(s1, "el")); //ello
  printf("str s1, el: %s\n", strstr(s1, "elo")); //null
  printf("str s1, el: %s\n", str(s1, "elo")); //null
  printf("str s2, goodb: %s\n", strstr(s2, "goodb")); //goodbye
  printf("str s2, goodb: %s\n", str(s2, "goodb")); //goodbye
  printf("str s2, db: %s\n", strstr(s2, "db")); //dbye
  printf("str s2, db: %s\n", str(s2, "db")); //dbye
  printf("str s2, e: %s\n", strstr(s2,"e")); //e
  printf("str s2, e: %s\n", str(s2,"e")); //e
  printf("str s2, f: %s\n", strstr(s2,"f")); //null
  printf("str s2, f: %s\n", strstr(s2,"f")); //null

  return 0;
}

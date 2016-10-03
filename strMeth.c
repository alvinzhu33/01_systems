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
  char *start=dest;
  while(n){
    *dest = *source;
    *dest++;
    *source++;
    n--;
  }
  return start;
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
  while( *s1 == *s2 && *s1 ){
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
  char s1[50]="hello";
  printf("s1: %s\n", s1);
  char s2[100]="goodbye";
  printf("s2: %s\n\n", s2);

  printf("Length:\n");
  printf("s1 strlen: %zu\n", strlen(s1));
  printf("s1 len: %i\n", len(s1));
  printf("s2 strlen: %zu\n", strlen(s2));
  printf("s2 len: %i\n\n", len(s2));

  printf("Chr:\n");
  printf("strchr s1,'l': %s\n", strchr(s1,'l')); //llo
  printf("chr s1,'l': %s\n", chr(s1,'l')); //llo
  printf("strchr s1,'e': %s\n", strchr(s1,'e')); //ello
  printf("chr s1,'e': %s\n", chr(s1,'e')); //ello
  printf("strchr s2,'d': %s\n", strchr(s2,'d')); //dbye
  printf("chr s2,'d': %s\n", chr(s2,'d')); //dbye
  printf("strchr s2,'z': %s\n", strchr(s2,'z')); //null
  printf("chr s2,'z': %s\n\n", chr(s2,'z')); //null

  printf("Str:\n");
  printf("strstr s1,'el': %s\n", strstr(s1, "el")); //ello
  printf("str s1,'el': %s\n", str(s1, "el")); //ello
  printf("strstr s1,'el': %s\n", strstr(s1, "elo")); //null
  printf("str s1,'el': %s\n", str(s1, "elo")); //null
  printf("strstr s2,'goodb': %s\n", strstr(s2, "goodb")); //goodbye
  printf("str s2,'goodb': %s\n", str(s2, "goodb")); //goodbye
  printf("strstr s2,'db': %s\n", strstr(s2, "db")); //dbye
  printf("str s2,'db': %s\n", str(s2, "db")); //dbye
  printf("strstr s2,'e': %s\n", strstr(s2,"e")); //e
  printf("str s2,'e': %s\n", str(s2,"e")); //e
  printf("strstr s2,'f': %s\n", strstr(s2,"f")); //null
  printf("str s2,'f': %s\n\n", str(s2,"f")); //null

  printf("Cmp:\n");
  printf("s1(h) strcmp s2(g): %i\n", strcmp(s1,s2)); //1
  printf("s1(g) cmp s2(h): %i\n", cmp(s1,s2)); //-1
  printf("s2(g) strcmp s1(h): %i\n", strcmp(s2,s1)); //-1
  printf("s2(g) cmp s1(h): %i\n", cmp(s2,s1)); //-1
  char n1[10]="grace";
  char n2[10]="gracious";
  printf("grace strcmp gracious: %i\n", strcmp(n1, n2)); //-4
  printf("grace cmp gracious: %i\n", cmp(n1, n2)); //-4
  printf("grace strncmp,4 gracious: %i\n", strncmp(n1, n2, 4)); //0
  printf("grace ncmp,4 gracious: %i\n", ncmp(n1, n2, 4)); //0
  printf("grace strncmp,5 gracious: %i\n", strncmp(n1, n2, 5)); //-4
  printf("grace ncmp,5 gracious: %i\n\n", ncmp(n1, n2, 5)); //-4

  char copy[100];
  char myCopy[100];
  printf("Cpy: \n");
  printf("s1 strcpy: %s\n", strcpy(copy, s1)); //hello
  printf("s1 cpy: %s\n", cpy(myCopy, s1)); //hello
  printf("copy: %s\n", copy);
  printf("myCopy:%s\n", myCopy);
  printf("s2 strcpy to s1: %s\n", strcpy(copy,s2)); //goodbye
  printf("s2 cpy to s1: %s\n", cpy(myCopy,s2)); //goodbye
  printf("copy: %s\n", copy);
  printf("myCopy: %s\n\n", myCopy);

  char a1[50]="hello";
  char a2[50]="goodbye";
  char mya1[50]="hello";
  char mya2[50]="goodbye";
  printf("nCpy: \n");
  printf("a1 strncpy3 to a2: %s\n", strncpy(a2,a1,3)); //heldbye
  printf("a2: %s\n", a2);
  printf("a2 strncpy6 to a1: %s\n", strncpy(a1,a2,6)); //heldby
  printf("a1: %s\n", a1);
  printf("mya1 ncpy3 to mya2: %s\n", ncpy(mya2,mya1,3)); //heldbye
  printf("mya2: %s\n", mya2);
  printf("mya2 ncpy6 to mya1: %s\n", ncpy(mya1,mya2,6)); //heldby
  printf("mya1: %s\n\n", mya1);

  char puddin[50]="Harley";
  char puddin2[50]=" Quinn";
  char mypuddin[50]="Harley";
  char mypuddin2[50]=" Quinn";
  printf("Cat: 'Harley' & ' Quinn'\n");
  printf("puddin2 strcat to puddin: %s\n", strcat(puddin,puddin2)); //Harley Quinn
  printf("puddin strcat to puddin2: %s\n", strcat(puddin2,puddin)); //QuinnHarley Quinn
  printf("mypuddin2 cat to mypuddin: %s\n", cat(mypuddin,mypuddin2)); //Harley Quinn
  printf("mypuddin cat to mypuddin2: %s\n\n", cat(mypuddin2,mypuddin)); //QuinnHarley Quinn

  char gang[50]="Gangnam";
  char sty[50]=" Style";
  char mygang[50]="Gangnam";
  char mysty[50]=" Style";
  printf("Cat: 'Gangnam' & ' Style'\n");
  printf("sty mycat2 to gang: %s\n", strncat(gang,sty,2)); //Gangnam S
  printf("Gangnam: %s\n", gang);
  printf("gang mycat4 to sty: %s\n", strncat(sty,gang,4)); //StyleGang
  printf(" Style: %s\n", sty);
  printf("mysty cat2 to mygang: %s\n", ncat(mygang,mysty, 2)); //Gangnam S
  printf("myGangnam: %s\n", mygang);
  printf("mygang cat4 to mysty: %s\n", ncat(mysty,mygang,4)); //StyleGang
  printf(" myStyle: %s\n", mysty);

  return 0;
}

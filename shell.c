#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[]) {
//test1 setup
  char* test1 = "ls -a";
  char* res1[3];
  res1[0] = "ls";
  res1[1] = "-a";
  res1[2] = "NULL";

  printf("Hello World\n");
  char cmd[500][50];
  int count = 0;
  int cmdPos = 0;
  for (int i = 0; i < strlen(test1); i++) {
    if(test1[i] == '&' && test1[i+1] == '&'){
      cmd[count][cmdPos++] = '/0';
      count++;
      i++;
    }
    else if(test1[i] != ' ')
      cmd[count][cmdPos++] = test1[i];
  }



  printf("Comparing now\n");
  printf("=========================\n" );

  for (size_t i = 0; i < count; i++) {
    printf("%s\n",cmd[i]);
  }

//test2 setup
/*
char* test2 = "echo Hello && echo Worl"
  char res2[2][3];
  res2[0][0] = "echo";
  res2[0][1] = "Hello";
  res2[0][2] = "NULL";

  res2[1][0] = "echo";
  res2[1][1] = "World";
  res2[1][2] = "NULL";
*/




}

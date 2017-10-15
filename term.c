#include "stdio.h"
#define MAX_LENGTH 1000
#define MAX_COMMANDS 100

char buffer[MAX_LENGTH];
char* commandBuffer[MAX_COMMANDS];


void split_commands();
void split_commands2();

int main(int argc, char const *argv[]) {

  for (size_t i = 0; i < MAX_COMMANDS; i++) {
    commandBuffer[i] = '/0';
  }
  scanf("%s\n",&buffer);
  split_commands2();

  int status;

  if (fork() == 0) {
    //child code
    printf("child code\n" );
    execvp(commandBuffer[0], commandBuffer);

  } else {
     wait(&status);
  }

  return 0;

}

void split_commands2(){
  int k = 0,i = 0;
  while (buffer[i] != '/0') {
    while (buffer[i] != ' ') {
      commandBuffer[k] = strcat(commandBuffer[k],buffer[i++]);
    }
    while (buffer[i++] == ' ') {
    }
    k++;
  }

}


void split_commands(){

  char delimiter[] = " ,.-";
  char *ptr;

  int k = 0;
  // initialisieren und ersten Abschnitt erstellen
  ptr = strtok(buffer, delimiter);

  while(ptr != NULL) {
    commandBuffer[k++] = ptr;
  	printf("%s\n", ptr);
   	ptr = strtok(NULL, delimiter);
  }
}

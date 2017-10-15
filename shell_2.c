#include <stdio.h>
#include <string.h>


#define true 1
#define false 0
int main(int argc, char const *argv[]) {
  char buffer[5000] ;
  scanf("%[^\n]%*c",&buffer );
  char cmd[50][50][50];

  int cmdPos = 0;
  int subCmdPos = 0;
  int index = 0;
  for (int i = 0; i < buffer[i] != '\0'; i++) {

    if(buffer[i] == '&' && buffer[i+1] == '&'){
      cmdPos++;
      subCmdPos = -1;
      index = 0;
      i++;
    }
    else if(buffer[i] != ' ' && buffer[i] != '\n'){
      cmd[cmdPos][subCmdPos][index++] = buffer[i];
      cmd[cmdPos][subCmdPos][index] = '\0';


      cmd[cmdPos][subCmdPos+1][0] = NULL;
    }
    else{
      index = 0;
      subCmdPos++;
    }
  }




    for (int i = 0; i <= cmdPos; i++) {
        /*for (int k = 0; cmd[i][k][0] != NULL; k++) {
          for (int l = 0; cmd[i][k][l] != '\0'; l++) {
            printf("%c\n",cmd[i][k][l] );
          }
          //printf("%s\n ",cmd[i][k]);
          printf("============0===============\n");
        }
        printf(">>>>>>>>>>>>>n>>>>>>>>>>>>>>\n");
        */
        execvp(cmd[i][0], cmd[i]);
    }





}

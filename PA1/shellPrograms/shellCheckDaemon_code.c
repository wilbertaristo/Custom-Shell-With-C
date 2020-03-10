#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v grep > output.txt");

   // TODO: Execute the command using system(command) and check its return value
   int return_value = system(command);
   if (return_value == -1){
      fprintf(stderr, "System command failed"); 
      exit(1);
   }

   free(command);

   int live_daemons = 0;
   // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
   // 1. Open the file
   // 2. Fetch line by line using getline()
   // 3. Increase the daemon count whenever we encounter a line
   // 4. Close the file
   // 5. print your result

    FILE* floc = fopen("output.txt","r");
    if (floc == NULL){
        perror("failed to open file");
        exit(1);
    }
    printf("checked");
    int result;
    char* buffer;
    size_t buffersize = 50;
    buffer = (char*) malloc(sizeof(char) * buffersize);
    while(result != -1){
        result = getline(&buffer,&buffersize,floc);
        if(result != -1){
            live_daemons ++;
        }
    }
    fclose(floc);
    printf("This text file contains %d lines\n",live_daemons);

   if (live_daemons == 0){
      printf("No one daemon is alive right now\n");
      }
   else
   {
      printf("There are in total of %d live daemons \n", live_daemons);
   }


   // TODO: close any file pointers and free any statically allocated memory 
   free(buffer);
   return 1;
}


int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}
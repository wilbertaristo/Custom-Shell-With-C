#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{

    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    FILE* floc = fopen(args[1],"r");
    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    if (floc == NULL){
        perror("failed to open file");
        exit(1);
    }
    // 3. Read the file line by line by using getline(&buffer, &size, fp)
    int result;
    int count = 0;
    char* buffer;
    size_t buffersize = 50;
    printf("before wait");
    while(result != -1){
        result = getline(&buffer,&buffersize,floc);
        count ++;
        printf("%d",count);
    }
    fclose(floc);
    printf("%d",count);
    
    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
    // 6. Close the FILE*
    // 7. Print out how many lines are there in this particular filename
    // 8. Return 1, to exit program

    return 1;
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}
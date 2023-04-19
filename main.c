#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//including this file to get the implementation of optarg and optopt 
#include "getopt.c"

#define MAX_SIZE_PATH 256

void get_size(FILE *fp1, FILE *fp2, char *path_1, char *path_2){
    
    fseek(fp1, 0L, SEEK_END);
    int sz1 = ftell(fp1);
    rewind(fp1);

    fseek(fp2, 0L, SEEK_END);
    int sz2 = ftell(fp2);
    rewind(fp2);

    if (sz1 > sz2){
        printf("The sound content of %s has %d more bytes sound data than %s", path_1, sz1 - sz2, path_2);
    }
    else{
        printf("The sound content of %s has %d more bytes sound data than %s", path_2, sz2 - sz1, path_1);
    }

}

int main(int argc, char *argv[]){
    // Get the options from the arguments
    int opt;
    int silent_flag = 0;
    char *value_opt = NULL;
    while((opt = getopt(argc, argv, "sn:")) != -1) 
    { 
        switch(opt) 
        { 
            case 's': 
                silent_flag = 1;
            case 'n': 
                value_opt = optarg; 
            case ':': 
                
                break; 
            case '?': 
                printf("unknown option: %c\n", optopt);
                break; 
        } 
    } 
    printf("%d", silent_flag);
    //Getting the paths for both files
    char path_1[MAX_SIZE_PATH];
    char path_2[MAX_SIZE_PATH];
    FILE *fp1;
    FILE *fp2;
    printf("Enter first path: ");
    gets(path_1);
    printf("Enter second path: ");
    gets(path_2);  

    //Opening files and checking if path's are correct
    fp1 = fopen(path_1, "r");
    if (fp1 == NULL){
        printf("Incorrect first file path!");
        exit(1);
    }

    fp2 = fopen(path_2, "r");
    if (fp2 == NULL){
        printf("Incorrect second file path!");
        exit(1);
    }
    
    get_size(fp1, fp2, path_1, path_2);

    return 0;
}
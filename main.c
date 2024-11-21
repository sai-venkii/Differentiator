#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Lines_Calc.h"
#include "htmlFix.h"
int i =0,j=0,k=0;
int main()
{
    FILE *file1,*file2,*file3;
    char path_file1[50],path_file2[50];
    char output_path[300]="Start chrome.exe \"",temp_oupt_path[100];
    char **file1_array,**file2_array;
    printf("Enter File 1 to be compared(full file path) : ");
    gets(path_file1);
    printf("Enter File 2 to be compared(full file path) : ");
    gets(path_file2);
    printf("Enter path where the output file should be stored: (use \\\\)");
    gets(temp_oupt_path);
    strcat(output_path,temp_oupt_path);
    strcat(output_path,"\\\\OUTPUT.html");
    while(strlen(path_file1)==0 || strlen(path_file2) == 0)
    {
            if(strlen(path_file1)==0)
            {
                printf("Enter Correct file path for file 1: ");
                gets(path_file1);
            }
            else if(strlen(path_file2)==0)
            {
                printf("Enter Correct file path for file 2: ");
                gets(path_file2);
            }
    }
    file1 = fopen(path_file1,"r");
    file2 = fopen(path_file2,"r");
    file3 = fopen("OUTPUT.html","w");
    fclose(file3); //Erase all the contents which were previously stored
    file3 = fopen("OUTPUT.html","w");
    int Lines_in_file1 = 0,Lines_in_file2 = 0;
    int previous_index=0;
    if(file1 == NULL)
    {
        printf("File 1 cannot be found");
        exit(1);
    }
    else if(file2 == NULL)
    {
        printf("File 2 cannot be found");
        exit(1);
    }
    else if(file3 == NULL)
    {
        printf("File 3 cannot be found");
        exit(1);
    }
    fprintf(file3,"<!DOCTYPE html><html><head><style>.file1 {background-color: #FF6D6A;}.file2 {background-color:#7FFF00;}</style></head><body><pre>\n"); //file 1: RED, file 2: Green
    fclose(file3);
    file3 = fopen("OUTPUT.html","a");
    Lines_in_file1 = Calculate_line(file1);
    Lines_in_file2 = Calculate_line(file2);
    file1_array = malloc(Lines_in_file1*sizeof(char *));
    file2_array = malloc(Lines_in_file2*sizeof(char *));
    if(file1_array == NULL || file2_array == NULL)
        printf("Memory error");
    for(i=0;i<Lines_in_file1;i++)
        file1_array[i]=malloc(100*sizeof(char));
    for(i=0;i<Lines_in_file2;i++)
        file2_array[i]=malloc(100*sizeof(char));
    rewind(file1);
    rewind(file2);
    symbol_correction(file1_array,file1);
    symbol_correction(file2_array,file2);
    bool hasMatch = false;
    for(i=0;i<Lines_in_file1;i++)
    {
        for(j=previous_index;j<Lines_in_file2;j++)
        {
            if(strcmp(file1_array[i],file2_array[j])==0)
            {
                hasMatch = true;
                if(j!=previous_index){
                        for(int n=previous_index; n<j ; n++)
                        {
                            fprintf(file3,"<div class='file2'>");
                            fputs(file2_array[n], file3);
                            fprintf(file3,"</div>");
                        }
                }
                fputs(file1_array[i], file3);
                fprintf(file3,"<br>");
                previous_index=j+1;
                break;
            }
        }

        if (hasMatch) {
            hasMatch = false;
        } else {
            fprintf(file3,"<div class='file1'>");
            fputs(file1_array[i], file3);
            fprintf(file3,"</div>");
        }
    }
    if(previous_index!=Lines_in_file2)
    {
        for(previous_index++;previous_index<Lines_in_file2;previous_index++)
        {
            fprintf(file3,"<div class='file2'>");
            fputs(file2_array[previous_index], file3);
            fprintf(file3,"</div>");
        }
    }
    fprintf(file3,"</pre></body></html>");
    for(i=0;i<Lines_in_file1;i++)
        free(file1_array[i]);
    for(i=0;i<Lines_in_file2;i++)
        free(file2_array[i]);
    free(file2_array);
    free(file1_array);
    printf("OUTPUT Window is opening!!!");
    system(output_path);
    fclose(file1);
    fclose(file2);
    fclose(file3);
    return 0;
}

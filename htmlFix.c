#include<stdio.h>
#include"htmlFix.h"
void symbol_correction(char **file_array,FILE *file)
{
    int i=0,j=0;
    char ch;
    for(j=0;!feof(file);j++)
    {
        ch = fgetc(file);
        if(ch == '\n')
        {
            file_array[i][j] = '\0';
            j=-1;
            i++;
        }
        else if(ch == '<')
        {
            file_array[i][j]='&';
            file_array[i][++j]='l';
            file_array[i][++j]='t';
        }
        else if(ch == '>')
        {
            file_array[i][j]='&';
            file_array[i][++j]='g';
            file_array[i][++j]='t';
        }
        else if(ch == EOF)
        {
            file_array[i][j] = '\0' ;
        }
        else
        {
            file_array[i][j]=ch;
        }
    }
}

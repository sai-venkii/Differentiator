#include<stdio.h>
#include"Lines_Calc.h"
int Calculate_line(FILE *file)
{
    char ch;
    int Total_lines=0;
    if(feof(file))
        printf("File Contains no lines");
    else{
        while(!feof(file))
        {
            ch = fgetc(file);
            if(ch == '\n')
            {
                Total_lines++;
            }
        }
        Total_lines++;
        return Total_lines;
    }
    rewind(file);
}

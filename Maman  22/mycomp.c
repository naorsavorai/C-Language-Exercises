#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "complex.h"
#define MAXIN 100

int main(){
    comp A,B,C,D,E,F;
    A = B = C = D = E = F = default_comp();
    comp*  pointers[6];
    pointers[0] = &A;
    pointers[1] = &B;
    pointers[2] = &C;
    pointers[3] = &D;
    pointers[4] = &E;
    pointers[5] = &F;
    read_input(pointers);

    return 0;
}

int is_command(char c)
{
    int res;
    if( c >= 'a' &&  c <= 'z' || c =='_')
    {
        res = 0;
    }
    else{
        res = 1;
    }
    return res;
}
int is_numeric(char c)
{
    int res;
    if (c >= '0' && c <= '9')
    {
        res = 0; 
    }
    else{
        res = 1;
    }
    return res;
}

int is_white(char c)
{
    int res;
    if(c == ' ' || c == '\t'){
        res = 0;
    }
    else{
        res = 1;
    }
    return res;
}
int valid_comp(char c)
{
    int res;
    if (c >= 'A' && c<= 'F'){
        res = 0;
    }
    else{
        res = 1;
    }
    return res;
}
int correct_pointer(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
        break;
    case 'B':
        return 1;
        break;
    case 'C':
        return 2;
        break;
    case 'D':
        return 3;
        break;
    case 'E':
        return 4;
        break;
    case 'F':
        return 5;
        break;                
    }
}

int use_command(char command[], char input[], int index)
{
    int res;
    if(strcmp(command))
    return res;
}






void read_input(comp* pointer[])
{
    char user_input[MAXIN];
    char user_command[15];
    int i = 0;
    int j = 0;
    while(fgets(user_input,MAXIN,stdin))
    {
        while( is_white(user_input[i]) == 0)
        {
            i++;
        }
        if(is_command(user_input[i]) != 0){
            printf("Error: Input must start with a command");
            continue;
        }
        while(is_command(user_input[i] == 0))
        {
            if ( j >= 15){
                printf("Error: command is to long please check your typo or check what are the valid commands");
                break;
            }
            user_command[j++] = user_input[i++];
        }
        if(is_white(user_input[i]) != 0 ){
            printf("Error: After typing the command please indent the input with a blank space or a tab");
            continue;
        }
        i++;
        use_command(user_command, user_input, i);
    }
}



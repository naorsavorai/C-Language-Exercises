#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "complex.h"
#define MAXIN 100


void read_input(comp* pointer[]);
int main(){
    comp A,B,C,D,E,F;
    comp*  pointers[6];

    A = B = C = D = E = F = default_comp();
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

    if( (c >= 'a' &&  c <= 'z') || (c =='_'))
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
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    default   :
        return -1;                 
    }
}
void use_print_all(comp* pointers[])
{
        printf("A = ");
        print_comp(*pointers[0]);
        printf("\nB = ");
        print_comp(*pointers[1]);
        printf("\nC = ");
        print_comp(*pointers[2]);
        printf("\nD = ");
        print_comp(*pointers[3]);
        printf("\nE = ");
        print_comp(*pointers[4]);
        printf("\nF = ");
        print_comp(*pointers[5]);
        printf("\n");   
}
void use_print_commands()
{
        printf("List Of Valid Commands:\n");
        printf("1) read_comp complex(A-F), real(double), imaginary(double)  -  Intializes a wanted complex number \n");
        printf("2) print_comp complex(A-F)  -  Prints a wanted complex number\n");
        printf("3) add_comp complex1(A-F), complex2(A-F)  -  Adds 2 complex numbers\n");
        printf("4) sub_comp complex1(A-F), complex2(A-F)  -  Substract 2 complex numbers\n");
        printf("5) mult_comp_real complex(A-F), real(double)  -  Multiplys a complex number with a real number\n");
        printf("6) mult_comp_img complex(A-F), imaginary(double)  -  Multiplys a complex number with an imaginary number\n");
        printf("7) mult_comp_comp complex1(A-F), complex2(A-F)  -  Multiplys 2 complex numbers\n");
        printf("8) abs_comp complex(A-F)  -  Returns the  absolute value of a given complex number\n");
        printf("9) print_all(void)  -  Prints all saved complex numbers\n");
}
void use_read_comp(char input[],int* index,comp* pointers[]);
void use_print_comp(char input[],int* index,comp* pointers[]);
void use_add_comp(char input[],int* index,comp* pointers[]);
void use_sub_comp(char input[],int* index,comp* pointers[]);
void use_mult_comp_real(char input[],int* index,comp* pointers[]);
void use_mult_comp_img(char input[],int* index,comp* pointers[]);
void use_mult_comp_comp(char input[],int* index,comp* pointers[]);
void use_abs_comp(char input[],int* index,comp* pointers[]);

void use_command(char command[], char input[], int* index, comp* pointers[])
{
    if(strcmp(command,"read_comp") == 0){
        use_read_comp(input, index, pointers);
        return;
    }
    /*if(strcmp(command,"print_comp") == 0){
        use_print_comp(input, index, pointers);
        return;
    }
    if(strcmp(command,"add_comp") == 0){
        use_add_comp(input, index, pointers);
        return;  
    }
    if(strcmp(command,"sub_comp") == 0){
        use_sub_comp(input, index, pointers);
        return;
        
    }
    if(strcmp(command,"mult_comp_real") == 0){
        use_mult_comp_real(input, index, pointers);
        return;
        
    }
    if(strcmp(command,"mult_comp_img") == 0){
        use_mult_comp_img(input, index, pointers);
        return;
        
    }
    if(strcmp(command,"mult_comp_comp") == 0){
        use_mult_comp_comp(input, index, pointers);
        return;
        
    }
    if(strcmp(command,"abs_comp") == 0){
        use_abs_comp(input, index, pointers);
        return;
        
    }*/
    if(strcmp(command,"print_all") == 0){
       use_print_all(pointers);
       return;
    }
    if(strcmp(command,"print_commands") == 0){
        use_print_commands();
        return;
    }
    else{
        printf("Error: Unkonwn command please check your typo or check if you entered a valid command\n");
        printf("To show list of valid commands please enter 'print_commands'\n");
        return;
    }  
}

void read_input(comp* pointer[])
{
    char user_input[MAXIN];
    char user_command[15];
    int i = 0;
    int j = 0;
    int* index = &i;

    while(fgets(user_input,MAXIN,stdin))
    {
        while(is_white(user_input[i]) == 0)
        {
            i++;
        }
        if(is_command(user_input[i]) != 0){
            printf("Error: Input must start with a command\n");
            i = 0;
            continue;
        }

        while(is_command(user_input[i]) == 0)
        {
            if ( j >= 16){
                printf("Error: command is to long please check your typo or check what are the valid commands\n");
                printf("char =%c ,i = %d j = %d\n",user_input[i],i,j);
                break;
            }
            user_command[j++] = user_input[i++];
            
        }
        user_command[j] = '\0';
        use_command(user_command, user_input, index, pointer);
        printf("\n");
        i = 0;
        j = 0;
    }
}

int get_next_double(char input[],int* index)
{
    int res;

    while(is_numeric(input[*index]) != 0 && input[*index] != '\0' )
    {
        (*index)++;
    }
    if(input[*index] =='\0'){
        res = 1;
    }
    else{
        res = 0;
    }
    return res;
}
int read_double(char double1[], char input[],int* index)
{
    int j = 0;
    int counter = 0;
    while((is_numeric(input[*index]) == 0 || input[*index] =='.' ) && counter <= 1)
    {   
        if(input[*index] == '.'){
            counter++;
        }
        double1[j++] = input[(*index)++]; 
    }
    if (counter > 1)
    {
        return 1;
    }
    double1[j] = '\0';
    return 0;
    
}

void use_read_comp(char input[], int* index,comp* pointers[])
{
    int comp_index, checker;
    double real, imaginary;
    char double1[MAXIN];
    char double2[MAXIN];
    comp* comp_pointer;
    char comp_var;

    if(valid_comp(input[*index]) != 0 )
    {
        (*index)++;
    }
    if (valid_comp(input[*index]) != 0)
    {
        printf("Error: Invalid input, after command please enter the wanted complex variable\n");
        return;
    }
    comp_var = input[*index];
    comp_index = correct_pointer(input[*index]);
    comp_pointer = pointers[comp_index];
    checker = get_next_double(input, index);
    if(checker != 0)
    {
        printf("Error: User did not enter enough double inputs");
        return;
    }
    checker = read_double(double1,input,index);
    if(checker != 0)
    {
        printf("Error: Real value was entered incorrectly, please check your typo\n");
        return;
    }
    real = atof(double1);
    checker = get_next_double(input,index);
    if(checker != 0)
    {
        printf("Error: User did not enter enough double inputs");
        return;
    }
    checker = read_double(double2,input,index);
    if(checker != 0)
    {
        printf("Error: Imaginary value was entered incorrectly, please check your typo\n");
        return;
    }
    imaginary = atof(double2);
    printf("real =  %f, imaginary = %f\n",real, imaginary);
    read_comp(comp_pointer, real, imaginary);
    printf("%c = ",comp_var);
    print_comp(*comp_pointer);
    printf("\n");
}



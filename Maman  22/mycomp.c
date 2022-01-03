#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "complex.h"
#define MAXIN 100



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

    if ((c >= '0' && c <= '9') || c == '-')
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


int use_command(char command[], char input[], int* index, comp* pointers[])
{
    if(strcmp(command,"read_comp") == 0){
        use_read_comp(input, index, pointers);
        return 0;
    }
    if(strcmp(command,"print_comp") == 0){
        use_print_comp(input, index, pointers);
        return 0;
    }
    
    if(strcmp(command,"add_comp") == 0){
        use_add_comp(input, index, pointers);
        return 0;  
    }
    
    if(strcmp(command,"sub_comp") == 0){
        use_sub_comp(input, index, pointers);
        return 0;
        
    }
    
    if(strcmp(command,"mult_comp_real") == 0){
        use_mult_comp_real(input, index, pointers);
        return 0;
        
    }
    
    if(strcmp(command,"mult_comp_img") == 0){
        use_mult_comp_img(input, index, pointers);
        return 0;
        
    }
    if(strcmp(command,"mult_comp_comp") == 0){
        use_mult_comp_comp(input, index, pointers);
        return 0;
        
    }
    if(strcmp(command,"abs_comp") == 0){
        use_abs_comp(input, index, pointers);
        return 0;
        
    }
    if(strcmp(command,"print_all") == 0){
       use_print_all(pointers);
       return 0;
    }
    if(strcmp(command,"help") == 0){
        use_help();
        return 0;
    }
    if(strcmp(command,"stop") == 0){
        return 1;
        
    }
    else{
        printf("Error: Unkonwn command please check your typo or check if you entered a valid command\n");
        printf("To show list of valid commands please enter 'help'\n");
        return 0;
    }  
}

void read_input(comp* pointer[])
{
    char user_input[MAXIN];
    char user_command[15];
    int checker;
    int i = 0;
    int j = 0;
    int* index = &i;

    printf("This is a basic complex number calculator, for all valid commands enter 'help'\n");
    printf("Please enter a command:\n");
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
        checker = use_command(user_command, user_input, index, pointer);
        if (checker == 1){
            break;
        }
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

int get_comp_var(char input[], int* index)
{   
    while(valid_comp(input[*index]) != 0 && input[*index] != '\0')
    {
        (*index)++;
    }
    if(input[*index] =='\0')
    {
        return 1;
    }
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
        printf("Error: Invalid input, after command please enter the wanted complex variable (A-F)\n");
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
    read_comp(comp_pointer, real, imaginary);
    printf("%c <=== ",comp_var);
    print_comp(*comp_pointer);
    printf("\n");
}
void use_print_comp(char input[],int* index,comp* pointers[])
{
    int checker;
    char var;
    comp* comp1;

    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, after command please enter the wanted complex variable (A-F)");
        return;
    }
    var = input[*index];
    comp1 = pointers[correct_pointer(var)];
    printf("%c = ",var);
    print_comp(*comp1);
    printf("\n");
}
void use_add_comp(char input[],int* index,comp* pointers[])
{
    int checker;
    char var1 ,var2;
    comp* comp1;
    comp* comp2;
    comp res;

    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, after command please enter the wanted complex variable (A-F)");
        return;
    }
    var1 = input[*index];
    comp1 = pointers[correct_pointer(var1)];
    (*index)++;
    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, please enter 2 complex variables\n");
        return;
    }
    var2 = input[*index];
    comp2 = pointers[correct_pointer(var2)];
    
    res = add_comp(*comp1, *comp2);
    printf("%c + %c = ",var1, var2);
    print_comp(res);
    printf("\n");
}

void use_sub_comp(char input[],int* index,comp* pointers[])
{
    int checker;
    char var1 ,var2;
    comp* comp1;
    comp* comp2;
    comp res;

    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, after command please enter the wanted complex variable (A-F)");
        return;
    }
    var1 = input[*index];
    comp1 = pointers[correct_pointer(var1)];
    (*index)++;
    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, please enter 2 complex variables\n");
        return;
    }
    var2 = input[*index];
    comp2 = pointers[correct_pointer(var2)];
    
    res = sub_comp(*comp1, *comp2);
    printf("%c - %c = ",var1, var2);
    print_comp(res);
    printf("\n");
}
void use_mult_comp_comp(char input[],int* index,comp* pointers[])
{
    int checker;
    char var1 ,var2;
    comp* comp1;
    comp* comp2;
    comp res;

    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, after command please enter the wanted complex variable (A-F)");
        return;
    }
    var1 = input[*index];
    comp1 = pointers[correct_pointer(var1)];
    (*index)++;
    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, please enter 2 complex variables\n");
        return;
    }
    var2 = input[*index];
    comp2 = pointers[correct_pointer(var2)];
    
    res = mult_comp_comp(*comp1, *comp2);
    printf("%c * %c = ",var1, var2);
    print_comp(res);
    printf("\n");
}

void use_abs_comp(char input[],int* index,comp* pointers[])
{
    int checker;
    char var;
    comp* comp1;
    double res;

    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, after command please enter the wanted complex variable (A-F)");
        return;
    }
    var = input[*index];
    comp1 = pointers[correct_pointer(var)];
    res = abs_comp(*comp1);
    printf("|%c| = %f\n",var, res);
}

void use_mult_comp_real(char input[],int* index,comp* pointers[])
{
    int checker;
    char var;
    comp* comp1;
    double real;
    char double1[MAXIN];
    comp res;

    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, after command please enter the wanted complex variable (A-F)");
        return;
    }
    var = input[*index];
    comp1 = pointers[correct_pointer(var)];

    checker = get_next_double(input, index);
    if(checker != 0)
    {
        printf("Error: User did not enter enough double inputs");
        return;
    }

    checker = read_double(double1, input,index);
    if(checker != 0)
    {
        printf("Error: Real value was entered incorrectly, please check your typo\n");
        return;
    }
    real = atof(double1);
    res = mult_comp_real(*comp1, real);
    printf("%f * %c = ",real ,var);
    print_comp(res);
    printf("\n");
}

void use_mult_comp_img(char input[],int* index,comp* pointers[])
{
    int checker;
    char var;
    comp* comp1;
    img imaginary;
    char double1[MAXIN];
    comp res;

    checker = get_comp_var(input, index);
    if(checker == 1){
        printf("Error: Invalid input, after command please enter the wanted complex variable (A-F)");
        return;
    }
    var = input[*index];
    comp1 = pointers[correct_pointer(var)];

    checker = get_next_double(input, index);
    if(checker != 0)
    {
        printf("Error: User did not enter enough double inputs");
        return;
    }

    checker = read_double(double1, input,index);
    if(checker != 0)
    {
        printf("Error: Real value was entered incorrectly, please check your typo\n");
        return;
    }
    imaginary.im = atof(double1);
    res = mult_comp_img(*comp1, imaginary);
    printf("%fi * %c = ",imaginary.im ,var);
    print_comp(res);
    printf("\n");
}

void use_help()
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
        printf("10) stop(void)  -  Stops the program\n");
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




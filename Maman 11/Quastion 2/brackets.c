#include <stdio.h>
#define MAXIN 101
#define INSIDE 1
#define OUTSIDE 0

int validLine(char str[],int i, int q);
int endLine(char brack[], int i);
int getEndOfLine(char str[], int i);


int main()
{    
    char str[MAXIN];
    int i ,res;
    i = 0;

    printf("Please enter a text or a text file:\n");
    fgets(str,MAXIN,stdin);

    printf("\n*********************************************************\n");
    res = validLine(str,i, 1);
    if (res > 0 ) {
        printf("text is invalid\n");
    }
    else {
        printf("text is valid\n");
    }
    return 0 ;

    
}  

int endLine(char brack[], int i)
{
    if (brack[0] == 'N'){
        printf("Line %d is valid\n", i);
        return 0;
    }
    else{
        printf("Line %d is invalid\n", i);
        return 1;   
    }
}  
char open( char c)
{
    if (c == '}'){
        return '{';
    }
    else if (c == ')'){
        return '(';
    }
    else if (c == ']'){
        return'[';
    }
    else {
        return '-1';
    }
  
}

int getEndOfLine(char str[], int i)
{
    int k;
    for (k = i ; (str[k] != '\n') && (str[k] != '\0'); ++k){
    }
    return k;
} 

int validLine(char str[], int i, int q)
{
    int k, j;
    int state, counter;
    char brack[MAXIN];
    
    state = OUTSIDE; 
    j = 0;
    counter = 0 ; 
    brack[0] = 'N';
    	
    for (k = i; (str[k] != '\0') && (str[k] != '\n') ; ++k)
    {
        if ((str[k] == '{' || str[k] == '[' || str[k] == '(') && (state == OUTSIDE)){
            brack[j] = str[i];
            ++j;
            continue;
        }
        if ((str[i] == '"') && (state == OUTSIDE)){
            state = INSIDE;
            brack[j] =str[i];
            ++j;
            continue;
        }
        if ((i > 0) && (str[i-1] == '/') && (str[i] == '*') && ( state == OUTSIDE )){
            state = INSIDE;
            brack[j] = str[i];
            ++j;
            continue;
        }
        if ((str[i] == '"' ) && (state == INSIDE) && (brack[j-1] == '"')){
            state = OUTSIDE;
            --j;
            brack[j] = 'N';
            continue;
            
        }
        if ( (i > 0) && (str[k] == '/') && (str[k-1] == '*') && (state == INSIDE) && (brack[k-1] == '*' )){
            --j;
            brack[j] = 'N';
            state = OUTSIDE;
            continue;
        }
        if (((str[k] == '}') || (str[k] == ']') || (str[k] == ')')) && (state == OUTSIDE)){
             char op;
             
             op = open(str[k]);
             if (brack[j-1] == op){
                 --j;
                 brack[j] = 'N';
                 continue;
             }
             else {
                 printf("incorrect\n");
                 printf("Line %d is unvalid\n", q);
                 k = getEndOfLine(str, k);
                 return 1 + validLine(str, k+1, q+1);
             }
        }          
    }
    if (str[i] == '\0'){
        return endLine(brack, q);
    }
    else{ 
        return endLine(brack, q) + validLine(str, k+1, q+1);
    }
    
}

int isSpecial(char str[], int i, char specialStack[], int j )
{
    int k;
    int count;
    int op;

    count = 0;

    for (k = i; str[k] != '\n' && str[k] != '\0'; ++k){
        if (str[k] != '}' && str[k] != '{'){
            return 1;
        }
        else if ((str[k] == '{' || str[k] =='}') && (count == 0)){
            specialStack[j] = str[k];
            ++j;
            ++count;
        }
        else if ((str[k] == '{' || str[k] == '}') && (count > 0) ){
            --j;
            specialStack[j] = 'N';
            return 1;
        }
    }
    if (count == 1){
        op = open(isSpecial[j-1]);
        if (op == isSpecial[j-2]){
            --j;
            isSpecial[j] = 'N';
            --j;
            isSpecial[j] = 'N';
        }
    return 0;   
    }
    

}





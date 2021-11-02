#include <stdio.h>
#define MAXIN 101
#define INSIDE 1
#define OUTSIDE 0

int validLine(char str[],int i, int q , char specialStack[], int j);
int endLine(char brack[], int i);
int getEndOfLine(char str[], int i);
int stackChecker(char specialStack[]);


int main()
{    
    char str[MAXIN];
    char specialStack[MAXIN];
    int i ,j;
    int res1, res2;

    i = 0;
    j = 0;
    specialStack[0] = 'N';

    printf("Please enter a text or a text file:\n");
    fgets(str,MAXIN,stdin);

    printf("\n*********************************************************\n");
    res1 = validLine(str,i, 1, specialStack, j);
    res2 = stackChecker(specialStack);
    printf("res1 = %d\n", res1);
    printf("res2 = %d\n", res2);
    if (res1 +res2 > 0 ) {
        printf("text is invalid\n");
    }
    else {
        printf("text is valid\n");
    }
    return 0 ;

    
}  

int stackChecker(char specialStack[]){
    if (specialStack[0] == 'N'){
        return 0;
    }
    else{
        return 1;
    }

}
int endLineCheck(char brack[], int i)
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
    else{
        return 'n';
    }
}

int getEndOfLine(char str[], int i)
{
    int k;
    for (k = i ; (str[k] != '\n') && (str[k] != '\0'); ++k){
    }
    return k;
} 
int isSpecial(char str[], int i, char specialStack[], int j);

int validLine(char str[], int i, int q, char specialStack[], int j)
{
    int k, r;
    int state;
    char brack[MAXIN];
    
    state = OUTSIDE; 
    r = 0; 
    brack[0] = 'N';

    if (isSpecial(str, i, specialStack, j) == 0){
        printf("line %d is special\n", q);
        k = getEndOfLine(str, i);
        return validLine(str, k+1, q+1, specialStack, j);
    }
    	
    for (k = i; (str[k] != '\0') && (str[k] != '\n') ; ++k)
    {
        if ((str[k] == '{' || str[k] == '[' || str[k] == '(') && (state == OUTSIDE)){
            brack[r] = str[k];
            ++r;
            continue;
        }
        if ((str[i] == '"') && (state == OUTSIDE)){
            state = INSIDE;
            brack[r] =str[i];
            ++r;
            continue;
        }
        if ((i > 0) && (str[i-1] == '/') && (str[i] == '*') && ( state == OUTSIDE )){
            state = INSIDE;
            brack[r] = str[k];
            ++r;
            continue;
        }
        if ((str[i] == '"' ) && (state == INSIDE) && (brack[j-1] == '"')){
            state = OUTSIDE;
            --r;
            brack[r] = 'N';
            continue;
            
        }
        if ( (i > 0) && (str[k] == '/') && (str[k-1] == '*') && (state == INSIDE) && (brack[k-1] == '*' )){
            --r;
            brack[r] = 'N';
            state = OUTSIDE;
            continue;
        }
        if (((str[k] == '}') || (str[k] == ']') || (str[k] == ')')) && (state == OUTSIDE)){
             char op;
             
             op = open(str[k]);

             if (brack[r-1] == op){
                 --r;
                 brack[r] = 'N';
                 continue;
             }
             else {
                 printf("Line %d is invalid\n", q);
                 k = getEndOfLine(str, k);
                 return 1 + validLine(str, k+1, q+1, specialStack, j);
             }
        }          
    }
    printf("str[k] is %c\n",str[k]);
    if (str[k] == '\0'){
        printf("you are in 0\n");
        return endLineCheck(brack, q);
    }
    else if (str[k] == '\n'){
        printf("you are in n\n");
        return endLineCheck(brack, q) + validLine(str, k+1, q+1,specialStack, j);
    }
    else {
        printf("you are wrong\n");
        return 12;
    }
}

int isSpecial(char str[], int i, char specialStack[], int j)
{
    int k;
    int count;
    char op;

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
        op = open(specialStack[j-1]);
        if (op == specialStack[j-2]){
            --j;
            specialStack[j] = 'N';
            --j;
            specialStack[j] = 'N';
        }
    return 0;   
    }
    else{
        return 1;
    }

}





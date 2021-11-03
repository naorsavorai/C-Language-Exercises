#include <stdio.h>
#define MAXIN 101
#define INSIDE 1
#define OUTSIDE 0

int validLine(char str[],int i, int q , char specialStack[]);
int endLine(char brack[], int i);
int getEndOfLine(char str[], int i);
int stackChecker(char specialStack[]);

int j = 0;
int main()
{    
    char str[MAXIN];
    char stack[MAXIN];
    int  q;
    int res1, res2;
    
    q = 1;
    stack[0] = 'N';
    res1 = 0;
    res2 = 0;

 printf("Please enter a text or a text file:\n");
    while(fgets(str,MAXIN,stdin)){
        printf("Line %d is: %s",q ,str);
        res1 =  res1 + validLine(str,0, q, stack); 
        ++q;
    }
    res2 = stackChecker(stack);
    printf("res1 is: %d\n",res1 );
    printf("res2 is: %d\n",res2 );
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
int isSpecial(char str[], int i, char specialStack[]);

int validLine(char str[], int i, int q, char specialStack[])
{
    int k, r;
    int state;
    char brack[MAXIN];
    
    state = OUTSIDE; 
    r = 0; 
    brack[0] = 'N';

    if (isSpecial(str, i, specialStack) == 0){
        printf("line %d is special\n", q);
        k = getEndOfLine(str, i);
        return 0;
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
                 return 1 ;
             }
        }          
    }
    if (str[k] == '\0'  || str[k] == '\n'){
        return endLineCheck(brack, q);
    }
    else {
    
        return 0;
    }
}

int isSpecial(char str[], int i, char specialStack[])
{
    int k;
    int count;
    char op;

    count = 0;
    
    for (k = i; str[k] != '\n' && str[k] != '\0'; ++k){
        if ((str[k] != '}' && str[k] != '{') || (count >= 1 && str[k] != ' ')){
            return 1;
        }
        else if ((str[k] == '{' || str[k] =='}') && (count == 0)){
            specialStack[j] = str[k];
            ++j;
            ++count;
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


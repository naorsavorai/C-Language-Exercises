#include <stdio.h>


int usersInput(int str[],int num);
int getUserN();

int main()
{
    int n;
    n = getUserN();
    int usrInp[n*n];
    usersInput(usrInp, n);
    return 0;
}


int getUserN()
{
    int n;
    printf("Please Enter The Number Of Rows And coloums of the matrix:\n");
    scanf("%d", &n);
    return n;
}

void printMat(int str[],int num)
{
    int i = 0;
    while (i < num*num)
    {
        if ((i+1)% num == 0){
            printf("%d\n", str[i++]);
        }
        else{
            printf("%d  ",str[i++]);
        } 
    }
}
int checkDiag(int str[], int num, int wantedSum)
{
    int i = 0;
    int j = num-1; 
    int posDiag = 0;
    int negDiag = 0;
    while (i < num*num )
    {
        posDiag += str[i];
        negDiag += str[j];
        i += num + 1;
        j += num - 1;
    }
    if (posDiag == negDiag && posDiag == wantedSum){
        return 0;
    }
    else{
        return 1;
    }
}
int checkCols(int array[], int num, int wantedSum)
{
    int j = 0;
    int i = 1;
    int curSum = 0;
    int lastSum;
    while (j < num*num && i < num +1)
    {
        
        if (j > num*num-1 - num &&  j < num*num ){
            if (j == num*num - num){
                lastSum = curSum +array[j];
                curSum = 0;
            }
            else{
                if(curSum + array[j] == lastSum){
                    curSum = 0;
                } 
                else{
                    return 1;
                }
            }
            j = i;
            i += 1;
        

        }
        else{
            curSum += array[j];
            j += num;  
        }
    } 
    if (lastSum == wantedSum){
        return 0;
    }
    else{
        return 1;
    }
}

int isMagic(int str[], int num)
{
    int i, lastSum ;
    int curSum = 0;
    i = 0;
    while  (i < num*num)
    {
        if((i+1)%num == 0){
            if (i+1 == num){
                lastSum = curSum + str[i++];
                curSum = 0;
            }
            else{
                if (curSum + str[i++] == lastSum){
                    curSum = 0;
                }
                else{
                    return 1;
                }
            }
        }
        else{
            curSum += str[i++];
        }
    }
    return 0  + checkDiag(str, num, lastSum)+ checkCols(str, num, lastSum);
}

int usersInput(int str[], int num)
{
    int i = 0;
    int lastNum = 0;
    int insert = 1;
    int isNeg = 1;
    int res;
    int insertCount = 0;
    char c;
    printf("Please Enter An %d*%d Matrix:\n", num, num);
    while ((c = getchar()) != EOF)
    {
    
        if ((c >= '0') && (c <= '9')){
            lastNum = (c-'0') + lastNum*10;
            insert = 0; 
        }
        else{
            if (insert == 0 ){
                str[i++] = lastNum*isNeg;
                lastNum = 0;
                insert = 1;
                isNeg = 1;
                insertCount+=1;
            }
            if (c == '-'){
                isNeg = -1;
            }            
        }
    }
    str[i] = -1;
    if (insertCount < num*num-1)
    {
        printf("Error: The User Did Not Enter Enough Integers\n");
        return 1;
    }
    printf("*****************************************************************************************************\n");
    printf("Your Matrix Is:\n");
    printMat(str,num);
    res = isMagic(str,num);
    if (res >= 1){
        printf("The Matrix Is Not Magic\n");
        return 1;
    }
    else{
        printf("The Matrix Is Magic!\n");
        return 0;
    }       
}


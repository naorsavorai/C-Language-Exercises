#include <stdio.h>
#include <stdlib.h>


int seekN(int num, char *args[]);

int main(int argc , char* argv[])
{   
    
   return seekN(argc,argv);
     
}

int seekN(int num, char *args[])
{
    int ex = 0;
    char res;
    int i;
    int n;
    FILE * fb; 
    if (num < 2){
        printf("Error: Progrem exepts at least 2 arguments, an integer and at least one file name\n");
        ex = 1;
    }
    if (atoi(args[1]) == 0){
        printf("Error: The first argument that the progrem expects is an integer\n");
        ex = 2;
    }
    if (ex != 0 ){
        return ex;
    }
    n = atoi(args[1]);
    for(i = 2; i < num; i++)
    {
        if( !(fb = fopen(args[i],"r")) )
        {
            printf("Could Not open file %s\n",args[i]);
            continue;
        }
        else{
             ex = fseek(fb,n-1,SEEK_SET);
             if (ex != 0){
                 printf("Error: Error seeking the wanted character in file %s", args[i]);
                 continue;
             }
             else{
                 res = fgetc(fb);
                 if (res == EOF ){
                     printf("Error: file %s is shorter than %d\n",args[i], n);
                     continue;
                 }

                 printf("The asci code of the %dnd character of file:\"%s\" is %d\n",n,args[i],res);
             }
        }
        fclose(fb);
    }
    return 0;

}
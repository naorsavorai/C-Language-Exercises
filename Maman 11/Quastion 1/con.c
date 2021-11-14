#include <stdio.h> 

#define MAXIN 81 /*maximum length of text input */
#define IN 1 /*if inside a sequance*/
#define OUT 0 /*if outside a sequance*/

 void contract (char in[], char out[]);
 

int main()
{
    char str[MAXIN];
    char res[MAXIN];

    printf("Please enter a text or a text file:\n");
    fgets(str,81,stdin);
    contract(str, res);
    printf("*********************************************************\n");
    printf("The Original Text:\n");
    printf("%s\n", str);
    printf("Modified Text:\n");
    printf("%s\n", res);
    return 0;
}



void contract (char in[], char out[])
{   
    int i ,j;
    int state ,last;

    state = OUT;
    j = 0;
   


    for(i = 0; in[i] != '\0' || in[i] == '\n'; ++i)
    {
        if (('0' <= in[i] && in[i] <= '9') || ('a' <= in[i] && in[i]<= 'z') || ('A' <= in[i] && in[i] <= 'Z')){
            if (state == OUT) {
                out[j] = in[i];
                state = IN;
                last = i;
                ++j;
            }
            else if ( in[i-1] +1 == in[i]){
                continue;
            }
            else {
                  if (i - last == 1 ){
                      out[j] = in[i];
                      ++j;
                      last = i;
                  }
                  else if (i - last ==2){
                      out[j] = in[i-1];
                      out[j+1] = in[i];
                      j = j + 2;
                      last = i;
                  }
                  else{
                      out[j] = '-';
                      out[j+1] = in[i-1];
                      out[j+2] = in[i];
                      last = i;
                      j = j + 3;
                  }
            } 
        }
        else{
            if (state == OUT){
                out[j] = in[i];
                ++j;
            }
            else {
                  if (i - last == 1 ){
                      out[j] = in[i];
                      ++j;
                      state = OUT;
                  }
                  else if (i - last ==2){
                      out[j] = in[i-1];
                      out[j+1] = in[i];
                      j = j + 2;
                      state = OUT;
                  }
                  else{
                      out[j] = '-';
                      out[j+1] = in[i-1];
                      out[j+2] = in[i];
                      j = j + 3;
                      state = OUT;
                  }
            }

        }

    }



      
}

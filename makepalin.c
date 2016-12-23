
#include <stdio.h>;

int main(){
    
    char in[41];
    printf("Please enter a string > ");
    fgets(in, 21, stdin);
    
    char palin[41];
    
    int ended = 0;
    int i = 0;
    int j = 0;
    for (i = 0; j >= 0; i++){
        if (in[j] == '\n'){
            ended = 1;
            j--;
        }
        if (!ended){
           palin[i] = in[j++];
        }
        if (ended){
            palin[i] = in[j--];
        }
    }
    
    palin[i] = '\0';
    
    printf("The palindrome is <%s>\n", palin);
    
    return 0;
    
}
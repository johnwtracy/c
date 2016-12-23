#include <stdio.h>

int main(){
    
    char in[200];
    
    printf("Please enter a line of text > ");
    fgets(in, 200, stdin);
    
    if (in[0] != ' ' && in[0] > 90)
        in[0] = in[0] - 32;
        
    int i = 0;
    for (i = 0 ; 1; i++){
        if (in[i] == '\0' || in[i + 1] == '\0')
            break;
        if (in[i] == ' ' && in[i + 1] > 90)
            in[i + 1] = in[i + 1] - 32;
    }

    printf("%s\n", in);
    
    return 0;
    
}
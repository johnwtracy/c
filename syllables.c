
#include <stdio.h>

int isVowel(char c) {

    switch (c) {
        case 'a':
            return 1;
        case 'e':
            return 1;
        case 'i':
            return 1;
        case 'o':
            return 1;
        case 'u':
            return 1;
        case 'y':
            return 1;
        case 'A':
            return 1;
        case 'E':
            return 1;
        case 'I':
            return 1;
        case 'O':
            return 1;
        case 'U':
            return 1;
        case 'Y':
            return 1;
        default:
            return 0;
    }

    return 0;

}

int main() {

    char in[19];

    printf("Please enter a string > ");
    scanf("%s", in);

    long count = 0;

    int i = 0;
    for (i = 0; 1; i++) {
        char a = in[i];
        if (a == '\0')
            break;
        if (isVowel(a))
            count++;
    }

    printf("The number of syllables is %ld\n", count);

    return (0);

}


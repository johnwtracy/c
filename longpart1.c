#include <stdio.h>
#include <string.h>
#include <math.h>

int findSum(char *a, char *b, char *c, int n, int p);

/* Checks if char *str is a number
 * RECURSIVE*/
int isDigit(char *str, int n) {
    if (n < 0) {
        return 1;
    }
    if ((str[n] > 57 || str[n] < 48) && str[n]) {
        return 0;
    } else {
        return isDigit(str, --n);
    }
}

/* Reverses char *s 
 * RECURSIVE*/
int reverseString(char *s, int n) {
    if (n >= strlen(s) / 2) {
        return 1;
    } else {
        char t = s[n];
        s[n] = s[strlen(s) - (n + 1)];
        s[strlen(s) - (n + 1)] = t;
        return reverseString(s, ++n);
    }
}

/* Adds the contents of the 2 string parameters*/
char *add2(char *str1, char *str2) {
    char sum[2001];
    findSum(sum, str1, str2, 0, 0);
    reverseString(sum, 0);
    return sum;
}

int fill(char *sum, char *left, int *carry, int *place, int i) {
    if (i < 0) {
        return 1;
    }
    int b = left[i] - 48;
    sum[(*place)++] = (b + *carry) % 10 + 48;
    *carry = (b + *carry > 9) ? (b + *carry) / 10 : 0;
    return fill(sum, left, carry, place, i - 1);
}

/* Keep in mind that after calling this function sum will have the
 correct digits in the reverse order
 * RECURSIVE*/
int findSum(char *sum, char *str1, char *str2, int carry, int place) {
    // declares helpful variables
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = len1 - place - 1;
    int j = len2 - place - 1;
    // checks if both of the strings are terminated
    if (i < 0 && j < 0) {
        if (carry)
            sum[place++] = carry + 48;
        sum[place] = '\0';
        return 1;
    }
    // checks if the first string is over
    if (i < 0) {
        // fills sum with the rest of the other string
        fill(sum, str2, &carry, &place, j);
        // places the final carry digit and a null char to end the string
        if (carry)
            sum[place++] = carry + 48;
        sum[place] = '\0';
        return 1;
    }
    // checks if the second string is over
    if (j < 0) {
        // fills sum with the rest of the other string
        fill(sum, str1, &carry, &place, i);
        // places the final carry digit and a null char to end the string
        if (carry)
            sum[place++] = carry + 48;
        sum[place] = '\0';
        return 1;
    }
    // the current digit in both of the strings
    int a = str1[i] - 48;
    int b = str2[j] - 48;
    // places a single digit in the current position
    sum[place] = (a + b + carry) % 10 + 48;
    // handles whether carry will have any value for the next iteration
    carry = (a + b + carry > 9) ? (a + b + carry) / 10 : 0;
    return findSum(sum, str1, str2, carry, ++place);

}

/* Recursive function which 
 * RECURSIVE*/
char *times(char *p, char *a, char n) {
    if (n == '1')
        return p;
    else {
        p = add2(p, a);
        return times(p, a, (char) (n - 1));
    }
}

/* Multiplies any number a by the single digit n*/
char *sMult(char *a, char n) {
    char *product = a;
    if (n == '0') {
        return "0\0";
    }
    product = times(product, a, n);
    product[strlen(product)] = '\0';
    return product;
}

/* Prints the single digit multiplication
 * RECURSIVE*/
int printTimes(char *a, int i) {
    if (i == 10)
        return 1;
    printf("%s times %d is %s\n", a, i, sMult(a, i + 48));
    return printTimes(a, i + 1);
}

int main() {
    // gets the two strings from user input
    char a[2000];
    char b[2000];
    printf("Enter first number > ");
    scanf("%s", a);
    if (!isDigit(a, strlen(a) - 1)) {
        printf("The number is invalid\n");
        return 0;
    }
    printf("Enter second number > ");
    scanf("%s", b);
    if (!isDigit(b, strlen(b) - 1)) {
        printf("The number is invalid\n");
        return 0;
    }
    // prints 
    printf("1st num is %s\n", a);
    printf("2nd num is %s\n", b);
    printf("The sum is %s\n", add2(a, b));
    printTimes(a, 2);
    return 0;

}

#include <stdio.h>
#include <string.h>

void ReverseString(char* str, int length);

int main() {
    char str[] = "Hello, World!";
    int length = strlen(str);

    ReverseString(str, length);
    printf("Reversed string: %s\n", str);

    return 0;
}

void ReverseString(char* str, int length) {
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;
        start++;
        end--;
    }
}
#include <stdio.h>

int Fibonacci(int n);

int main() {
   int n = 7;
   printf("Element in position %d in Fibonacci series is %d\n", n, Fibonacci(n));

   return 0;
}

int Fibonacci(int n) {
   if (n < 1) {
      printf("Invalid input\n");
      return -1;
   }

   if (n == 1) {
      return 0;
   }

   if (n == 2) {
      return 1;
   }

   return Fibonacci(n - 1) + Fibonacci(n - 2);
}

#include <stdio.h>
#include <stdbool.h>

bool IsPrime(int n);

int main() {
   int n = 13;

   if (IsPrime(n)) {
      printf("%d is a prime number.\n", n);
   } else {
      printf("%d is not a prime number.\n", n);
   }
}

bool IsPrime(int n) {
   if (n <= 1) {
      return false;
   }

   for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
         return false;
      }
   }

   return true;
}
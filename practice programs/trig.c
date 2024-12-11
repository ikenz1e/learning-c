#include <stdio.h>
#include <math.h>

int main(){

  double a;
  double b;
  double c;

  printf("enter side a:\n");
  scanf("%lf", &a);
  printf("enter side b:\n");
  scanf("%lf", &b);

  c = sqrt(pow(a, 2) + pow(b, 2));

  printf("c: %lf", c);

  return 0;
}
#include <stdio.h>
#include <math.h>

int main(){

  double radius;
  const double pi = 3.141592653589793;

  printf("enter the radius of the circle:\n");
  scanf("%lf", &radius);

  double circumference = 2 * radius * pi;
  double area = pi * pow(radius,2);
  printf("the circumference is: %lf\n", circumference);
  printf("the area is: %lf", area);

  return 0;
}
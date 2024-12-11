#include <stdio.h>

int main(){

  // int age;

  // printf("Enter your age: \n");
  // scanf("%d", &age);

  // if(age >= 18){
  //   printf("come over ;)\n");
  // }else{
  //   printf("nvm\n");
  // }

  char grade;

  printf("enter a grade: ");
  scanf("%c", &grade);

  switch(grade){
    case 'A':
      printf("you passed");
      break;
    case 'B':
      printf("you did decent");
      break;
    default:
      printf("you failed");
      break;
  }

}
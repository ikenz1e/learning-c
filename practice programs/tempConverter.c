#include <stdio.h>
#include <ctype.h>

int main(){


  char unit;
  float temp;

  printf("in F or C?\n");
  scanf("%c", &unit);

  if(toupper(unit) == 'C'){
    
  }else if(toupper(unit) == 'F'){

  }else{
    printf("that does not exist");
  }

  return 0;
}
#include <stdio.h>


void func()
{
    for (int i = 0; i < 10; ++i) {
        printf("%d", i);
    }
    printf("func!");
}

int main (int argc, char *argv[])
{
  int i, *p, count = 0;
  p = &count;

  for (i = 0; i < 10; i++) {
  	(*p)++;	//Do you understand this line of code and all the other permutations of the operators? ;)
  }


  func();


  printf("Thanks for waddling through this program. Have a nice day.\n");
  return 0;
}

#include <stdio.h>

int main(int argc, char *argv[]){

  double a, b, c[4];
  int size_world,rank_world;

  printf("input data(a,b)\n");
  scanf("%lf",&a);
  scanf("%lf",&b);

  c[0]=a+b;
  printf(" a+b=%lf\n",c[0]);

  c[1]=a-b;
  printf(" a-b=%lf\n",c[1]);

  c[2]=a*b;
  printf(" a*b=%lf\n",c[2]);

  c[3]=a/b;
  printf(" a/b=%lf\n",c[3]);

  return 0;
}

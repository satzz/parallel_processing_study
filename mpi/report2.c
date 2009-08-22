#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[]){

  double a, b, c;
  int size_world,rank_world;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank_world);
  MPI_Comm_size(MPI_COMM_WORLD, &size_world);

  if(rank_world == 0) {
    printf("input data(a,b)\n");
    scanf("%lf",&a);
    scanf("%lf",&b);
  }

  MPI_Bcast(&a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast(&b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  switch ( rank_world ) {
  case 0:
    c=a+b;
    printf(" a+b=%lf\n",c);
    break;
  case 1:
    c=a-b;
    printf(" a-b=%lf\n",c);
    break;
  case 2:
    c=a*b;
    printf(" a*b=%lf\n",c);
    break;
  case 3:
    c=a/b;
    printf(" a/b=%lf\n",c);
    break;
  }

  MPI_Finalize();

  return 0;
}

/*
RESULT
input data(a,b)
3 4
 a+b=7.000000
 a-b=-1.000000
 a*b=12.000000
 a/b=0.750000
*/



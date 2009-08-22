#include <stdio.h>
#include "mpi.h"

#define CNT   1
#define TAG_1 100
#define TAG_2 200
#define TAG_3 300

int main(int argc, char *argv[]){

  double a, b, c;
  int size_world,rank_world;
  double buf_recv[CNT], buf_send[CNT];
  double buf_reduce;

  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank_world);
  MPI_Comm_size(MPI_COMM_WORLD, &size_world);
  MPI_Status status;

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
    printf("rank0: %lf\n",c);

    MPI_Recv(buf_recv, CNT, MPI_DOUBLE, 1, TAG_1, MPI_COMM_WORLD, &status);
    printf("rank1: %lf\n", buf_recv[0]);
    MPI_Recv(buf_recv, CNT, MPI_DOUBLE, 2, TAG_2, MPI_COMM_WORLD, &status);
    printf("rank2: %lf\n", buf_recv[0]);
    MPI_Recv(buf_recv, CNT, MPI_DOUBLE, 3, TAG_3, MPI_COMM_WORLD, &status);
    printf("rank3: %lf\n", buf_recv[0]);

    break;
  case 1:
    c=a-b;
    MPI_Send(&c, CNT, MPI_DOUBLE, 0, TAG_1, MPI_COMM_WORLD);
    break;
  case 2:
    c=a*b;
    MPI_Send(&c, CNT, MPI_DOUBLE, 0, TAG_2, MPI_COMM_WORLD);
    break;
  case 3:
    c=a/b;
    MPI_Send(&c, CNT, MPI_DOUBLE, 0, TAG_3, MPI_COMM_WORLD);
    break;
  }

  MPI_Reduce(&c, &buf_reduce, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
  if(rank_world == 0) {  printf("max: %lf\n", buf_reduce); }
  MPI_Finalize();

  return 0;
}

/*
RESULT
input data(a,b)
3 4
rank0: 7.000000
rank1: -1.000000
rank2: 12.000000
rank3: 0.750000
max: 12.000000
*/

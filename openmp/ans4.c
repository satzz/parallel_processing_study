#include "omp.h"
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

main(){

  int split, i;
  double height, width, area, pai, time;
  struct timeval stp, etp;

  gettimeofday(&stp, NULL);

  area = 0;
  split = 20000000;
  width = 1.0 / (double)split;
#pragma omp parallel
{
#pragma omp for reduction(+:area) private(height)
  for(i=0; i<split; i++){
    height = sqrt(1.0 - pow((i * width), 2.0));
    area += height * width;
  }
}
  pai = 4.0 * area;
  printf("pai = %lf\n", pai);

 gettimeofday(&etp, NULL);
 time = (double)(etp.tv_usec - stp.tv_usec) / 1000000.0;
 time += (double)(etp.tv_sec - stp.tv_sec);
 printf("%lf sec\n", time);

}
/*
RESULT
pai = 3.141593
0.584702 sec
./ans4  2.31s user 0.01s system 364% cpu 0.637 total
*/

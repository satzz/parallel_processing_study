#include <stdio.h>
#include <math.h>
#define n 1000000

void main(){

  int i, arg[n];
  double average=0, variance=0, deviation=0;

#pragma omp parallel
  {
#pragma omp for reduction(+:average)
    for(i=0; i<n; i++){
      arg[i] = i;
      arg[i] = arg[i] % 101;
      average += arg[i];
    }

#pragma omp single
 {
    average /= (double)n;
 }
#pragma omp for reduction(+:variance)
    for(i=0; i<n; i++){
      variance += pow((arg[i] - average), 2);
    }

  }

  variance /= n;
  deviation = sqrt(variance);

  printf("%lf\n", deviation);
}

/*
RESULT
29.154731
./ans3  0.14s user 0.02s system 166% cpu 0.096 total
*/

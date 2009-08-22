#include <stdio.h>
#define n 500

main(){

  int i, j, k;
  double ary_1[n][n], ary_2[n][n], ary_r[n][n];
#pragma omp parallel
 {
#pragma omp for private(j)
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      ary_1[i][j] = (j - 1) * n + i;
      ary_2[i][j] = (i - 1) * n + j;
    }
  }

#pragma omp for private(j,k)
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      ary_r[i][j] = 0;
      for(k=0; k<n; k++)
	ary_r[i][j] = ary_1[i][k] * ary_2[k][j] + ary_r[i][j];
    }
  }
 }
}

/*
RESULT
./ans2  2.13s user 0.19s system 303% cpu 0.764 total
*/

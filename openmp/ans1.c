#include "omp.h"
#include <stdio.h>

main(){
# pragma omp parallel
  {
  printf("Thread id = %d\n", omp_get_thread_num());
  }
}

/*
RESULT
Thread id = 0
Thread id = 1
Thread id = 2
Thread id = 3
./ans1  0.00s user 0.00s system 0% cpu 0.135 total
*/

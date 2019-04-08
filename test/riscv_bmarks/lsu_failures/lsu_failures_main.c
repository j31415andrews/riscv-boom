
// See LICENSE for license details.

//**************************************************************************
// Vector-vector add benchmark
//--------------------------------------------------------------------------
//
// This benchmark uses adds to vectors and writes the results to a
// third vector. The input data (and reference data) should be
// generated using the vvadd_gendata.pl perl script and dumped
// to a file named dataset1.h.

#include "util.h"

//--------------------------------------------------------------------------
// lsu_failures function

void lsu_failures( /* args */ )
{
  // code
  int* arr[1005];
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    int k = i + ((i + 1) * (i + 1) - 1) % 3;
    int l = i + 100;
    int m = 12 * i;
    arr[i] = l;
    arr[k] = m;
    sum += arr[i];
  }
  printf("%d", sum);
}

//--------------------------------------------------------------------------
// Main

int main( int argc, char* argv[] )
{
  // Do the vvadd
  setStats(1);
  lsu_failures();
  setStats(0);

  // Check the results
  return 0;
}


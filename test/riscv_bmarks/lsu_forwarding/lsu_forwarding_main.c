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
// lsu_forwarding function

void lsu_forwarding( /* args */ )
{
  int sum = 0;
  int arr[5074];
  for (int i = 0; i < 5000; i++) {
    int x = 3 * i * i + 22 * i - 33;
    int j = i + (i % 74);
    arr[i] = x;
    arr[j] = 22 + j;
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
  lsu_forwarding();
  setStats(0);

  // Check the results
  return 0;
}

#include "header.h"

int   ia[64] ALIGNED16;

__attribute__((noinline))
void example21(int *input, int n) {
  int i, sub = 0;

  for (i = n-1; i >= 0; i--)
    sub -= input[i];

  input[0] = sub;
}


int main(int argc,char* argv[]){
  init_memory(&ia[0], &ia[64]);
  BENCH("Example21",  example21(ia, 64), Mi*4/64*512, digest_memory(&ia[0], &ia[64]));
  return 0;
}
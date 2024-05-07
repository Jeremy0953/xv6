#include "kernel/types.h"
#include "user.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(2,"usage: sleep <number>\n");
    exit(-1);
  } 
  int tick = atoi(argv[1]);
  sleep(tick);
  printf("(nothing happens for a little while)\n");
  exit(0);
}
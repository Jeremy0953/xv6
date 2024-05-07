#include "kernel/types.h"
#include "user.h"
#define N 256
int main(int argc, char *argv[]) {
  if (argc != 1) {
    fprintf(2, "usage: pingpong\n");
    exit(-1);
  } 
  int pipes_parent[2];
  int pipes_child[2];
  pipe(pipes_parent);
  pipe(pipes_child);
  int pid = fork();
  char buf_parent[N];
  char buf_child[N];

  if (pid == 0)
  {
    // child
    close(pipes_parent[1]);
    close(pipes_child[0]);
    read(pipes_parent[0], buf_parent, N);
    printf("%d: received %s\n", getpid(), buf_parent);
    write(pipes_child[1], "pong", 4);
    close(pipes_parent[0]);
    close(pipes_child[1]);
    exit(0);
  } else {
    // parent
    close(pipes_parent[0]);
    close(pipes_child[1]);
    write(pipes_parent[1], "ping", 4);
    read(pipes_child[0], buf_child, N);
    printf("%d: received %s\n", getpid(), buf_child);
    close(pipes_parent[1]);
    close(pipes_child[0]);
    exit(0);
  }
}
#include <sys/time.h>
#include <stdio.h>

int main(int ac, char **av) 
{
  struct timeval current_time;
  gettimeofday(&current_time, NULL);
  printf("seconds : %ld\nmicro seconds : %d\n", current_time.tv_sec, current_time.tv_usec);
  return 0;
}
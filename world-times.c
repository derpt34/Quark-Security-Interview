#include <time.h>
#include <stdio.h>

int main(void) {
  time_t curr_time = time(NULL);
  
  printf("Time in Washington DC: %s", ctime(&curr_time));
  curr_time -= (3600*3);
  
  printf("Time in San Francisco: %s", ctime(&curr_time));
  
  return 0;
}

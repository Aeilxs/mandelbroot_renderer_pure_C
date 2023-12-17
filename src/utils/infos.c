#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

void show_progress(int current, int max, bool last) {
  int percentage = (int)((float)current / max * 100);
  printf("\r%d/100%%", percentage);
  fflush(stdout);
  usleep(100);

  if (last)
    printf("\r100%% DONE\n");
}
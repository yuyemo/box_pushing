// timer.c
#include "timer.h"


static time_t start_time = 0;
static int step_count = 0;

void start_timer(void) {
    start_time = time(NULL);
}

int get_elapsed_time(void) {
    return (int)(time(NULL) - start_time);
}

void reset_step_count(void) {
    step_count = 0;
}

void increase_step_count(void) {
    step_count++;
}

void decrease_step_count(void) {
    step_count--;
}

int get_step_count(void) {
    return step_count;
}

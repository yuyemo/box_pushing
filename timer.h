// timer.h
#ifndef TIMER_H
#define TIMER_H

#include <time.h>


// 初始化计时器
void start_timer(void);

// 获取已用时间（单位：秒）
int get_elapsed_time(void);

// 步数统计接口
void reset_step_count(void);
void increase_step_count(void);
void decrease_step_count(void);
int get_step_count(void);

#endif

// undo.h
#ifndef UNDO_H
#define UNDO_H

#define MAX_SCALE 100
#define UNDO_STACK_SIZE 100


extern int map_scale;
extern int map[MAX_SCALE][MAX_SCALE];
extern int box_num;
extern int gamer_location[2];
extern int box_location[MAX_SCALE][2];
extern int aim[MAX_SCALE][2];

typedef struct {
    int e_gamer_location[2];
    int e_box_location[MAX_SCALE][2];
} Location;

int init_save();   // 初始化栈并保存第一步
int save();        // 保存当前状态入栈
int out();         // 从栈中取出上一步状态

#endif

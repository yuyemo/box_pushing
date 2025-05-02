// undo.c
#include <stdio.h>
#include <string.h>
#include "undo.h"
#include "timer.h"


// 栈结构
static Location stack[UNDO_STACK_SIZE];
Location temp;
static int top = -1;

// 将当前状态保存到栈中（用于 init_save 和 save）
static int push_current_state() {
    if (top >= UNDO_STACK_SIZE - 1)
        return -1; // 栈溢出

    top++;
    if(top>-1){
    memcpy(stack[top].e_gamer_location, temp.e_gamer_location, sizeof(gamer_location));
    memcpy(temp.e_gamer_location, gamer_location, sizeof(gamer_location));

    for (int i = 0; i < box_num; i++) {
        stack[top].e_box_location[i][0]=temp.e_box_location[i][0];
        temp.e_box_location[i][0]= box_location[i][0];
        stack[top].e_box_location[i][1] = temp.e_box_location[i][1];
        temp.e_box_location[i][1]=box_location[i][1];
    }
    }
    else if(top==-1){
    memcpy(temp.e_gamer_location, gamer_location, sizeof(gamer_location));

    for (int i = 0; i < box_num; i++) {
        temp.e_box_location[i][0]= box_location[i][0];
        temp.e_box_location[i][1]=box_location[i][1];
    }
    }

    return 0;
}

// 初始化保存一次
int init_save() {
    top = -1; // 清空栈
    return push_current_state();
}

// 再次保存（用于每次移动后）
int save() {
    return push_current_state();
}

// 从栈中取出上一步
int out() {

    if (top < 0)
        return -1; // 栈空

    // 获取状态
    Location current = stack[top];
    top--;

    // 还原玩家位置
    gamer_location[0] = current.e_gamer_location[0];
    gamer_location[1] = current.e_gamer_location[1];

    // 还原箱子位置
    for (int i = 0; i < box_num; i++) {
        box_location[i][0] = current.e_box_location[i][0];
        box_location[i][1] = current.e_box_location[i][1];
    }
   
    // 清除 map 中的旧箱子位置（1），并设置新位置为 1
    for (int i = 0; i < map_scale; i++) {
        for (int j = 0; j < map_scale; j++) {
            if (map[i][j] == 1)
                map[i][j] = 0;
        }
    }

    for (int i = 0; i < box_num; i++) {
        int x = box_location[i][0];
        int y = box_location[i][1];

        if (x < 0 || x >= map_scale || y < 0 || y >= map_scale)
            return -1; // 非法坐标
    if(map[x][y]!=2)map[x][y] = 1;
    }
decrease_step_count(); 
temp=current;
    return 0;
}

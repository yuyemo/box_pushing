// map.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"
#include "game.h"


// 全局变量定义
int map_scale = 10;
int map[MAX_SCALE][MAX_SCALE] = {0};
int box_num = 3;
int gamer_location[2] = {0};
int box_location[MAX_SCALE][2];
int aim[MAX_SCALE][2];

// 辅助函数：判断是否重复坐标
static int is_duplicate(int loc[][2], int count, int x, int y) {
    for (int i = 0; i < count; i++) {
        if (loc[i][0] == x && loc[i][1] == y)
            return 1;
    }
    return 0;
}


// 初始化地图
int init(void) {

    gamer_location[0] = 0;
    gamer_location[1] = 0;

    // 初始化 map 为 0
    for (int i = 0; i < map_scale; i++) {
        for (int j = 0; j < map_scale; j++) {
            map[i][j] = 0;
        }
    }

    // 随机生成箱子和目标位置（不重复）
    int used = 0;
    int total = box_num * 2;
    int used_locations[MAX_SCALE][2];

    srand((unsigned int)time(NULL));

    while (used < total) {
        int x = rand() % map_scale;
        int y = rand() % map_scale;

         if ((x != 0 && y != 0) && is_valid_pos(x, y)==1) continue;

        if (!is_duplicate(used_locations, used, x, y)) {
            used_locations[used][0] = x;
            used_locations[used][1] = y;

            if (used < box_num) {
                if ((x == 0 || y == 0||x==map_scale||y==map_scale) ) continue;
                box_location[used][0] = x;
                box_location[used][1] = y;
                map[x][y] = 1;
            } else {
                int idx = used - box_num;
                aim[idx][0] = x;
                aim[idx][1] = y;
                map[x][y] = 2;
            }

            used++;
        }
    }

    return 0;
}

// 扫描 map，找到所有 box 并更新 box_location
int scan(void) {
    int found = 0;
    int count = 0;

    for (int i = 0; i < map_scale; i++) {
        for (int j = 0; j < map_scale; j++) {
            if (map[i][j] == 1) {
                box_location[count][0] = i;
                box_location[count][1] = j;
                count++;
                found = 1;
            }
        }
    }

    return found ? 3 : 2;
}


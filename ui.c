// ui.c
#include <stdio.h>
#include<stdlib.h>
#include "ui.h"
#include "map.h"
#include "timer.h"
#include "game.h"
#include"undo.h"

// 跨平台清屏函数
void clear_screen(void) {
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

// 地图绘制函数
void draw_map(void) {
    for (int i = 0; i < map_scale; i++) {
        for (int j = 0; j < map_scale; j++) {
            // 玩家位置优先显示
            if (i == gamer_location[0] && j == gamer_location[1]) {
                printf(" @ ");
            }
            else {
                switch (map[i][j]) {
                case 0: printf(" . "); break;  // 空地
                case 1: printf(" # "); break;  // 箱子
                case 2: printf(" O "); break;  // 目标点
                default: printf(" ? "); break; // 异常
                }
            }
        }
        printf("\n");
    }
}

// 显示步数和时间
void display_status(void) {
    printf("\n步数: %d    时间: %d 秒\n", get_step_count(), get_elapsed_time());
}

// 游戏胜利提示
void display_victory(void) {
    printf("\nヽ(＾▽＾*)～恭喜你，完成推箱子挑战！ヽ(＾▽＾*)～\n");
}

// 判断是否胜利（所有目标点上有箱子）
int check_victory(void) {
    for (int i = 0; i < map_scale; i++) {
        for (int j = 0; j < map_scale; j++) {
            if(map[i][j]==1)return 0;}
    }
    return 1;
}

// UI主循环（游戏控制核心）
void ui_loop(int level) {
    init(level);
    start_timer();
    reset_step_count();
    init_save();
    while (1) {
        clear_screen();
        draw_map();
        display_status();

        if (check_victory()) {
            display_victory();
            break;
        }

        int move_result = move();
        if (move_result == -1) {
            printf("非法输入，请按 W/A/S/D 移动\n");
        }
    }
}

// game.c
#include "game.h"
#include "timer.h"  //  引入计步接口
#include <stdio.h>

// 跨平台输入处理。
#if defined(_WIN32)
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

int is_valid_pos(int x, int y) {
    if (map_scale <= 0 || map_scale > MAX_SCALE) {
        return -1; // 异常情况
    }
    return (x >= 0 && x < map_scale && y >= 0 && y < map_scale) ? 0 : 1;
}

#if !defined(_WIN32)
static int getch(void) {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif

int move() {
    int ch;
#if defined(_WIN32)
    ch = _getch();
#else
    ch = getch();
#endif

    int dx = 0, dy = 0;
    switch (ch) {
        case 'w': dy = -1; break;  // 上移
        case 's': dy = 1;  break;  // 下移
        case 'a': dx = -1; break;  // 左移
        case 'd': dx = 1;  break;  // 右移
        default:  return 0;        // 无效输入
    }

    int x = gamer_location[0];
    int y = gamer_location[1];
    int new_x = x + dx;
    int new_y = y + dy;

    // 第一步：检查目标位置有效性
    int valid = is_valid_pos(new_x, new_y);
    if (valid != 0) return valid;

    // 第二步：处理移动逻辑
    if (map[new_x][new_y] != 1) {  // 普通移动
        gamer_location[0] = new_x;
        gamer_location[1] = new_y;
        increase_step_count();  //  成功移动，计步 +1
        return 0;
    } else {  // 推箱子逻辑
        int box_x = new_x + dx;
        int box_y = new_y + dy;
        
        // 检查箱子目标位置有效性
        int box_valid = is_valid_pos(box_x, box_y);
        if (box_valid != 0) return box_valid;

        // 处理不同箱子目标位置类型
        if (map[box_x][box_y] == 2) {  // 推到目标点
            map[new_x][new_y] = 0;     // 清除原箱子位置
        } else if (map[box_x][box_y] == 0) {  // 普通推动
            map[new_x][new_y] = 0;
            map[box_x][box_y] = 1;     // 设置新箱子位置
        } else {
            return 1; // 推动失败：目标点被阻挡
        }

        gamer_location[0] = new_x;
        gamer_location[1] = new_y;
        increase_step_count();  //  推箱子成功，计步 +1
        return 0;
    }
}

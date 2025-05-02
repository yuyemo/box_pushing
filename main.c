#include <stdio.h>
#include "ui.h"

int main(void) {
    int level;
    printf("欢迎来到推箱子游戏！\n");
    printf("请选择您要挑战的难度（由易到难1~7）:\n");
    scanf("%d",&level);


#if defined(_WIN32)
    getchar();
#else
    getchar();  // 类 Unix 系统不需要额外处理
#endif

    ui_loop(level);

    printf("游戏结束，感谢游玩！\n");
    return 0;
}

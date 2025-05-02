#include <stdio.h>
#include "ui.h"

int main(void) {
    int level;
    printf("欢迎来到推箱子游戏！\n");
    printf("说明：\n#代表箱子\n@代表小人\nO代表洞\n按WASD移动\n按Z悔棋\n");
    printf("请选择您要挑战的难度（由易到难1~14）:\n");
    scanf("%d",&level);


#if defined(_WIN32)
    getchar();
#else
    getchar();  // 类 Unix 系统不需要额外处理
#endif

    ui_loop(level%15);

    printf("游戏结束，感谢游玩！\n");
    getchar();
    return 0;
}

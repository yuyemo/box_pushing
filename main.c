#include <stdio.h>
#include "ui.h"

int main(void) {

    printf("欢迎来到推箱子游戏！\n");
    printf("按任意键开始...\n");

#if defined(_WIN32)
    getchar();
#else
    getchar();  // 类 Unix 系统不需要额外处理
#endif

    ui_loop();

    printf("游戏结束，感谢游玩！\n");
    return 0;
}

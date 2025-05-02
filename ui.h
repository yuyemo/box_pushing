// ui.h
#ifndef UI_H
#define UI_H

// 跨平台的输入获取函数声明
int getch(void);  // 声明 getch 函数

// 清屏
void clear_screen(void);

// 绘制地图
void draw_map(void);

// 显示步数和时间
void display_status(void);

// 游戏胜利提示
void display_victory(void);

// 检查是否胜利
int check_victory(void);

// UI 主循环
void ui_loop(void);
void start_prompt(void) ;
#endif // UI_H

// map.h
#ifndef MAP_H
#define MAP_H

#define MAX_SCALE 100

extern int map_scale;
extern int map[MAX_SCALE][MAX_SCALE];
extern int box_num;
extern int gamer_location[2];
extern int box_location[MAX_SCALE][2];
extern int aim[MAX_SCALE][2];


// 初始化地图和位置，返回0成功，1失败
int init(void);


// 扫描 map 中所有为 1 的坐标并更新 box_location
// 返回3表示找到，2表示未找到
int scan(void);


#endif

// game.h
#ifndef GAME_H
#define GAME_H

#define MAX_SCALE 100

extern int map_scale;
extern int map[MAX_SCALE][MAX_SCALE];
extern int box_num;
extern int gamer_location[2];
extern int box_location[MAX_SCALE][2];
extern int aim[MAX_SCALE][2];

int is_valid_pos(int x, int y);
int move();


#endif // GAME_H
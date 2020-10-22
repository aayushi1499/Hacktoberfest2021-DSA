#ifndef SNAKE

#define SNAKE

#include <iostream>
#include <vector>
#include "constants.h"
#include "ui.h"
using namespace std;

void init_snake();

bool has_collision();

void paint_snake();

pair<int, int> move_snake(int);

void grow_snake();

#endif
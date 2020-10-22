#include "ui.h"


void init_ui() {
	setlocale(LC_ALL, "");  
	initscr();  
	curs_set(0);  
	noecho();  
		cbreak(); 	keypad(stdscr, TRUE);
	start_color();
	init_pair(SNAKE_COLOR_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(FOOD_COLOR_PAIR, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(BORDER_COLOR_PAIR, COLOR_WHITE, COLOR_BLACK);
	init_pair(STATUS_COLOR_PAIR, COLOR_GREEN, COLOR_WHITE);
	nodelay(stdscr, TRUE); 

	}

void tear_down_ui() {
	endwin();
}

void paint_border() {
		attron(COLOR_PAIR(BORDER_COLOR_PAIR));
	for(int i = 0; i < COLS; i++) {
		move(0, i);
		addstr("\u2588");
		move(LINES-1, i);
		addstr("\u2588");
	}
	for(int i = 0; i < LINES; i++) {
		move(i, 0);
		addstr("\u2588");
		move(i, COLS - 1);
		addstr("\u2588");
	}
	attroff(COLOR_PAIR(BORDER_COLOR_PAIR));
}
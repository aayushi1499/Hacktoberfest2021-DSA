#include "game.h"

int direction;
int game_state = BEFORE_START;
int score = 0;

void paint_status() {
	move(0, 5);
	attron(COLOR_PAIR(STATUS_COLOR_PAIR));
	attron(A_BOLD);
	if(game_state == BEFORE_START) {
		printw("Press any key to start");
	} else if(game_state == STARTED) {
		printw("Score: %d ", score);
	}
	attroff(COLOR_PAIR(STATUS_COLOR_PAIR));
	attroff(A_BOLD);
}

void start_game() {
	erase();
	init_snake();
	init_food();
	direction = UP;
	game_state = STARTED;
}

void tick(int key) {
	if(game_state == BEFORE_START) {
		erase();
		paint_border();
		paint_status();
		if(key != ERR) {
			start_game();
		}
	} else if(game_state == STARTED) {
		if(key == UP && direction != DOWN) {
			direction = UP;
		} else if(key == DOWN && direction != UP) {
			direction = DOWN;
		} else if(key == LEFT && direction != RIGHT) {
			direction = LEFT;
		} else if(key == RIGHT && direction != LEFT) {
			direction = RIGHT;
		}
		pair<int, int> head = move_snake(direction);
		if(consume_food(head.first, head.second)) {
			score ++;
			grow_snake();
		}
		erase();
		paint_border();
		paint_status();
		paint_snake();
		paint_food();
		if(has_collision()) {
			game_state = BEFORE_START;
		}
	}
}
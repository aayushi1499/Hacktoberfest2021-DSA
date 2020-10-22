#include "snake.h"

vector<pair<int, int>> snake;
pair<int, int> last_tail;

void init_snake() {
	snake.clear();
	snake.push_back({10, 10});
	snake.push_back({10, 11});
	snake.push_back({10, 12});
	for(int i = 0; i < snake.size(); i++) {
		move(snake[i].first, snake[i].second);
		addstr("\u2588");
	}
}

bool has_collision() {
	
	auto new_head = snake[0];
	if(new_head.first == 0 || new_head.first == LINES
	   || new_head.second == 0 || new_head.second == COLS) {
		return true;
	}
	
	for(int i = 1; i < snake.size(); i++) {
	
		if(new_head == snake[i])
			return true;
	}
	return false;
}

void paint_snake() {
	attron(COLOR_PAIR(SNAKE_COLOR_PAIR));
	for(int i = 0; i < snake.size(); i++) {
		move(snake[i].first, snake[i].second);
		addstr("\u2588");
	}
	attroff(COLOR_PAIR(SNAKE_COLOR_PAIR));
}

pair<int, int> move_snake(int direction) {
	pair<int, int> new_head;
	pair<int, int> head = snake[0];
	if(direction == LEFT) {
		new_head = {head.first, head.second - 1};
	} else if(direction == RIGHT) {
		new_head = {head.first, head.second + 1};
	} else if(direction == UP) {
		new_head = {head.first -1, head.second};
	} else if(direction == DOWN) {
		new_head = {head.first + 1, head.second};
	}
	snake.insert(snake.begin(), new_head);
	last_tail = snake.back();
	snake.pop_back(); 
	return new_head;
}

void grow_snake() {
	snake.push_back(last_tail);
}
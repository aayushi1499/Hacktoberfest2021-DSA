#include "ui.h"
#include "game.h"
#include <chrono>

void event_loop() {
	auto last_time = chrono::system_clock::now();
	auto current_time = last_time;
	int dt;
	int key;

	while(true) {
		key = ERR;
		do {
			current_time = chrono::system_clock::now();
			dt = chrono::duration_cast<std::chrono::microseconds>(current_time - last_time).count();
			int k = getch();
			if(k != ERR)
				key = k;
		} while(dt < 100000);
		last_time = current_time;

		tick(key);
		refresh();
	}
}
int main() {
	init_ui();
	event_loop();
	while(getch() == ERR);  
	tear_down_ui();
	return 0;
}
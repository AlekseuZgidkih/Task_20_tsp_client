#include "menu.h"

int main() {
	Menu menu;	

	while (menu.main_menu()) {													// Цикл оснновного меню

		while (menu.getChatRun() && menu.chat()) {								// Если выполнен вход и вызов меню чат
		}
	}
	return 0;
}
#include"site.h"
#include"find_shortest_way.cpp"
#include"admin_operation.cpp"
#include"menu.h"
#include<conio.h>
#include<windows.h>

int main() {
	int choice = -1;
	csv_read_mysite();
	csv_read_site();
	init_map();
	init_basic_map();
	while (choice != 4) {
		system("cls");
		int opt = 1;
		system_menu.main_menu(opt);
		while (1) {
			if (_kbhit()) {
				int v = _getch();
				if (v == 72) {
					if (opt != 1) opt--;
					system("cls");
					system_menu.main_menu(opt);
				}
				else if (v == 80) {
					if (opt != 4) opt++;
					system("cls");
					system_menu.main_menu(opt);
				}
				else if (v == 13) {
					choice = opt;
					break;
				}
				else continue;
			}
		}
		switch (choice) {
			case 1: {
				search_menu();
				break;
			}
			case 2: {
				findway_menu();
				break;
			}
			case 3: {
				admin_menu();
				break;
			}
			case 4: {
				exit(0);
				break;
			}
		}
	}
}
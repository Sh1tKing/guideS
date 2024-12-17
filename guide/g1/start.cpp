#include"site.h"
#include"find_shortest_way.cpp"
#include"admin_operation.cpp"
#include"menu.h"
int main() {
	int choice = -1;
	csv_read_mysite();
	csv_read_site();
	init_map();
	init_basic_map();
	while (choice != 4) {
		system("cls");
		system_menu.main_menu();
		cin >> choice;
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
#include"scene.h"
#include"admin_operation.cpp"
#include"menu.h"
int main() {
	int choice = -1;
	csv_read();
	while (choice != 4) {
		system("cls");
		system_menu.main_menu();
		cin >> choice;
		switch (choice) {
			case 1: {
				break;
			}
			case 2: {
				break;
			}
			case 3: {
				admin_menu();
				break;
			}
			case 4: {
				if (myscene_size != myscene.size()) csv_writeall();
				exit(0);
				break;
			}
		}
	}
}
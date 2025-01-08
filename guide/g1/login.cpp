
#include"menu.h"
bool check_password() {
	string account, password;	
	cout << "请输入账号："<<endl;
	cin >> account;
	cout << "请输入密码："<<endl;
	cin >> password;
	if (account == "admin" && password == "123456") return true;
	else return false;
}
int to_start() {
	int choice = -1;
	while (choice != 3) {
		system("cls");
		int opt = 1;
		int code = -1;
		system_menu.login_menu(opt);
		while (1) {
			if (_kbhit()) {
				int v = _getch();
				if (v == 72) {
					if (opt != 1) opt--;
					system("cls");
					system_menu.login_menu(opt);
				}
				else if (v == 80) {
					if (opt != 3) opt++;
					system("cls");
					system_menu.login_menu(opt);
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
						int c = -1;
						while (c != 3) {
							system("cls");
							int opt = 1;
							system_menu.main_menu_user(opt);
							while (1) {
								if (_kbhit()) {
									int v = _getch();
									if (v == 72) {
										if (opt != 1) opt--;
										system("cls");
										system_menu.main_menu_user(opt);
									}
									else if (v == 80) {
										if (opt != 3) opt++;
										system("cls");
										system_menu.main_menu_user(opt);
									}
									else if (v == 13) {
										c = opt;
										break;
									}
									else continue;
								}
							}
							switch (c) {
							case 1: {
								search_menu();
								break;
							}
							case 2: {
								findway_menu();
								break;
							}
							case 3: {
								code = 1;
								break;
							}
							}
						}
						break;
					}
					case 2: {
						if (!check_password()) {
							cout << "账号密码错误" << endl;
							system("pause");
							break;
						}
						int c = -1;
						while (c != 4) {
							system("cls");
							int opt = 1;
							system_menu.main_menu_admin(opt);
							while (1) {
								if (_kbhit()) {
									int v = _getch();
									if (v == 72) {
										if (opt != 1) opt--;
										system("cls");
										system_menu.main_menu_admin(opt);
									}
									else if (v == 80) {
										if (opt != 4) opt++;
										system("cls");
										system_menu.main_menu_admin(opt);
									}
									else if (v == 13) {
										c = opt;
										break;
									}
									else continue;
								}
							}
							switch (c) {
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
								code = 1;
								break;
							}
							}
						}
						break;
					}
					case 3: {
						exit(0);
					}
				}
				if (code == 1) { 
					code = -1;
					break;				
				}
		
	}
}
#include"menu.h"
#include"scene.h"
#include"file_operate.cpp"
using namespace std;
menu system_menu;
void add_scene() {
	string name; float price; int visit_time; float distance; int present_num; string open_time;
	cout << "请输入景点名字" << endl;
	cin >> name;
	cout << "请输入门票价格" << endl;
	cin >> price;
	cout << "请输入建议旅游时间" << endl;
	cin >> visit_time;
	cout << "请输入当前人数" << endl;
	cin >> present_num;
	cout << "请输入景点开放时间" << endl;
	cin >> open_time;
	distance = 0;
	if (csv_add(name, price, visit_time, distance, present_num, open_time) == true) {
		cout << "添加成功" << endl;
		system("pause");
	}
	else { 
		cout << "添加成功" << endl;
		system("pause");
	}
}
void delete_scene() {
	cout << "请输入要删除的风景" << endl;
	string name;
	cin >> name;
	if (csv_delete(name) == true) {
		cout << "删除成功" << endl;
		system("pause");
	}
	else {
		cout << "删除失败" << endl;
		system("pause");
	}
}
void modify_scene() {
	cout << "请输入要修改的风景" << endl;
	string name;
	cin >> name;
	if (csv_modify(name) == true) {
		cout << "修改成功" << endl;
		system("pause");
	}
	else {
		cout << "修改失败" << endl;
		system("pause");
	}
}
void admin_menu() {
	int choice = -1;
	while (choice != 4) {
		system("cls"); 
		system_menu.admin_operate_menu();
		cin >> choice;
		switch (choice) {
		case 1: {
			add_scene();
			break;
		}
		case 2: {
			delete_scene();
			break;
		}
		case 3: {
			
			break;
		}
		case 4: {
			return;
			break;
		}
		}
	}
}
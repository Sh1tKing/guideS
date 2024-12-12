#pragma once
#include<iostream>
using namespace std;
class menu {
public:
	void main_menu();
	void admin_operate_menu();
};
void menu::main_menu() {
	cout << "1.查看景点" << endl;
	cout << "2.查看推荐路线" << endl;
	cout << "3.管理景点" << endl;
	cout << "4.退出系统" << endl;
}
void menu::admin_operate_menu() {
	cout << "1.添加景点" << endl;
	cout << "2.删除景点" << endl;
	cout << "3.修改景点" << endl;
	cout << "4.返回" << endl;
}
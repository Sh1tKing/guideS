#pragma once
#include<iostream>
using namespace std;
class menu {
public:
	void main_menu_user(int opt);
	void main_menu_admin(int opt);
	void admin_operate_menu(int opt);
	void search_menu(int opt);
	void login_menu(int opt);
};
void menu::login_menu(int opt) {
	cout << "--华南植物园导游系统-- " << endl;
	cout << "---------------------" << endl;
	if (opt == 1) cout << "  -> 1.游客进入" << endl;
	else cout << "     1.游客进入" << endl;
	if (opt == 2) cout << "  -> 2.管理员登录" << endl;
	else cout << "     2.管理员登录" << endl;
	if (opt == 3) cout << "  -> 3.退出系统" << endl;
	else cout << "     3.退出系统" << endl;
	cout << "---------------------" << endl;
}
void menu::main_menu_user(int opt) {
	cout << "--华南植物园导游系统-- " << endl;
	cout << "---------------------" << endl;
	if (opt == 1) cout << "  -> 1.查看景点"<<endl;
	else cout << "     1.查看景点" << endl;
	if (opt == 2) cout << "  -> 2.查看推荐路线" << endl;
	else cout << "     2.查看推荐路线" << endl;
	if (opt == 3) cout << "  -> 3.返回登录" << endl;
	else cout << "     3.返回登录" << endl;
	cout << "---------------------" << endl;
}
void menu::main_menu_admin(int opt) {
	cout << "--华南植物园导游系统-- " << endl;
	cout << "---------------------" << endl;
	if (opt == 1) cout << "  -> 1.查看景点"<<endl;
	else cout << "     1.查看景点" << endl;
	if (opt == 2) cout << "  -> 2.查看推荐路线" << endl;
	else cout << "     2.查看推荐路线" << endl;
	if (opt == 3) cout << "  -> 3.管理景点" << endl;	
	else cout << "     3.管理景点" << endl;
	if (opt == 4) cout << "  -> 4.返回登录" << endl;
	else cout << "     4.返回登录" << endl;
	cout << "---------------------" << endl;
}
void menu::admin_operate_menu(int opt) {
	cout << "--华南植物园导游系统--" << endl;
	cout << "---------------------" << endl;
	if (opt == 1) cout << "  -> 1.添加景点" << endl;
	else cout << "     1.添加景点" << endl;
	if (opt == 2) cout << "  -> 2.删除景点" << endl;
	else cout << "     2.删除景点" << endl;
	if (opt == 3) cout << "  -> 3.修改景点" << endl;
	else cout << "     3.修改景点" << endl;
	if (opt == 4) cout << "  -> 4.返回" << endl;
	else cout << "     4.返回" << endl;
	cout << "---------------------" << endl;
}
void menu::search_menu(int opt) {
	cout << "--华南植物园导游系统--" << endl;
	cout << "---------------------" << endl;
	if (opt == 1) cout << "  -> 1.查看指定园区" << endl;
	else cout << "     1.查看指定园区" << endl;
	if (opt == 2) cout << "  -> 2.查看所有园区" << endl;
	else cout << "     2.查看所有园区" << endl;
	if (opt == 3) cout << "  -> 3.返回" << endl;
	else cout << "     3.返回" << endl;
	cout << "---------------------" << endl;
}
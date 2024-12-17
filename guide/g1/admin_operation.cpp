#include"menu.h"
#include"site.h"
#include"file_operate.cpp"
using namespace std;
menu system_menu;
void search_menu() {
	int code = 0;
	
	while(code!=3){
		system("cls");
		cout << "1.查看指定园区" << endl;
		cout << "2.查看所有园区" << endl;
		cout << "3.返回" << endl;
		cin >> code;
		if (code == 1) {
			for (int i = 0; i < mysite.size(); i++) {
				cout << i << "  " << mysite[i].GetName() << endl;
			}
			cout << "输入要查看的编号" << endl;
			int id;
			cin >> id;
			cout << mysite[id].GetName() << "  ";
			if (mysite[id].GetToilet() == true) cout << "设有卫生间  ";
			else cout << "不设有卫生间  ";
			if (mysite[id].GetIsopen() == true) cout << "正在开放  " << endl;
			else cout << "关闭中  " << endl;
			system("pause");
		}
		else if (code == 2) {
			for (int i = 0; i < mysite.size(); i++) {
				cout << i << "  " << mysite[i].GetName() << "  ";
				if (mysite[i].GetToilet() == true) cout << "设有卫生间  ";
				else cout << "不设有卫生间  ";
				if (mysite[i].GetIsopen() == true) cout << "正在开放  " << endl;
				else cout << "关闭中  " << endl;
			}
			system("pause");
		}
	}
	
}
void add_site() {
	string name; bool toilet; bool isopen;
	cout << "请输入景点名字：" << endl;
	cin >> name;
	cout << "是否内设洗手间（1.是  0.否）" << endl;
	cin >> toilet;
	cout << "是否正在开放（1.是  0.否）" << endl;
	cin >> isopen;
	
	int choice = -1;
	vector<relate_site> relate;
	while (choice != 0) {
		system("cls");
		for (int i = 0; i < graph.size(); i++) {
			cout << i << "  " << graph[i][i].name << endl;
		}
		cout << "请选择附近可直接到达的其他园区" << endl;
		int number = 0, distance = 0;
		cin >> number;
		cout << "请输入新增园区到达此园区的路程距离（m）" << endl;
		cin >> distance;
		relate.push_back({number,distance});
		cout << "1.继续添加 0.结束添加" << endl;
		cin >> choice;
	}
	
	if (csv_map_add(relate) && csv_writemap() && csv_situation_add(name,toilet,isopen)) {
		cout << "添加成功" << endl;
		site tmp(name, toilet, isopen);
		mysite.push_back(tmp);
		init_basic_map();
		system("pause");
	}
	else { 
		cout << "添加失败" << endl;
		system("pause");
	}
}
void delete_site() {
	system("cls");
	for (int i = 0; i < graph.size(); i++) {
		cout << i << "  " << graph[i][i].name << endl;
	}
	cout << "请输入要删除的景点编号：" << endl;
	int id;
	cin >> id;
	if (csv_map_delete(id) && csv_writemap()&& csv_situation_delete(id) && csv_situation_writeall()) {
		cout << "删除成功" << endl;
		mysite.clear();
		csv_read_mysite();
		init_basic_map();
		system("pause");
	}
	else {
		cout << "删除失败，当前景点不存在" << endl;
		system("pause");
	}
}
void modify_site() {
	int id; 
	
	for (int i = 0; i < mysite.size(); i++) {
		cout << i << "  " << mysite[i].GetName() << endl;
	}
	cout << "请输入要修改的景点编号：" << endl;

	cin >> id;
	system("cls");
	cout << endl<<"当前园区状态为：" << endl << mysite[id].GetName() << " ";
	if (mysite[id].GetToilet() == true) cout << "设有卫生间  ";
	else cout << "不设有卫生间  ";
	if (mysite[id].GetIsopen() == true) cout << "正在开放  " << endl;
	else cout << "关闭中  " << endl;
	int c = -1;
		cout <<endl<< "请选择：（1.更改名字  2.更改卫生间状态  3.更改开闭园区状态 4.返回）";
		cin >> c;
		switch (c)
		{
			case 1: {
				cout << "请输入新的名字" << endl;
				string name;
				cin.clear();
				cin >> name;
				
				if (csv_situation_modify(name, id) && csv_situation_writeall()) {
					cout << "修改成功" << endl;
				}
				else {
					cout << "修改失败，当前景点不存在" << endl;
				}
				system("pause");
				break;
			}
			case 2: {
				cout << "请输入新的卫生间状态（1.有  0.没有）" << endl;
				bool toilet;
				cin.clear();
				cin >> toilet;
				if (csv_situation_modify(toilet, id) && csv_situation_writeall()) {
					cout << "修改成功" << endl;
				}
				else {
					cout << "修改失败，当前景点不存在" << endl;
				}
				system("pause");
				break;
			}
			case 3: {
				cout << "请输入新的园区状态（1.开放  0.关闭）" << endl;
				bool isopen;
				cin.clear();
				cin >> isopen;
				
				if (csv_situation_modify(id, isopen) && csv_situation_writeall()) {
					cout << "修改成功" << endl;
				}
				else {
					cout << "修改失败，当前景点不存在" << endl;
				}
				system("pause");
				break;
			}
			case 4: {
				return;
				break;
			}
		}
		return;
}
void admin_menu() {
	int choice = -1;
	while (choice != 4) {
		system("cls"); 
		system_menu.admin_operate_menu();
		cin.clear();
		cin >> choice;
		switch (choice) {
		case 1: {
			add_site();
			break;
		}
		case 2: {
			delete_site();
			break;
		}
		case 3: {
			modify_site();
			break;
		}
		case 4: {
			return;
			break;
		}
		}
	}
}
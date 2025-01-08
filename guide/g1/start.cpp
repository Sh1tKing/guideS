#include"site.h"
#include"find_shortest_way.cpp"
#include"admin_operation.cpp"
#include"menu.h"
#include<conio.h>
#include<windows.h>
#include "login.cpp"
using namespace std;
int main() {
	int choice = -1;
	csv_read_mysite();
	csv_read_site();
	init_map();
	init_basic_map();
	while (1) {
		to_start();
	}
}
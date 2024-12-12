#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "menu.h"
#include<iomanip>
#define FILE_PATH "data\\1.csv"
#define MAX_NUM 100
using namespace std;
vector<scene> myscene;
int myscene_size = myscene.size();
void csv_read() {
	string file_name = FILE_PATH;
	ifstream csv_data(file_name, ios::in);
	if (!csv_data.is_open())
	{
		printf("Error: opening file fail\n");
		exit(1);
	}
	else {
		string line;
		vector<string> words;
		string word;
		getline(csv_data, line);
		istringstream sin;
		while (getline(csv_data, line))
		{
			words.clear();
			sin.clear();
			sin.str(line);
			float tmp1 = 0.0;
			int tmp2 = 0;
			float tmp3 = 0.0;
			int tmp4 = 0;
			while (getline(sin, word, ','))
			{
				words.push_back(word);
			}
			istringstream Tmp1(words[1]);
			Tmp1 >> tmp1;
			istringstream Tmp2(words[2]);
			Tmp2 >> tmp2;
			istringstream Tmp3(words[3]);
			Tmp3 >> tmp3;
			istringstream Tmp4(words[4]);
			Tmp4 >> tmp4;
			scene tmp(words[0], tmp1, tmp2, tmp3, tmp4,words[5]);
			myscene.push_back(tmp);
		}
		csv_data.close();
	}

}
bool csv_writeall() {
	string file_name = FILE_PATH;
	ifstream file(file_name);
	if (!file.is_open()) {
		cout << "File does not exist!" << endl;
		return false;
	}
	else {
		file.close();
		ofstream outFile(file_name, ios::out);
		for (int i = 0; i < myscene.size(); i++) {
			outFile << myscene[i].GetName() << ','
				<< myscene[i].GetPrice() << ','
				<< myscene[i].GetVisit_time() << ','
				<< myscene[i].GetDistance() << ','
				<< myscene[i].GetPresent_num() << ','
				<< myscene[i].GetOpen_time() << endl;
		}
		outFile.close();
		return true;
	}
}
bool csv_add(string name, float price, int visit_time, float distance, int present_num, string open_time) {
	string file_name = FILE_PATH;
	ifstream file(file_name);
	if (!file.is_open()) {
		cout << "File does not exist!" << endl;
		return false;
	}
	else {
		file.close();
		ofstream outFile(file_name, ios::app);

		outFile << name << ','
			<< price << ','
			<< visit_time << ','
			<< distance << ','
			<< present_num <<','
			<< open_time <<endl;
		outFile.close();
		scene tmp(name, price, visit_time, distance, present_num, open_time);
		myscene.push_back(tmp);
		myscene_size = myscene.size();
		return true;
	}
}
bool csv_delete(string name) {
	for (auto i = myscene.begin(); i!=myscene.end(); i++) {
		if (i->GetName() == name) {
			myscene.erase(i);
			return true;
		}
	}
	return false;
}
bool csv_modify(string name) {
	for (auto i = myscene.begin(); i != myscene.end(); i++) {
		if (i->GetName() == name) {
			
		}
	}
	return false;
}
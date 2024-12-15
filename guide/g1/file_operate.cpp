#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "menu.h"
#include<iomanip>
#define FILE_PATH1 "data\\1.csv"
#define FILE_PATH2 "data\\1t.csv"
#define MAX_NUM 100
using namespace std;
vector<scene> myscene;
int myscene_size = myscene.size();
void csv_read1() {
	string file_name = FILE_PATH1;
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
		istringstream sin;
		while (getline(csv_data, line))
		{
			words.clear();
			sin.clear();
			sin.str(line);
			int tmp1 = 0;
			float tmp2 = 0.0;
			int tmp3 = 0;
			float tmp4 = 0.0;
			int tmp5 = 0;
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
vector<each_site> csv_read2() {
	string file_name = FILE_PATH2;
	ifstream csv_data(file_name, ios::in);
	vector<each_site> data;
	if (!csv_data.is_open())
	{
		printf("Error: opening file fail\n");
		exit(1);
	}
	else {
		string line;
		vector<string> words;
		string word;
		istringstream sin;
		while (getline(csv_data, line))
		{
			words.clear();
			sin.clear();
			sin.str(line);
			bool tmp1 = 0;
			while (getline(sin, word, ','))
			{
				words.push_back(word);
			}
			istringstream Tmp1(words[1]);
			Tmp1 >> tmp1;
			each_site tmp;
			tmp.distance = 0;
			tmp.name = words[0];
			tmp.toilet = tmp1;
			data.push_back(tmp);
		}
		csv_data.close();
	}
	return data;

}
bool csv_writeall() {
	string file_name = FILE_PATH1;
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
	string file_name = FILE_PATH1;
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
bool csv_delete(int id) {
	if (id > myscene.size()) return false;
	auto i = myscene.begin();
	while (id > 0) {
		id--;
		i++;
	}
	myscene.erase(i);
	csv_writeall();
	return true;
}
bool csv_modify(int id,string name,float price,int visit_time,float distance,int present_num,string open_time) {
	if (id > myscene.size()) return false;
	auto i = myscene.begin();
	while (id > 0) {
		id--;
		i++;
	}
	i->SetName(name);
	i->SetPrice(price);
	i->Setvisit_time(visit_time);
	i->SetDistance(distance);
	i->SetPresent_num(present_num);
	i->SetOpen_time(open_time);
	csv_writeall();
	return true;
}
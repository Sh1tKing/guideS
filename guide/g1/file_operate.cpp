#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "menu.h"
#include "site.h"
#include<iomanip>
#define FILE_PATH1 "data\\site_situation.csv"
#define FILE_PATH2 "data\\map.csv"
#define MAX_NUM 100
using namespace std;
vector<site> mysite;
int mysite_size = mysite.size();
typedef struct relate_site {
	int number;
	int distance;
};
bool csv_read_mysite() {
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
			bool tmp1 = 0, tmp2 = 0;
			while (getline(sin, word, ','))
			{
				words.push_back(word);
			}
			istringstream Tmp1(words[1]);
			Tmp1 >> tmp1;
			istringstream Tmp2(words[2]);
			Tmp2 >> tmp2;
			site tmp(words[0], tmp1, tmp2);
			mysite.push_back(tmp);
		}
		csv_data.close();
	}
}
bool csv_situation_writeall() {
	string file_name = FILE_PATH1;
	ifstream file(file_name);
	if (!file.is_open()) {
		cout << "File does not exist!" << endl;
		return false;
	}
	else {
		file.close();
		ofstream outFile(file_name, ios::out);
		for (int i = 0; i < mysite.size(); i++) {
			outFile << mysite[i].GetName() << ','
				<< mysite[i].GetToilet() << ','
				<< mysite[i].GetIsopen() << endl;
		}
		outFile.close();
		return true;
	}
}
vector<each_site> csv_read_site() {
	string file_name = FILE_PATH1;
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
			bool tmp1 = 0, tmp2 = 0;
			while (getline(sin, word, ','))
			{
				words.push_back(word);
			}
			istringstream Tmp1(words[1]);
			Tmp1 >> tmp1;
			istringstream Tmp2(words[2]);
			Tmp2 >> tmp2;
			each_site tmp;
			tmp.distance = 0;
			tmp.name = words[0];
			tmp.toilet = tmp1;
			tmp.isopen = tmp2;
			data.push_back(tmp);
		}
		csv_data.close();
	}
	return data;

}
vector<vector<int>> csv_read_map() {
	string file_name = FILE_PATH2;
	ifstream csv_data(file_name, ios::in);
	vector<vector<int>> data;
	if (!csv_data.is_open())
	{
		printf("Error: opening file fail\n");
		exit(1);
	}
	else {
		string line;
		vector<int> words;
		string word;
		istringstream sin;
		while (getline(csv_data, line))
		{
			words.clear();
			sin.clear();
			sin.str(line);
			int tmp1;
			while (getline(sin, word, ','))
			{
				istringstream Tmp1(word);
				Tmp1 >> tmp1;
				words.push_back(tmp1);
			}

			data.push_back(words);
		}
		csv_data.close();
	}
	return data;

}
bool csv_writemap() {
	string file_name = FILE_PATH2;
	ifstream file(file_name);
	if (!file.is_open()) {
		cout << "File does not exist!" << endl;
		return false;
	}
	else {
		file.close();
		ofstream outFile(file_name, ios::out);
		for (int i = 0; i < mymap.size(); i++) {
			for (int j = 0; j < mymap.size(); j++) {
				outFile << mymap[i][j];
				if (j < mymap.size() - 1) outFile << ',';
			}
			outFile << endl;
		}
		outFile.close();
		return true;
	}
}
bool csv_situation_add(string name, bool toilet, bool isopen) {
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
			<< toilet << ','
			<< isopen << endl;
		outFile.close();
		return true;
	}
}
bool csv_map_add(vector<relate_site>& relate) {
	if (relate.size() == 0) return false;
	int new_size = mymap.size();
	vector<int> new_site(mymap.size(), -1);
	new_site.push_back(0);
	for (int i = 0; i < mymap.size(); i++) {
		mymap[i].push_back(-1);
	}
	mymap.push_back(new_site);
	for (auto newsite_data : relate) {
		mymap[newsite_data.number][new_size] = newsite_data.distance;
		mymap[new_size][newsite_data.number] = newsite_data.distance;
	}
	return true;
}
bool csv_situation_delete(int number) {
	if (number<0 || number>mysite.size()) return false;
	mysite.erase(mysite.begin() + number);
	return true;
}
bool csv_map_delete(int number) {
	for (int i = 0; i < mymap.size(); i++) {
		mymap[i].erase(mymap[i].begin() + number);
	}
	mymap.erase(mymap.begin() + number);
	return true;
}
//modify
bool csv_situation_modify(string name, int number) {
	if (number<0 || number>mysite.size()) return false;
	mysite[number].SetName(name);
	graph[number][number].name = name;
	return true;
}
bool csv_situation_modify(bool toilet, int number) {
	if (number<0 || number>mysite.size()) return false;
	mysite[number].SetToilet(toilet);
	graph[number][number].toilet = toilet;
	return true;
}
bool csv_situation_modify(int number, bool isopen) {
	if (number<0 || number>mysite.size()) return false;
	mysite[number].SetIsopen(isopen);
	graph[number][number].isopen = isopen;
	return true;
}
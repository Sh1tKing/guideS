#pragma once
#include<iostream>
using namespace std;
class site {
public:
	//int GetId();
	string GetName();
	bool   GetToilet();
	bool   GetIsopen();
	//void SetId(int);
	void SetName(string);
	void SetToilet(bool);
	void SetIsopen(bool);

	site(string name, bool toilet, bool isopen) : name(name),toilet(toilet),isopen(isopen) {}
private:
	string name;
	bool toilet;
	bool isopen;
};
string site::GetName() { return this->name; }
bool site::GetToilet() { return this->toilet; }
bool site::GetIsopen() { return this->isopen; }
void site::SetName(string name) { this->name = name; }
void site::SetToilet(bool toilet) { this->toilet = toilet; }
void site::SetIsopen(bool isopen) { this->isopen = isopen; }
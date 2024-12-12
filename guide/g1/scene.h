#pragma once
#include<iostream>
using namespace std;
class scene {
public:
	string GetName();
	float GetPrice();
	int GetVisit_time();
	float GetDistance();
	int GetPresent_num();
	string GetOpen_time();
	void SetName(string);
	void SetPrice(float);
	void Setvisit_time(int);
	void SetDistance(float);
	void SetPresent_num(int);
	void SetOpen_time(int);
	scene(string name, float price, int visit_time, float distance, int present_num,string open_time):name(name),price(price),visit_time(visit_time), distance(distance), present_num(present_num), open_time(open_time){}
private:
	string name;
	float price;
	int visit_time;
	float distance;
	int present_num;
	string open_time;
};
string scene::GetName() { return this->name; }
float scene::GetPrice() { return this->price; }
int scene::GetVisit_time() { return this->visit_time; }
float scene::GetDistance() { return this->distance; }
int scene::GetPresent_num() { return this->present_num; }
string scene::GetOpen_time() { return this->open_time; }
void scene::SetName(string name) {
	this->name = name;
}
void scene::SetPrice(float price) {
	this->price = price;
}
void scene::Setvisit_time(int visit_time) {
	this->visit_time = visit_time;
}
void scene::SetDistance(float distance) {
	this->distance = distance;
}
void scene::SetPresent_num(int present_num) {
	this->present_num = present_num;
}
void scene::SetOpen_time(int open_time) {
	this->open_time = open_time;
}
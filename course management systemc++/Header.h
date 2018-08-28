
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;
class course
{
public:
	int id;
	string name;
	string instructor;
	int enrolled;
	void counter();
	course();
	course(int i,string n,string ins,int e);
};
class student
{
public:
	int id;
	string name;
	vector<string>courses;
	student();
	student(int i,string n);
};
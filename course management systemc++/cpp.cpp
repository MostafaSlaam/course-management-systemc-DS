
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<vector>
#include"Header.h"
using namespace std;
course::course()
{
	id=0;
	name=" ";
	instructor=" ";
	enrolled=0;
}

course::course(int i, string n,string ins,int e)
{
	i=id;
	n=name;
	ins=instructor;
	e=enrolled;
}
void course::counter()
{
	enrolled++;
}
student::student()
{
	id=0;
	name=" ";
}
student::student(int i,string n)
{
	i=id;
	n=name;
}
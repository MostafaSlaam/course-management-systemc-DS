
#include<iostream>
#include<fstream>
#include<string>
#include<unordered_map>
#include<vector>
#include"Header.h"
using namespace std;






int main()
{

	vector<int> id_student;
	vector<course> cc;
	course c1;
	ifstream course_file("course.txt");
	if(!course_file.is_open())
	{
		cout<<"course file can't open";
	}
	else{



		char* l;
		char line[100];
		while(course_file.getline(line,100))

		{	  
			l = strtok(line," ");
			c1.id= atoi(l);
			l = strtok(NULL," ");
			c1.name = l;
			l = strtok(NULL," ");
			c1.instructor = l;
			l = strtok(NULL," ");
			c1.enrolled = atoi(l);
			cc.push_back(c1);

		}
		course_file.close();
	}




	unordered_map<int,student>ss;


	ifstream student_file("student.txt");
	if(!student_file.is_open())
	{
		cout<<"student file can't open";
	}
	else{

		char* l;
		char line[100];
		while(student_file.getline(line,100))

		{	  student s1;

		l = strtok(line," ");
		s1.id= atoi(l);
		id_student.push_back(s1.id);
		l = strtok(NULL," ");
		s1.name = l;
		do
		{
			l = strtok(NULL," ");
			if(l!=NULL)
			{
				s1.courses.push_back(l);
			}
		}while(l!=NULL);
		l = strtok(NULL," ");
		ss[s1.id]=s1;


		}
		student_file.close();

	}
	char c;
	do
	{

		int chooise;

		cout<<"---------------------------------------------"<<endl;
		cout<<"\t Course Management System"<<endl;
		cout<<"---------------------------------------------"<<endl;
		cout<<"1- Enroll new student to a specific course."<<endl;
		cout<<"2- Adding new course."<<endl;
		cout<<"3- Search for a student by an ID"<<endl;
		cout<<"4- Adding new courses to sutent"<<endl;	
		cin>>chooise;

		switch(chooise)
		{


		case 1:
			{


				cout<<"\t Available Courses:"<<endl;
				cout<<"ID\tName\tInstructor\tEnrolled student"<<endl;
				for(int i=0;i<cc.size();i++)
				{
					cout<<cc[i].id<<"\t";
					cout<<cc[i].name<<"\t";
					cout<<cc[i].instructor<<"\t";
					cout<<cc[i].enrolled<<"\n";
				}
				char x;
				char f;
				do
				{
					bool flag=false;

					student s;
k:
					cout<<"enter student id"<<endl;
					cin>>s.id;
					unordered_map<int,student>::iterator it;

					for(it=ss.begin();it!=ss.end();it++)
					{
						if(it->first==s.id)
						{
							cout<<"this id exist"<<endl;
							goto k;
						}
						else
						{

							continue;
						}
					}

					cout<<"enter student name"<<endl;
					cin>>s.name;


					do
					{

						int id;

z:

						cout<<"enter id course: "<<endl;
						cin>>id;

						for(int j=0;j<cc.size();j++)
						{
							if(id==cc[j].id)
							{
								flag=true;

							}
							continue;

						}
						if(flag==false)
						{
							cout<<"this course does not find"<<endl;
							goto z;
						}
						cc[id-1].counter();
						s.courses.push_back(cc[id-1].name);
						cout<<"if you want to add another course enter y to exit enter any key"<<endl;
						cin>>f;
					}while(f=='y'||f=='Y');




					fstream student_file("student.txt",ios::out|ios::app);
					if (student_file.fail())
					{
						cout << "Error opening file."<<endl;
					}
					student_file<<s.id<<" ";
					student_file<<s.name<<" ";
					int xx=s.courses.size();
					for(int i=0;i<xx;i++)
					{
						student_file<<s.courses[i]<<" ";
					}
					student_file<<endl;




					cout<<"to add another student press y to exit press any key"<<endl;
					cin>>x;
				}while(x=='Y'||x=='y');
				cout<<"thank u for using this application"<<endl;
				break;
			}


		case 2:
			{
				char y;
l:
				do
				{
					course nc;
					nc.id=cc.size()+1;
					cout<<"enter course name"<<endl;
					cin>>nc.name;
					for(int i=0;i<cc.size();i++)
					{
						if(cc[i].name==nc.name)
						{
							cout<<"this course exist"<<endl;
							goto l;
						}
						else
						{
							continue;
						}

					}
					cout<<"enter course instructor"<<endl;
					cin>>nc.instructor;
					nc.enrolled=0;
					cc.push_back(nc);


					cout<<"to add another student press y to exit press any key"<<endl;
					cin>>y;
				}while(y=='y'||y=='Y');
				cout<<"thank u for using this application"<<endl;
				break;
			}



		case 3:
			{
				char z;

				do
				{


					unordered_map<int,student>::iterator it1;

					int id;

a:
					cout<<"enter id :";
					cin>>id;
					unordered_map<int,student>::iterator it=ss.find(id);

					if(it==ss.end())
					{
						cout<<"this id not found"<<endl;
						goto a;
					}


					it1=ss.find(id);
					if(it1!=ss.end())

						for(int j=0;j<it1->second.courses.size();j++)
							cout<<"course :"<<it1->second.courses[j]<<endl;



					cout<<"to serch for another student press z to exit press any key "<<endl;
					cin>>z;
				}while(z=='z'||z=='Z');
				cout<<"thank u for using this application"<<endl;
				break;	
			}




		case 4:
			{
				char x;
				do
				{

					cout<<"\t Available Courses:"<<endl;
					cout<<"ID\tName\tInstructor\tEnrolled student"<<endl;
					for(int i=0;i<cc.size();i++)
					{
						cout<<cc[i].id<<"\t";
						cout<<cc[i].name<<"\t";
						cout<<cc[i].instructor<<"\t";
						cout<<cc[i].enrolled<<"\n";
					}
					int ids;
kk:
					cout<<"enter student id"<<endl;
					cin>>ids;

					unordered_map<int,student>::iterator it=ss.find(ids);

					if(it==ss.end())
					{
						cout<<"this id not found"<<endl;
						goto kk;
					}


d:

					int id;
					char v;
					bool idcourse=false;
					do
					{


						cout<<"enter id course: "<<endl;
						cin>>id;
						for(int i=0;i<cc.size();i++)
						{
							if(cc[i].id==id)
							{
								idcourse=true;
								break;
							}
						}

						if(idcourse==false)
						{
							cout<<"this course not found"<<endl;
							goto d;
						}

						unordered_map<int,student>::iterator it1=ss.find(ids);
						if(it1!=ss.end())
						{
							for(int i=0;i<it1->second.courses.size();i++)
							{
								if(it1->second.courses[i]==cc[id-1].name)
								{
									cout<<"this student enrolled in this course"<<endl;
									goto d;
								}
								else
								{continue;}
							}
						}



						cc[id-1].counter();
						ss[ids].courses.push_back(cc[id-1].name);
						cout<<"if u want to enter another course enter y and to out enter any key"<<endl;
						cin>>v;
					}while(v=='y'||v=='Y');
					cout<<"to edit another student press y else any key"<<endl;
					cin>>x;
				}while(x=='y'||x=='Y');

				fstream f("student.txt",ios::out|ios::trunc);
				fstream file("student.txt",ios::out);
				int size=id_student.size();
				for(int i=0;i<size;i++)
				{
					file<<ss[id_student[i]].id<<" ";
					file<<ss[id_student[i]].name<<" ";
					for(int j=0;j<ss[id_student[i]].courses.size();j++)
					{
						file<<ss[id_student[i]].courses[j]<<" ";
					}
					file<<endl;
				}
				file.close();

				break;






			}



		}



		cout<<"to repeat the main page enter y to out enter any key"<<endl;
		cin>>c;

	}while(c=='y'||c=='Y');
	cout<<"thank u for using this application"<<endl;






	fstream f("course.txt",ios::out|ios::trunc);
	fstream file("course.txt",ios::out);
	int size=cc.size();
	for(int i=0;i<size;i++)
	{
		file<<cc[i].id<<" ";
		file<<cc[i].name<<" ";
		file<<cc[i].instructor<<" ";
		file<<cc[i].enrolled<<" ";
		file<<endl;
	}
	course_file.close();










	return 0;
}
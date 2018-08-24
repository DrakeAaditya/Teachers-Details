#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
class teacher
{
	int tno;
	char tname[50];
	char gender;
	int age;
	int exp;
	char sub[30];
public:
	void enter();
	void show();
	void search(int);
	void update(int);
	void delete_rec(int);
};
void teacher::enter()
{
	cout<<"\nEnter Teacher No.";
	cin>>tno;
	cout<<"\nEnter Teacher Name";
	gets(tname);
	cout<<"\nEnter Gender   (M/F)";
	cin>>gender;
	cout<<"\nEnter Age";
	cin>>age;
	cout<<"\nEnter Subject";
	gets(sub);
	cout<<"\nEnter  Experience";
	cin>>exp;
	fstream t;
	t.open("teacher.dat",ios::out|ios::app|ios::binary);
	t.write((char*)this,sizeof(teacher));
	t.close();
}
void teacher::show()
{
	fstream t;
	t.open("teacher.dat",ios::in);
	while(!t.eof())
	{
		t.read((char*)this,sizeof(teacher));
		if(t.eof())
			break;
		cout<<"\nTeacher No."<<tno;
		cout<<"\nTeacher Name=";
		puts(tname);
		cout<<"\nGender="<<gender;
		cout<<"\nAge="<<age;
		cout<<"\nExperience="<<exp;
		cout<<"\nSubject=";
		puts(sub);
	}
		t.close();
}
void teacher::search(int r)
{
	fstream t;
	t.open("teacher.dat",ios::in);
	while(!t.eof())
	{
		t.read((char*) this,sizeof (teacher));
		if(tno==r)
		{
			cout<<endl<<"Teacher No."<<tno;
			cout<<endl<<"Teacher's Name";
			puts(tname);
			cout<<"Age="<<age<<endl;
			cout<<"Gender="<<gender<<endl;
			cout<<"Subject="<<sub<<endl;
			cout<<"Experience="<<exp<<endl;
		}
	}
	t.close();
}
void teacher::delete_rec(int k)
{
	fstream t1;
	fstream t2;
	t1.open("teacher.dat",ios::in);
	t2.open("teacher.dat",ios::out|ios::binary);
	while(t1.eof())
	{
		t1.read((char*)this,sizeof(teacher));
		if(t1.eof())
			break;
		if(tno==k)
		continue;
		t2.write((char*)this,sizeof(teacher));
	}
	t1.close();
	t2.close();
	t1.open("teacher.dat",ios::out|ios::binary|ios::trunc);
	t2.open("temp.dat",ios::in);
	while(!t2.eof())
	{
		t2.read((char*)this,sizeof(teacher));
		if(t2.eof())
			break;
		t2.write((char*)this,sizeof(teacher));
	}
	t1.close();
	t2.close();
}
void teacher::update(int r)
{
	fstream t;
	int p;
	t.open("teacher.dat",ios::in|ios::out);
	while(!t.eof())
	{
		t.read((char*)this,sizeof(teacher));
		if(tno==r)
		{
			cout<<"Teacher No."<<endl;
			cout<<tno;
			cout<<"Teacher Name"<<endl;
			puts(tname);
			cout<<"Gender"<<endl;
			cout<<gender;
			cout<<"Age"<<endl;
			cout<<age;
			cout<<"Subject"<<endl;
			puts(sub);
			cout<<"Enter Experience"<<endl;
			cin>>exp;
			p=t.tellg()-sizeof(teacher);
			t.seekg(p);
			t.write((char*)this,sizeof(teacher));
		}
	}
	t.close();
}
void main()
{
	teacher e;
	char t='y';
	int ch;
	clrscr();
do
{
	clrscr();
	cout<<"1-Enter the details of a new teacher"<<endl;
	cout<<"2-Show the details of the teachers"<<endl;
	cout<<"3-Search the details according to the Teacher No."<<endl;
	cout<<"4-Delete the detial of teacher"<<endl;
	cout<<"5-Update the details"<<endl;
	cout<<"6-Exit"<<endl;
	cout<<"Enter your choice";
	cin>>ch;
	switch(ch)
	{
		case 1:
			e.enter();
			break;
		case 2:
			e.show();
			break;
		case 3:
			cout<<"Enter the teacher no.";
			int t;
			cin>>t;
			e.search(t);
			break;
		case 4:
			cout<<"Enter the teacher no.";
			int y;
			cin>>y;
			e.delete_rec(y);
			break;
		case 5:
			cout<<"Enter the teacher no.";
			int f;
			cin>>f;
			e.update(f);
			break;
		case 6:
			exit(0);

	}
	cout<<endl<<"Do you want to continue";
	cin>>t;
	}while((t=='y')||(t=='Y'));
}

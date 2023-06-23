#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

 using namespace std;
 
 class student
 {
 	private:
 	char name[20],course[20],rollno[20],email[20],address[20];
 	public:
 		void adddetail();
 		void displaydetail();
 		void modifydetail();
 		void searchdetail();
 		void deletedetail();
 };
 
 void student::adddetail() 
 {
 	system("cls");
 	fstream file;
 	cout<<"\n\t\t\tenter the name of student:";
 	cin.sync();
 	cin.getline(name,20);
 	cout<<"\n\t\t\tenter the course of student:";
 	cin.sync();
 	cin.getline(course,20);
 	cout<<"\n\t\t\tenter the roll of student:";
 	cin.sync();
 	cin.getline(rollno,20);
 	cout<<"\n\t\t\tenter the email of student:";
 	cin.sync();
 	cin.getline(email,20);
 	cout<<"\n\t\t\tenter the address of student:";
 	cin.sync();
 	cin.getline(address,20);
 	file.open("official.txt",ios::app|ios::out);
 	file<<name<<"\n"<<course<<"\n"<<rollno<<"\n"<<email<<"\n"<<address<<"\n";
 	file.close();
 }
 
 void student::displaydetail()
 {
 	system("cls");
 	string name,course,rollno,email,address;
 	int total=1;
 	fstream file;
 	cout<<"\n\t\t------------------student detail---------------";
 	cout<<"\n\t\t------------------------------------------------";
 	file.open("official.txt",ios::in);
 	if(!file)
 	{
 		cout<<"\n\t\t No data is available"<<endl;
	 }
	 else
	 {
	 	getline(file,name);getline(file,course);getline(file,rollno);getline(file,email);getline(file,address);
	 	while(!file.eof())
	 	{
	 		cout<<"\n\t\t\tstudent no:"<<total++<<endl;
			cout<<"\t\t\tNAME:"<<name<<endl;
			cout<<"\t\t\tcourse:"<<course<<endl;
			cout<<"\t\t\tROLLNO:"<<rollno<<endl;
			cout<<"\t\t\temail:"<<email<<endl;
			cout<<"\t\t\taddress:"<<address<<endl;
			cout<<"\t\t\t--------------------------"<<endl;
			getline(file,name);getline(file,course);getline(file,rollno);getline(file,email);getline(file,address);
		}
		if(total==1)
		{
		
		cout<<"\n\t\tNO data is available:"<<endl;
	    }
	 }
	 file.close();
 }
 void student::modifydetail()
 {
 	system("cls");
 	fstream file,file1;
 	int found=0;
 	string name1,course1,rollno1,email1,address1;
 	string roll;
 	cout<<"\n\t\t----------------------------------";
 	cout<<"\n\t\t----------[MODIFY DETAIL]----------";
 	file.open("official.txt",ios::in);
 	if(!file)
 	{
 	  cout<<"\n\t\t OPening file sending error::";	
	}
	else
	{
		cout<<"\n\t\t enter roll no you want to modify:";
		cin>>roll;
		file1.open("officiall.txt",ios::app|ios::out);
		getline(file,name1);getline(file,course1);getline(file,rollno1);getline(file,email1);getline(file,address1);
	 	while(!file.eof())
	 	{
	 	    if(roll!=rollno1)
	 	    {
			 
			file1<<name1<<"\n"<<course1<<"\n"<<rollno1<<"\n"<<email1<<"\n"<<address1<<"\n";
		    }
		    else
		    {
		    	cout<<"enter the name of student:"<<endl;
 	            cin.sync();
 	            cin.getline(name,20);
 	            cout<<"enter the course of student:"<<endl;
             	cin.sync();
             	cin.getline(course,20);
 	            cout<<"enter the roll of student:"<<endl;
 	            cin.sync();
 	            cin.getline(rollno,20);
             	cout<<"enter the email of student:"<<endl;
             	cin.sync();
            	cin.getline(email,20);
            	cout<<"enter the address of student:"<<endl;
            	cin.sync();
            	cin.getline(address,20);
            	found++;
            	file1<<name<<"\n"<<course<<"\n"<<rollno<<"\n"<<email<<"\n"<<address<<"\n";
			}
			getline(file,name1);getline(file,course1);getline(file,rollno1);getline(file,email1);getline(file,address1);
		}
		if(found==0)
		{
			cout<<"\n\t\tEntered roll no is wrong or NO student::";
			getch();
		}
		file.close();
		file1.close();
		remove("official.txt");
		rename("officiall.txt","official.txt");
		
	}
 }
 void student::searchdetail()
 {
 	system("cls");
 	fstream file;
 	int found=0;
 	string name,course,rollno,email,address;
 	string roll;
 	file.open("official.txt",ios::in);
 	if(!file)
 	{
 		cout<<"FIle opening countering error::"<<endl;
	 }
	 else
	 {
	 	cout<<"\n\t\t Enter roll no of student you want to search:";
	 	cin>>roll;
	 	getline(file,name);getline(file,course);getline(file,rollno),getline(file,email);getline(file,address);
	 	while(!file.eof())
	 	{
	 		if(roll==rollno)
	 		{
	 		  cout<<"\n\t\t Name of student:"<<name;
			  cout<<"\n\t\t Course of student:"<<course;
			  cout<<"\n\t\t Roll no of student:"<<rollno;
			  cout<<"\n\t\t Email of student:"<<email;
			  cout<<"\n\t\t Address of student:"<<address;
			  getch();
			  found++;	
			}
			getline(file,name);getline(file,course);getline(file,rollno),getline(file,email);getline(file,address);
			
		 }
		 if(found==0)
		 {
		 	cout<<"\n\t\t Incorrect rollno:::try again";
		 	getch();
		 }
	 }
	 file.close();
 }
 void student::deletedetail()
 {
 	system("cls");
 	fstream file,file1;
 	int found=0;
 	string name1,course1,roll1,email1,address1;
 	string roll;
 	file.open("official.txt",ios::in);
 	if(!file)
 	 {
 		cout<<"OPENING FILE GIVING ERROR"<<endl;
	 }
	 else
	 {
	 	cout<<"\n\t\t Enter the roll no of student::";
	 	cin>>roll;
	 	file1.open("officiall.txt",ios::app|ios::in);
	 	getline(file,name1);getline(file,course1);getline(file,roll1);getline(file,email1);getline(file,address1);
	 	while(!file.eof())
	 	{
	 		if(roll!=roll1)
	 		{
	 			file1<<name1<<"\n"<<course1<<"\n"<<roll1<<"\n"<<email1<<"\n"<<address1<<"\n";
	 			found=1;
			 }
			 
			  
		   getline(file,name1);getline(file,course1);getline(file,roll1);getline(file,email1);getline(file,address1);
           		   
		} 
		if(found)
		{
			cout<<"\n\t\t INCORRECT ROLL NO ENTERED::OOPS";
			getch();
		 }
		 else
		 {
		 cout<<"\n\t\t Successfull deleted::";
		 getch();
	     }
		 file.close();
		 file1.close();
		 remove("official.txt");
		 rename("officiall.txt","official.txt");
	 }
 }
 
 int main()
 {
 	menu:
 	int choice;
 	student proj;
 	system("cls");
 	
 	cout<<"\n\t\t\t----------------------------------";
 	cout<<"\n\t\t\t-------[STUDENT DATABASE]----------";
 	cout<<"\n\t\t\t\t 1-> add student";
 	cout<<"\n\t\t\t\t 2-> display student";
 	cout<<"\n\t\t\t\t 3-> Modify detail";
 	cout<<"\n\t\t\t\t 4-> Search detail";
 	cout<<"\n\t\t\t\t 5-> delete detail";
 	cout<<"\n\t\t\t\t 6-> exit";
 	cout<<"\n\t\t\t------------------------------------";
 	do
 	{
	 
 	  cout<<"\nenter your choice:";
 	  cin>>choice;
 	  switch(choice)
 	  {
 	  	case 1:proj.adddetail();
 	  	      goto menu;
 	         break;
 	         
 	    case 2:proj.displaydetail();
 	           getch();
 	           system("cls");
 	           goto menu;
 	           break;
 	    case 3:proj.modifydetail();
 	           goto menu;
 	          break;
 	    case 4:proj.searchdetail();
 	          goto menu;
 	          break;
 	    case 5:proj.deletedetail();
 	          goto menu;
 	          break;
 	    case 6:exit(0);
 	         break;
 	    default:
 	    	cout<<"no such choice: try again;;;"<<endl;
 	         
	   }
    }while(choice!=6);
 }

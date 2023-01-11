#include<iostream>
#include<fstream>
using namespace std;
class student
{
private:
    string name,fname,mname,dob,course,branch,pno;
    string studentID, rollno;
    int sum1 =0 ,m,choice;
    char adress[40];
public:
    void add_record()
    {
        system("color 6");
	    sum1=0;
		ofstream fout;
		fout.open("record.txt", ios::out | ios::app);
		{
		    system("cls");
		    cout << "\t\t\t\t*****ENTER RECORD*****" << endl;
		    cout <<"\t\t\t\t----------------------"<<endl;
		    cout << "\nENTER STUDENT NAME:" << endl;
		    cin>>name;
		    cout<<"ENTER STUDENT FATHER'S NAME:"<<endl;
		    cin >> fname;
		    cout<<"ENTER STUDENT MOTHER'S NAME:"<<endl;
		    cin >> mname;
		    cout<<"ENTER DATE OF BIRTH:"<<endl;
		    cin>>dob;
		    cout<<"ENTER COURSE:"<<endl;
		    cin>>course;
		    cout<<"ENTER BRANCH:"<<endl;
		    cin>>branch;
		    cout<<"ENTER STUDENT ID:"<<endl;
		    cin>>studentID;
		    cout << "ENTER ROLLNO:" << endl;
		    cin >> rollno;
		    cout<<"ENTER PHONE NUMBER:"<<endl;
		    cin>>pno;
		    cout << "ENTER ADRESS:" << endl;
		    cin >> adress;
		    cout<<endl;
		    cout<<"\t\t\tNOTE! MARKS OUT OF 100..."<<endl;
		    cout<<"\n\tSo, How many Subject's Marks You Want to Enter:"<<endl;
		    cin>>choice;
		    for(int i=1;i<=choice;i++)
		{
         s:
		cout << "ENTER MARKS OF SUBJECT NO "<<i<<":"<< endl;
		cin >> m;
		if(m>100)
		{
			cout<<"PLEASE ENTER MARKS OUT OF 100"<<endl;
			goto s;
		}
		else
		    {
		        sum1 = sum1 + m;
	        }
	    }
        fout << name<< " " << fname << " " <<mname << " " << dob << " " << course << " " << branch << " " << studentID << " " << rollno << " " << pno << " " << adress << " " << sum1 << " "  << endl;
		fout.close();
		}
	}
	void show()
	{
		system("color B");
		int a = 0;
		ifstream fin;
		fin.open("record.txt", ios::in);
		fin >> name >> fname >> mname >> dob >> course >> branch >> studentID >> rollno >> pno >> adress >> sum1;
		if (!fin)
		{
			cout << "YET NO RECORD ENTER" << endl;
		}
		else
			while (!fin.eof())
			{
				a++;
				cout<<"\nRECORD NO:"<<a<<endl;
				cout << "\n\t1)" << "NAME: " << name << endl;
				cout << "\t2)" << "FATHER'S NAME: " << fname << endl;
				cout << "\t3)" << "MOTHER'S NAME: " <<mname <<endl;
				cout << "\t4)" << "DATE OF BIRTH: " << dob << endl;
				cout << "\t5)" << "COURSE: " << course << endl;
				cout << "\t6)" << "BRANCH: " << branch << endl;
				cout << "\t7)"<< "STUDENT ID:"<< studentID<<endl;
				cout << "\t8)" << "ROLLNO: " << rollno << endl;
				cout << "\t9)" << "PHONE NUMBER: " << pno << endl;
				cout << "\t10)" << "ADRSSS: " << adress << endl;
				cout << "\t11)" << "MARKS: " << sum1 << endl;
				cout << "............................." << endl;

				fin >> name >> fname >> mname >> dob >> course >> branch >> studentID >> rollno >> pno >> adress >> sum1;
			}
	}
	void search_record()
	{
		system("color C");
	    int a=0,f=0;
	    string stID;
		ifstream sr;
		sr.open("record.txt", ios::in);
		sr >> name>> fname >>mname >> dob >> course >> branch >> studentID >> rollno >> pno >> adress >>sum1 ;
		cout << "ENTER STUDENT ID TO SEARCH A RECORD:" << endl;
		cin >> stID;
		if (!sr)
		    {
			    cout << "SORRY! NO RECORD FOUND.";
			}
		else
			while (!sr.eof())
			{
				if (stID==studentID)
				{
				f = 1;
					a++;
				cout<<"\nRECORD NO:"<<a<<endl;
				cout << "\n\t1)" << "NAME: " << name << endl;
				cout << "\t2)" << "FATHER 'S NAME: " << fname << endl;
				cout << "\t3)"<<"MOTHER'S NAME: "<< mname <<endl;
				cout << "\t4)" << "DATE OF BIRTH: " << dob << endl;
				cout << "\t5)" << "COURSE: " << course << endl;
				cout << "\t6)" << "BRANCH: " << branch << endl;
				cout << "\t7)" << "ROLLNO: " << rollno << endl;
				cout << "\t8)" << "PHONE NUMBER: " << pno << endl;
				cout << "\t9)" << "ADRSSS: " << adress << endl;
				cout << "\t10)" << "MARKS: " << sum1 << endl;
				cout << "............................." << endl;
     		break;
				}
				else
				sr >> name >>fname >> mname >> dob >> course >> branch >> studentID >> rollno >> pno >>adress>>sum1;
			}
		if(f==0)
		{
			cout<<"THIS STUDENT ID HAS NO RECORD"<<endl;
		}
		sr.close();
	}
void delete_record()
	{
	 system("color F");
    	int f=0;
    	string stID1;
		ifstream delrec;
		delrec.open("record.txt", ios::in);
		delrec >> name >> fname >>mname >> dob >> course >> branch >> studentID >> rollno >> pno >> adress >>sum1 ;
		ofstream fout1;
		fout1.open("delete.txt", ios::out);
		if (!fout1)
            {
			cout << "Error!" << endl;
			}
		    else
		    {
		cout << "ENTER STUDENT ID TO DELETE RECORD:" << endl;
		cin >> stID1;
		if (!delrec)
		{
		cout<<"SORRY! NO RECORD FOUND";
		}
		else
			while (!delrec.eof())
			{
				if (stID1==studentID)
				{
				f = 1;
					cout << "RECORD DELETED SUCCESSFULLY" << endl;
				}
				else
                fout1<<name << " " <<fname << " " <<mname << " " << dob << " " << course << " " << branch << " " << studentID << " " << rollno << " " << pno << " " << adress << " " << sum1 << " " <<endl;
				delrec >> name >> fname >> mname >> dob >> course >> branch >>studentID >> rollno >>pno>>adress>>sum1 ;
			}
		    if(f==0)
		    {
			    cout<<"THIS STUDENT ID HAVE NO RECORD"<<endl;
		    }
		    delrec.close();
		    fout1.close();
		    remove("record.txt");
		    rename("delete.txt", "record.txt");
	   }
	}
	void update_record()
	{
	    system("color 5");
		int f1=0;
		string stID2;
		ifstream uprec;
		uprec.open("record.txt", ios::in);
		uprec >> name>> fname >> mname >> dob >> course >> branch >> studentID >> rollno >> pno >> adress >>sum1 ;
		ofstream fout2;
		fout2.open("update.txt", ios::out);
		if (!fout2)
		{
		 cout << "Error!" << endl;
		}
		else
		{
		cout << "ENTER STUDENT ID TO UPDATE A RECORD:" << endl;
		cin >> stID2;
		if (!uprec)
		{
		cout<<"SORRY! NO RECORD FOUND";
		}
		else
			while (!uprec.eof())
			{

				if (stID2 == studentID)
				{
				f1 = 1;
            system("cls");
		cout << "\t\t\t*****ENTER NEW RECORD*****" << endl;
		cout << "ENTER  NEW NAME:" << endl;
		cin >> name;
		cout<<"ENTER NEW FATHER'S NAME:"<<endl;
		cin >> fname;
		cout<<"ENTER NEW MOTHER'S NAME:"<<endl;
		cin>>mname;
		cout<<"ENTER NEW DOB:"<<endl;
		cin>> dob;
		cout<< "ENTER NEW COURSE:"<<endl;
		cin>> course;
		cout<<"ENTER NEW BRANCH:"<<endl;
		cin>>branch;
		cout<<"ENTER NEW STUDENT ID:"<<endl;
		cin>>studentID;
		cout << "ENTER NEW  ROLLNO" << endl;
		cin >> rollno;
		cout<<"ENTER NEW PHONE NUMBER:"<<endl;
		cin>>pno;
		cout << "ENTER  NEW ADRESS:" << endl;
		cin >> adress;
		cout<<endl;
	   cout<<"\t\t\tNOTE! MARKS OUT OF 100"<<endl;
		    cout<<"\n\tSo, How many Subject's Marks You want to Enter:"<<endl;
		cin>>choice;
		for(int i=1;i<=choice;i++)
		{
         s:
		cout << "ENTER THE MARKS OF SUBJECT "<<i<<":"<< endl;
		cin >> m;
		if(m>100)
		{
			cout<<"PLEASE ENTER MARKS OUT OF 100"<<endl;
			goto s;
		}
		else
		{
		sum1 = sum1 + m;
	    }
	      }
            fout2<< name<< " " <<fname << " " <<mname << " " << dob << " " << course << " " << branch << " " << studentID << " " << rollno << " " << pno << " " << adress << " " << sum1 << " " <<endl;
        }
        else
            fout2<<name << " " << fname << " " << mname << " " << dob << " " << course << " " << branch << " " << studentID << " " << rollno << " " <<pno << " " << adress << " " << sum1 << " " <<endl;
				uprec >> name >> fname >> mname >> dob >> course >> branch >> studentID >> rollno >> pno >> adress >> sum1 ;
			}
		if(f1==0)
		{
			cout<<"THIS STUDENT ID HAS NO RECORD"<<endl;
		}
		uprec.close();
		fout2.close();
		remove("record.txt");
		rename("update.txt", "record.txt");
	  }
    }
};
int main()
{
    student ob;
    char x;
    do {
		long int choice;
		char goback;
		 char pass[10];
		    	system("color 4");
		 	cout<<"\n\n";
		 	cout<<"\t\t\t\t*************************************"<<endl;
		 	cout<<"\t\t\t\t* STUDENT RECORD MAINTENANCE SYSTEM *"<<endl;
		 	cout<<"\t\t\t\t*************************************"<<endl;
		 	cout<<"\n\n\n\n\nPRESENTED BY:";
		 	cout<<"\n\t\tNAME: Anshul Tripathi\n\t\tUNIVERSITY ROLL NO.: 2017311\n\t\tSEC: CE-SPL\n\t\t\n";

		 	    system("pause");
		 		system("cls");
		 		system("color 1");
			string password ="geu";
			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t*****LOGIN*****"<<endl;
			cout << "\t\t\t\t\t\t---------------"<<endl;
			cout<<"\n\n\n\n\t\t\t\tInstitute: GRAPHIC ERA Hill UNIVERSITY DEHRADUN";
		cout << "\n\t\t\t\tPassword : ";
		cin >> pass;
		system("cls");
		if (pass == password)
		{
			do
			  {
				system("color 2");
				cout<<"\t\t\t*****MAIN MENU*****"<<endl;
				cout<<"\t\t\t-------------------\n"<<endl;
				cout << "\t\t\t1)ENTER RECORD" << endl;
				cout << "\t\t\t2)SHOW RECORD" << endl;
				cout << "\t\t\t3)SEARCH RECORD" << endl;
				cout << "\t\t\t4)DELETE RECORD" << endl;
				cout << "\t\t\t5)UPDATE RECORD" << endl;
				cout << "\t\t\t6)LOGOUT" << endl;
				cout << "Enter Your Choice:\n";
				cin >> choice;
				system("cls");
				switch (choice)
				{
				case 1:
					ob.add_record();
					 break;
				case 2:
					ob.show();
					 break;
				case 3:
					ob.search_record();
					 break;
				case 4:
					ob.delete_record();
					 break;
				case 5:
					ob.update_record();
					 break;
	            case 6:
					exit(0);
				default:
					cout << "Invalid Choice" << endl;
				}
				cout << "Enter y to go back to Main Menu." << endl;
				cin >> goback;
				system("cls");
			  }
			 while
			 (goback == 'y' || goback == 'Y');
			 system("cls");
		 }
		else
		 {
			cout<<"\nOPPS! WRONG PASSWORD\n"<<endl;
		 }
		 cout << "\nENTER Y TO TRY AGAIN" << endl;
		 cin >> x;
	}
	while (x == 'y' || x == 'Y');
}

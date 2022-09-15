#include<iostream>
#include<stdio.h>
#include<strings.h>
#include<string.h>
#include<fstream>


using namespace std;

class Books{
	public:
	char Book_id[5];
	char Book_name[10];
	char Book_ammount[5];
	char Book_Price[10];
	char Book_shelf[5];
};

void del()
{
	int flag=0;
	int way;
	
	char bname[20];
    char id[5];
	char ee[1];
    
	cout<<"\t1. Delete by id press"<<endl;
	cout<<"\t2. Delete by name press"<<endl;
    cout<<"Enter your choise : ";
	cin>>way;	 
	if(way==1)
    {
        cout<<"Enter Book id to delete : ";
        cin>>id;
	}
	else if(way==2)
    {
        cout<<"Enter Book name to delete : ";
        cin>>bname;}
        Books s;
        fstream myfile;
        fstream new_file;
        myfile.open("test.txt",ios::in);//read
        new_file.open("Temp.txt",ios::out);//write

        while(!myfile.eof())
        {
		    myfile.getline(s.Book_id,4,'|');	
			myfile.getline(s.Book_name,5,'|');
	 		myfile.getline(s.Book_ammount,9,'|');
	 		myfile.getline(s.Book_Price,12,'|');
	 		myfile.getline(s.Book_shelf,12,'\n');
         	
		 	if(way==1&&strcmp(id,s.Book_id	)!=0&&strcmp(ee,s.Book_id)!=0)
            {
                {
                    new_file<<s.Book_id<<"|"<<s.Book_name<<"|"<<s.Book_ammount<<"|"<<s.Book_Price<<"|"<<s.Book_shelf<<"\n";
                } 
        
                if(strcmp(id,s.Book_id)==0)
                {
                    flag=1;
                }
            }

            else if(way==2&&strcmp(bname,s.Book_name	)!=0&&strcmp(ee,s.Book_name	)!=0)
            {
                {
                    new_file<<s.Book_id<<"|"<<s.Book_name<<"|"<<s.Book_ammount<<"|"<<s.Book_Price<<"|"<<s.Book_shelf<<"\n";

                } 
                
                if(strcmp(bname,s.Book_name)==0)
                {
                    flag=1;
                }
            }

    }

    myfile.close();
	new_file.close();
    remove("test.txt");
    rename("Temp.txt","test.txt");

	if(flag==0)
	{
        cout<<"Not found"<<endl; 
    }

}

void update()
{
	int h=0;
	Books s;
	char comp[10];
	char ch[10];
	int x;
	cout<<"Press 1 to continue: ";
	cin>>x;
    if(x==1)
    {
        cout<<"Enter the name : ";
        cin>>comp;
        cout<<"Enter the new : ";
        cin>>ch;
    }

	fstream myfile , new_myfile ;
    myfile.open("Temp.txt",ios::out);//write
    new_myfile.open("test.txt",ios::in);//read
    while(!new_myfile.eof())
    {
        new_myfile.getline(s.Book_id,4,'|');	
 	    new_myfile.getline(s.Book_name,4,'|');
        new_myfile.getline(s.Book_ammount,8,'|');
        new_myfile.getline(s.Book_Price,11,'|');
        new_myfile.getline(s.Book_shelf,11,'\n');

        if(strcmp(comp,s.Book_name)!=0)
        {
            myfile<<s.Book_id<<"|"<<s.Book_name<<"|"<<s.Book_ammount<<"|"<<s.Book_Price<<"|"<<s.Book_shelf<<"\n";
	    }

        else if(strcmp(comp,s.Book_name)==0)
        {
            h++;
            if(h>0)
            {
                cout<<"Approve if record is to be updated (y or n)"<<endl;
                cout<<s.Book_id<<"|"<<s.Book_name<<"|"<<s.Book_ammount<<"|"<<s.Book_Price<<"|"<<s.Book_shelf<<"\n";
            
                char k;
                cout<<" y-n";
                cin>>k; 
            }
            if(h=='y')
            {
                myfile<<ch<<"|"<<s.Book_ammount<<"|"<<s.Book_Price<<"|"<<s.Book_shelf<<"\n";
            }  
        }
	
	getch();
	break;

	}

    myfile.close();
	new_myfile.close();
	remove("test.txt");
    rename("Temp.txt","test.txt");
	  
}

void search()
{
	Books s;
	char ch[10];
	int choice;
	int found=0;
	cout<<"\t1. Search by id"<<endl;
	cout<<"\t2. Search by name"<<endl;
	cout<<"Enter your choise : ";
	cin>>choice;

	switch(choice)
	{
		case 1:
			cout<<"Enter the id : ";
			cin>>ch;
			break;
		case 2:
			cout<<"Enter the name : ";
			cin>>ch;
			break;
	}
	
	fstream myfile;
	myfile.open("test.txt",ios::in);
	while(!myfile.eof())
	{
		myfile.getline(s.Book_id,4,'|');	
		myfile.getline(s.Book_name,4,'|');
		myfile.getline(s.Book_ammount,4,'|');
		myfile.getline(s.Book_Price,4,'|');
		myfile.getline(s.Book_shelf,4,'\n');
		if(choice==1)
        {
			if(strcmp(ch,s.Book_id)==0)
            {
				cout<<"The available record is: "<<endl;
                cout<<s.Book_id<<" "<<s.Book_name<<" "<<s.Book_ammount<<" "<<s.Book_Price<<" "<<s.Book_shelf<<" "<<endl;
                found=1;
			}
		}

		else if(choice==2)
        {
			if(strcmp(ch,s.Book_name)==0 )
            {
                cout<<"The available record is: "<<endl;
                cout<<s.Book_id<<"|"<<s.Book_name<<" "<<s.Book_ammount<<" "<<s.Book_Price<<" "<<s.Book_shelf<<" "<<endl;
                found=1;
            }
        }

	}
	if(found==0)
    {
        cout<<"Record not found";
		myfile.close();
		cin.get();
		std::cout<<" "<<endl;
    }
		
}

void view()
{
	Books s;
	fstream file1;
	file1.open("test.txt",ios::in);

	while(!file1.eof())
    {
		file1.getline(s.Book_id,4,'|');	
		file1.getline(s.Book_name,4,'|');
		file1.getline(s.Book_ammount,8,'|');
		file1.getline(s.Book_Price,11,'|');
		file1.getline(s.Book_shelf,11,'\n');

		cout<<"ID: "<<s.Book_id<<"\n Book name: "<<s.Book_name<<"\n Book ammount: "<<s.Book_ammount<<"\n Book Price: "<<s.Book_Price<<"\n Book shelf : "<<s.Book_shelf<<" "<<endl;
        getch();
	}
	file1.close();
}

void insert()
{
	char id[5];
	char included_id[5];
	int flag=0;
	Books d;
	
	fstream myfile;
	myfile.open("test.txt",ios::out|ios::app);
	cout<<endl;
	cout<<"Enter Book ID : ";
	cin>>id;

	fstream myfile2;
	myfile2.open("test.txt",ios::in);
	while(!myfile2.eof())
    {
		myfile2.getline(included_id,4,'|');	
		myfile2.getline(d.Book_name,4,'|');
		myfile2.getline(d.Book_ammount,8,'|');
		myfile2.getline(d.Book_Price,11,'|');
		myfile2.getline(d.Book_shelf,11,'\n');

        if(strcmp(id,included_id)==0)
        {
            flag=1;
            
            myfile2.close();
            break;
        } 

	}
    
    if(flag==1)
	{
		cout<<"This id is already included by the file, change id"<<endl;
		cout<<"Enter Book ID : ";
		cin>>id;
		flag=0;
	}

	cout<<endl<<"Enter Book Name : ";
	cin>>d.Book_name;
	cout<<endl<<"Enter Book Ammount : ";
	cin>>d.Book_ammount;
	cout<<endl<<"Enter Book Price : ";
	cin>>d.Book_Price;
	cout<<endl<<"Enter Book Shelf : ";
	cin>>d.Book_shelf;
	cout<<endl;
	myfile<<id<<"|"<<d.Book_name<<"|"<<d.Book_ammount<<"|"<<d.Book_Price<<"|"<<d.Book_shelf<<"\n";	
	
	myfile.close();
}
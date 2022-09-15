//  This program is for a bookshop
//  and in this program we expect to have a register, login, logout and an exit function
// We also expect the client with the ability to login to be able to view the details of the books requested for

#include<iostream>
#include<strings.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<conio.h>

#include "bookfile.h"

using namespace std;

void login();
void registr();
void inside();
void regin();
// void del();

// class Books{
// 	public:
// 		char Book_id[5];
// 		string Book_name;
// 		char Book_ammount[5];
// 		char Book_Price[10];
// 		char Book_shelf[5];
// };

class reader
{
    public:
        string readerName;
        int readerNumber;
        string passwd;
        char phone[20];
};

int main()
{
    int auth;
    // char pass[20], name[20];
    cout<<"\nWelcome to GENIOUS BOOKS"<<endl;
    cout<<"You are required to login to the system inorder to use the system"<<endl;

    cout<<"\tTo choose use our menu options(1, 2, 3 or 4)"<<endl;
    cout<<"\t1.\tLogin"<<endl;
    cout<<"\t2.\tRegister:"<<endl;
    cout<<"\t3.\tView Company details"<<endl;
    cout<<"\t4.\tExit"<<endl;
    cout<<"\nEnter your option:    ";
    cin>>auth;
    switch (auth)
    {
    case 1:
        system("cls");
        login();
        // inside();
        cin.get();
        break;
    case 2:
        system("cls");
        registr();
        cout<<"\nYou'll be automatically redirected to the main menu to login."<<endl;
        main();
        cin.get();
        break;

    case 3:
        system("cls");
        cout<<"\t\tWELCOME TO GENIOUS BOOKS"<<endl;
        cout<<"\tOur Company is a credibale one that has workd for so many years dealing in lending, selling and borrowing of literature"<<endl;
        cout<<"\tIn this field we're glad to knw that we're growing a generation of literates and the pholosophers of tomorrow"<<endl;
        cout<<"\tWe appreciate for all the support both financially and good counsel"<<endl;
        cin.get();
        getch();
        main();
        break;

    case 4:
        system("cls");
        cout<<"Thankyou for using our services, Goodluck"<<endl;
        cin.get();
        break;

    default:
        system("cls");
        cout<<"\nAn error occured, try again later"<<endl;
        cout<<" "<<endl;
        cout<<"Thankyou for using our services, Goodluck"<<endl;
        cin.get();
        break;
    }
    return 0;
}


void registr()
{
    system("cls");
    string regName, regPass;
    cout<<"Enter Username:  ";
    cin>>regName;
    cout<<"\nEnter Password:    ";
    cin>>regPass;
    ofstream reg("database.txt", ios::app);
    reg<<regName<<' '<<regPass<<endl;
    system("cls");
    cout<<"Your registration has been successful";
    main();
}

void login()
{
    system("cls");
    int exists;
    string name, pass, u, p;
    cout<<"Enter Username:  ";
    cin>>name;
    cout<<"\nEnter Password:    ";
    cin>>pass;
    ifstream input("database.txt");

    while(input>>u>>p)
    {
        if(u==name && p==pass)
        {
            exists=1;
        }
    }
    input.close();

    if(exists ==1 )
    {
        cout<<" "<<endl;
        cout<<"\nHello "<<name<<" Thanks for showing up"<<endl;
        // cin.get();
        inside();
    }
    else
    {
        cout<<"Sorry we encoutered an error during your login"<<endl;
        main();
    }

}

void inside()
{
    int choice;

    cout<<"Welcome back our esteemed customer, we're glad to have you again:"<<endl;
    cout<<"Follow the following procedure to use our services"<<endl;

    cout<<"\t1. To add books"<<endl;
    cout<<"\t2. View books"<<endl;
	cout<<"\t3. Search books"<<endl;
	cout<<"\t4. Delete books"<<endl;
	cout<<"\t5. Update books"<<endl;
	cout<<"\t6. Exit"<<endl;

    cout<<"Enter your preferred option to continue: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            system("cls");
            insert();
            break;
        case 2:
            system("cls");
            view();
            break;
        case 3:
            system("cls");
            search();
            break;
        case 4:
            system("cls");
            del();
            break;
        case 5:
            system("cls");
            update();
            break;
        case 6:
            system("cls");
            exit(0);
            break;
        default:
            system("cls");
            cout<<"Enter valid option"<<endl;
            main();
            break;
    }
}
// void inside()
// {
//     int option, number;
//     Books bName;
//     reader rName, rPass, rNumber,rTel;
//     char name[20];

//     cout<<"Welcome back our esteemed customer, we're glad to have you again:"<<endl;
//     cout<<"Follow the following procedure to use our services"<<endl;
//     cout<<"\t1.  Borrow a book"<<endl;
//     cout<<"\t2.  Return a book"<<endl;
//     cout<<"\t3.  Inquiries"<<endl;
//     cout<<"Take an option to continue:  ";
//     cin>>option;
//     switch (option)
//     {
//         case 1:
//             cout<<" "<<endl;
//             cout<<"\nWhat book would you like to borrow"<<endl;
//             cin>>name;
//             if (name==bName.Book_name)
//             {
//                 cout<<"Your book will be delivered to you shortly"<<endl;
//             }
//             break;
//         case 2:
//             system("cls");
//             cout<<" "<<endl;
//             cout<<"Enter the book number:"<<endl;
//             cin>>number;
//             cout<<"Thanks for your kindness, always come back and support us"<<endl;
//         default:
//             system("cls");
//             break;
//     }
// }

void regin()
{
    reader rName, rPass, rNumber,rTel;

    cout<<"Enter Your Name:    ";
    cin>>rName.readerName;
    cout<<"\nEnter telephone number:    ";
    cin>>rTel.phone;
    cout<<"\nEnter Password:    ";
    cin>>rPass.passwd;
}

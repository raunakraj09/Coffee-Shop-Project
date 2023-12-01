#include <iostream>
#include <conio.h>
#include <unistd.h>
#include <string>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void welcome_message()
{
    cout << "\t\t\t *****                      WELCOME TO THE SHOP                      *****" << endl
         << endl;
}

void login();
void user_response();
void menu()
{
    sleep(1);
    system("Cls");
    cout << "\t\t\t ****************************************** " << endl;
    cout << "\t\t\t ***************    Menu    *************** " << endl;
    cout << "\t\t\t ****************************************** " << endl;
    cout << "\t\t\t *  Sr. No  **       Dishes    **  Amount * " << endl;
    cout << "\t\t\t ****************************************** " << endl;
    cout << "\t\t\t *    1     **       Tea       ** INR 07  * " << endl;
    cout << "\t\t\t *    2     **      Coffee     ** INR 15  * " << endl;
    cout << "\t\t\t *    3     **    Ice Coffee   ** INR 30  * " << endl;
    cout << "\t\t\t *    4     **       Water     ** INR 15  * " << endl;
    cout << "\t\t\t *    5     **     Biscuits    ** INR 20  * " << endl;
    cout << "\t\t\t ****************************************** " << endl;
    cout << endl;
    user_response();
}

int total_amount(int quantity, int price)
{
    int amt = price * quantity;
    cout << "\t\t\t Net Payable Balance : " << amt << endl;
    return amt;
}

int main();
void user_response()
{
    int sr_no, quantity;
    cout << "\t\t\t Enter The Sr.No of What You Want To Buy : ";
    cin >> sr_no;
    cout << "\t\t\t How Much Quantity : ";
    cin >> quantity;

    int price = 0;
    int amount = 0;

    switch (sr_no)
    {
    case 1:
        price = 7;
        amount = total_amount(quantity, price);
        break;
    case 2:
        price = 15;
        amount = total_amount(quantity, price);
        break;
    case 3:
        price = 30;
        amount = total_amount(quantity, price);
        break;
    case 4:
        price = 15;
        amount = total_amount(quantity, price);
        break;
    case 5:
        price = 20;
        amount = total_amount(quantity, price);
        break;
    default:
        cout << "\t\t\t Invalid Entry ";
        break;
    }
    cout << endl;
    cout << "\t\t\t *** Order Summary*** " << endl;

    if (sr_no == 1)
    {
        cout << "\t\t\t You Have Ordered " << quantity << " items of Tea. " << endl;
    }
    else if (sr_no == 2)
    {
        cout << "\t\t\t You Have Ordered " << quantity << " items of Coffee. " << endl;
    }
    else if (sr_no == 3)
    {
        cout << "\t\t\t You Have Ordered " << quantity << " items of Ice Coffee. " << endl;
    }
    else if (sr_no == 4)
    {
        cout << "\t\t\t You Have Ordered " << quantity << " items of Water. " << endl;
    }
    else if (sr_no == 5)
    {
        cout << "\t\t\t You Have Ordered " << quantity << " items of Biscuits. " << endl;
    }
    else
    {
        cout << "\t\t\t You Have Not Ordered Anything. ";
        
    }

    int user_amt;
    cout << "\t\t\t Amount Entered By the user : ";
    cin >> user_amt;

    if (user_amt < price)
    {
        cout << "\t\t\t Insufficient Balance!!! Order Cancelled. ";
        exit;
    }
    else
    {
        cout << "\t\t\t Change Returned : " << (user_amt - amount) << endl;
    }

    cout << "\t\t\t *** Thank You!!! Do Visit Next Time *** ";
}

void admin_page()
{
    welcome_message();
    int ch;
    string user, pass;
    cout << "\t\t\t ************************************************************************* " << endl;
    cout << "\t\t\t *****                WELCOME TO ADMIN LOGIN PAGE                    *****" << endl;
    cout << "\t\t\t *************************************************************************" << endl
         << endl;
    sleep(1);
    cout << "\t\t\t USERNAME: - " << endl;
    cout << "\t\t\t ";
    cin >> user;
    cout << "\t\t\t PASSWORD: - " << endl;
    cout << "\t\t\t ";
    ch = getch();

    while (ch != 13)
    {
        pass.push_back(ch);
        cout << "*";
        ch = getch();
    }
    cout << endl;
    if ((user == "ADMIN" || user == "admin" || user == "Admin") && (pass == "Admin" || pass == "ADMIN" || pass == "admin"))
    {
        cout << "\t\t\t ***** LOGIN SUCCESSFULL *****";
        sleep(2);
        system("cls");
        welcome_message();
        menu();
    }
    else
    {
        cout << endl;
        cout << "\t\t\t ***** Error Invalid Entry!!! Please Try Again ***** " << endl;
        sleep(2);
        cout << "\t\t\t ***** REDIRECTING *****";
        sleep(3);
        system("cls");
        admin_page();
    }
}

void login()
{
    int count, ch;
    string user, pass, u, p;
    system("cls");
    cout << "\t\t\t ************************************************************************* " << endl;
    cout << "\t\t\t *****                WELCOME TO USER LOGIN PAGE                     *****" << endl;
    cout << "\t\t\t *************************************************************************" << endl
         << endl;
    sleep(1);
    cout << "\t\t\t Username: - ";
    cin >> user;
    cout << "\t\t\t Password: - ";
    ch = getch();

    while (ch != 13)
    {
        pass.push_back(ch);
        cout << "*";
        ch = getch();
    }

    ifstream input("database.txt");
    while (input >> u >> p)
    {
        if (u == user && p == pass)

        {
            count = 1;
            system("cls");
        }
    }
    input.close();
    if (count == 1)
    {
        sleep(2);
        cout << "\t\t\t ***** Login Successfull!!! *****" << endl;
        cin.get();
        menu();
    }
    else
    {
        cout << endl;
        cout << "\t\t\t ***** Login Error!!! Please Try Again *****";
        sleep(2);
        login();
    }
}

void registr()
{
    int ch1;
    string reguser, regpass, ru, rp;
    system("cls");
    cout << "\t\t\t***** Registration Portal!!! Kindly Enter The Details *****" << endl
         << endl;
    cout << "\t\t\tEnter Username: - ";
    cin >> reguser;
    cout << "\t\t\tEnter Password: - ";

    ch1 = getch();
    while (ch1 != 13)
    {
        regpass.push_back(ch1);
        cout << "*";
        ch1 = getch();
    }

    cout << endl
         << endl;
    ofstream reg("database.txt", ios::app);
    reg << reguser << ' ' << regpass << endl;
    cout << "\t\t\t***** Registration Sucessful *****";
    sleep(3);
    system("cls");
    cout << "\t\t\t ***** User Created!!! Please Login Now *****" << endl
         << endl;
    sleep(3);
    system("cls");
    login();
}

void forgot();
void try_again()
{
    char choice;
    cout << "\t\t\t Press 1 to try again." << endl;
    cout << "\t\t\t Press 2 to create a new account." << endl
         << endl;
    choice = getch();
    if (choice == '1')
    {
        forgot();
    }
    else if (choice == '2')
    {
        registr();
    }
    else
    {
        cout << "\t\t\t Invalid Entry Try Again";
        sleep(2);
        try_again();
    }
}

void forgot()
{
    int ch;
    system("cls");
    cout << "\t\t\t ***** Choose From The Given Options *****" << endl
         << endl;
    cout << "\t\t\t 1. Search By UserId" << endl;
    cout << "\t\t\t 2. Search By Password" << endl;
    cout << endl;
    cout << "\t\t\t Enter Your Choice: - ";
    cin >> ch;

    cout << endl;

    switch (ch)
    {
    case 1:
    {
        int count = 0;
        string searchuser, su, sp;
        cout << "\t\t\t Enter Your Remembered Username: - ";
        cin >> searchuser;
        cout << endl;
        cout << "\t\t\t Please Wait";
        for (int i = 1; i < 6; i++)
        {
            cout << ".";
            sleep(1);
        }
        cout << endl;
        cout << "\t\t\t Seaching In Database";
        for (int i = 1; i < 6; i++)
        {
            cout << ".";
            sleep(1);
        }
        cout << endl;
        sleep(2);

        ifstream searchu("database.txt");
        while (searchu >> su >> sp)
        {
            if (su == searchuser)
            {
                count = 1;
            }
        }
        searchu.close();
        if (count == 1)
        {
            cout << endl;
            cout << "\t\t\t Eureka!!! Hurray!!! Account Found!!!" << endl;
            cout << "\t\t\t Your Password Is: -  " << sp;
            cin.get();
            sleep(2);
            system("cls");
            login();
        }
        else
        {
            cout << "\t\t\t Error!!! Username not found!!!";
            cin.get();
            cout << endl;
            try_again();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string searchpass, su2, sp2;
        cout << "\t\t\t Entered Your Remembered Password: - ";
        cin >> searchpass;
        cout << "\t\t\t Please Wait";
        for (int i = 1; i < 6; i++)
        {
            cout << ".";
            sleep(1);
        }
        cout << endl;
        cout << "\t\t\t Seaching In Database";
        for (int i = 1; i < 6; i++)
        {
            cout << ".";
            sleep(1);
        }
        cout << endl;
        sleep(2);

        ifstream searchp("database.txt");
        while (searchp >> su2 >> sp2)
        {
            if (sp2 == searchpass)
            {
                count = 1;
            }
        }
        searchp.close();
        if (count == 1)
        {
            cout << "\t\t\t Eureka!!! Hurray!!! Account Found!!!" << endl;
            cout << "\t\t\t Your Username Is: - " << su2;
            sleep(2);
            system("cls");
            login();
        }
        else
        {
            cout << "\t\t\t Error!!! Password not found!!!" << endl;
            cin.get();
            cout << endl;
            try_again();
        }

        break;
    }

    default:
        cout << "\t\t\t Please Try Again!!! Wrong Choice Entered!!! " << endl;
        forgot();
    }
}

void user_login()
{
    welcome_message();
    sleep(1);
    char choice;
    cout << "\t\t\t ************************************************************************* " << endl;
    cout << "\t\t\t *****                WELCOME TO USER LOGIN PAGE                     *****" << endl;
    cout << "\t\t\t *************************************************************************" << endl;
    cout << "\t\t\t ******                             MENU                                **" << endl;
    cout << "\t\t\t *************************************************************************" << endl;
    cout << "\t\t\t ****** 1. LOGIN                                                        **" << endl;
    cout << "\t\t\t ****** 2. REGISTER                                                     **" << endl;
    cout << "\t\t\t ****** 3. FORGOT PASSWORD                                              **" << endl;
    cout << "\t\t\t ****** 4. Exit                                                         **" << endl;
    cout << "\t\t\t *************************************************************************" << endl;
    cout << endl;
    cout << "\t\t\t Enter Your Choice : ";
    choice = getch();
    cout << endl;
    switch (choice)
    {
    case '1':
        login();
        break;
    case '2':
        registr();
        break;
    case '3':
        forgot();
        break;
    case '4':
        cout << "\t\t\t ***** Thank You!!! Have A Good Day. ******";
        exit;
        break;
    default:
        system("cls");
        cout << "\t\t\t ***** Error!!! Please Try Again *****" << endl;
        user_login();
    }
}

void login_page()
{
    welcome_message();
    char user_response;
    cout << "\t\t\t *****                      WHO's LOGGING IN?                        *****" << endl
         << endl;
    sleep(1);
    cout << "\t\t\t ************************************************************************* " << endl;
    cout << "\t\t\t *****           1. USER          *****           2. ADMIN          ****** " << endl;
    cout << "\t\t\t ************************************************************************* " << endl
         << endl;
    sleep(1);
    cout << "\t\t\t ENTER YOUR RESPONSE: - ";
    user_response = getch();
    cout << endl;
    if (user_response == '1')
    {
        cout << "\t\t\t Redirecting To User Login Page ";
        for (int i = 1; i < 6; i++)
        {
            cout << ".";
            sleep(1);
        }
        sleep(1);
        system("cls");
        user_login();
    }
    else if (user_response == '2')
    {
        cout << "\t\t\t Redirecting To Admin Login Page ";
        for (int i = 1; i < 6; i++)
        {
            cout << ".";
            sleep(1);
        }
        sleep(1);
        system("cls");
        admin_page();
    }
    else
    {
        cout << "\t\t\t ***** Error Invalid Entry!!! Please Try Again ***** " << endl;
        sleep(2);
        cout << "\t\t\t ***** REDIRECTING *****";
        sleep(3);
        system("cls");
        login_page();
    }
}

int main()
{
    cout << endl;
    login_page();

    return 0;
}
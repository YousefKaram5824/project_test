#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct DATE
{
    int day = 01, month = 04, year = 2024;
};
struct SUBSCRIBTION
{
    string type;
    DATE START_date, END_date;
    int rides = 0, stage = 0;
};
struct USER
{
    string  name, password;
    char type = 0; //D for admin C for customer
    int id = 0;
    float balance = 0;
    SUBSCRIBTION SUB;
}users[10];

void REGISTRATION();
void LOG_IN();
void main_menu();
void user_menu();
void Purchase_sub();
void choice_subs();
void uptade_balance();
void show_inf();


int main()
{
    cout << "\t\t\t\t----------------------------\n"
        << "\t\t\t\tWELCOME TO METRO MATE SYSTEM\n"
        << "\t\t\t\t----------------------------\n";

    main_menu();
    return 0;
}

void main_menu()
{

    int choice;
    bool exit_program = false;
    while (!exit_program)
    {
        cout << "Press [1] to REGISTER \n";
        cout << "Press [2] to LOGIN\n";
        cout << "Press [3] to EXIT\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            REGISTRATION();
            break;
        case 2:
            LOG_IN();
            break;
        case 3:
            exit_program = true;
            break;
        default:
            system("cls"); // Use appropriate clear screen command for your OS.
            cout << "Please select from the options given above\n";
        }
    }
}

int index = 0;
void REGISTRATION()
{
    system("cls");
    cout << "\t\t\t\t------------------------------\n"
        << "\t\t\t\tWelcome to Registration page \n"
        << "\t\t\t\t-----------------------------\n";

    users[index].id = 100 + rand() % 200;
    cout << "TYPE(admin(D),customer(C)) : "; cin >> users[index].type;
    cin.ignore(); // Clear input buffer
    cout << "NAME     : "; getline(cin, users[index].name);
    cout << "PASSWORD : "; cin >> users[index].password;
    cout << "your id is :" << users[index].id << endl;
    index++;
}

int login_index = -1;
void LOG_IN()
{
    system("cls");
    int id;
    string pass;

    for (int attempt = 0; attempt < 3; attempt++)
    {
        cout << "Enter your ID and password\n";
        cout << "ID       : "; cin >> id;
        cout << "Password : "; cin >> pass;

        bool found = false;
        for (int i = 0; i < index; i++)
        {
            if (users[i].id == id && users[i].password == pass)
            {
                found = true;
                cout << "Login successful!\n"
                    << "===================\n"
                    << "   WLCOME " << users[i].name << endl
                    << "===================\n";

                login_index = i;
                user_menu();
                return;
            }
        }

        cout << "Invalid ID or password. Please try again.\n";
    }

    cout << "You have exceeded the maximum number of login attempts. Exiting.\n";

}

void user_menu()
{

    int choice;
    cout << "Enter [1] to Purchase_sub\n";
    cout << "Enter [2] to show your informations\n";
    cout << "Enter [3] to show uptade your balance\n";
    cout << "please enter : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Purchase_sub();
        break;
    case 2:
        show_inf();
        break;
    case 3:
        uptade_balance();
        break;
    default:
        break;
    }

}

void Purchase_sub()
{
    system("cls");
    cout << "\t\t\t\t------------------------\n"
        << "\t\t\t\twelcome to Purchase page\n"
        << "\t\t\t\t------------------------\n";
    cout << "● Metro Stages:\n"
        << "#1 => 6 LE from 1 station to 9 stations\n"
        << "#2 => 8 LE from 10 stations to 16 stations\n"
        << "#3 => 12 LE from 17 stations to 23 stations\n"
        << "#4 => 15 LE greater than 23 stations\n\n";

    cout << "here you all details about the subscribtions\n";
    cout << "\n●(Students)\nStudent pay fixed amount of money every 3 months\nfor 180 trips for limited stations\n";
    cout << "you have to pay\n"
        << "33 LE for stage #1\n"
        << "41 LE for stage #2\n"
        << "50 LE for stage #3\n"
        << "65 LE for stage #\n\n";

    cout << "● (Public Cards)\nPerson pays fixed amount of money every 1 month\nfor 60 trips or every 1 year for 730 trips for limited stations\n";
    cout << "for month payment you will pay\n"
        << "230 LE for stage #1\n"
        << "290 LE for stage #2\n"
        << "340 LE for stage #3\n"
        << "450 LE for stage #4\n";

    cout << "for year payment you will pay\n"
        << "1500 LE for stage #1\n"
        << "2500 LE for stage #2\n"
        << "3500 LE for stage #3\n"
        << "4500 LE for stage #4\n\n";

    cout << "● (Cash Wallet Cards)\n"
        << "Person pay amount of money (Multiples of 10) any time\n"
        << "Card limit can't exceed 400 LE\n"
        << "Card isn’t limited to a specific period\n"
        << "Card charges individual tickets according to metro stages\n";

    choice_subs();

}

void choice_subs()
{
    int choice;

    cout << "select 1 for students\nselect 2 for public cards\nselect 3 for Cash Wallet Cards\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        users[login_index].SUB.type = "students";
        users[login_index].SUB.END_date.month += 3;
        int stage_std;
        cout << "select which stage\n(1) or (2) or (3) or (4) : ";
        cin >> stage_std;

        switch (stage_std)
        {
        case 1:
            if (users[login_index].balance < 33)
            {
                cout << "recharge your wallet first\n";
                user_menu();

            }
            users[login_index].balance -= 33;
            break;
        case 2:
            if (users[login_index].balance < 41)
            {
                cout << "recharge your wallet first\n";
                user_menu();
            }
            users[login_index].balance -= 41;
            break;
        case 3:
            if (users[login_index].balance < 50)
            {
                cout << "recharge your wallet first\n";
                user_menu();
            }
            users[login_index].balance -= 50;
            break;
        case 4:
            if (users[login_index].balance < 65)
            {
                cout << "recharge your wallet first\n";
                user_menu();
            }
            users[login_index].balance -= 65;
            break;
        default:

            break;
        }

        users[login_index].SUB.rides = 180;
        cout << "\nyou joined students subscribtion sucssecfully\n\n";
        break;
    case 2:
        users[login_index].SUB.type = "public";
        users[login_index].SUB.END_date.month += 1;
        int stage_pub;
        cout << "select which stage\n(1) or (2) or (3) or (4) : ";
        cin >> stage_pub;

        switch (stage_pub)
        {
        case 1: //(230, 290, 340 & 450
            if (users[login_index].balance < 230)
            {
                cout << "recharge your wallet first\n";
                user_menu();
            }
            users[login_index].balance -= 230;
            break;
        case 2:
            if (users[login_index].balance < 290)
            {
                cout << "recharge your wallet first\n";
                user_menu();
            }
            users[login_index].balance -= 290;
            break;
        case 3:
            if (users[login_index].balance < 340)
            {
                cout << "recharge your wallet first\n";
                user_menu();
            }
            users[login_index].balance -= 340;
            break;
        case 4:
            if (users[login_index].balance < 450)
            {
                cout << "recharge your wallet first\n";
                user_menu();
            }
            users[login_index].balance -= 450;
            break;
        default:

            break;
        }
        users[login_index].SUB.rides = 60;
        cout << "\nyou joined students subscribtion sucssecfully\n\n";
        break;
    case 3:
        users[login_index].SUB.type = "cash";


        break;
    default:
        cout << "selct from these numbers only\n";
        choice_subs();
    }
}

void uptade_balance()
{
    int add_balance;
    cout << "\n add your balance : ";
    cin >> add_balance;
    users[login_index].balance += add_balance;
}

void show_inf()
{
    system("cls");
    cout << "\t\t\t=====================\n"
        << "\t\t\tpersonal informations\n"
        << "\t\t\t=====================\n"
        << "User name   : " << users[login_index].name << endl
        << "pasword     : " << users[login_index].password << endl
        << "subcribtion : " << users[login_index].SUB.type << endl
        << "start date  : " << users[login_index].SUB.START_date.day
        << " / " << users[login_index].SUB.START_date.month
        << " / " << users[login_index].SUB.START_date.year << endl
        << "end date    : " << users[login_index].SUB.END_date.day
        << " / " << users[login_index].SUB.END_date.month
        << " / " << users[login_index].SUB.END_date.year << endl
        << "balance     : " << users[login_index].balance;




}

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

using namespace std;


#define log(x) cout << x << endl

bool isLogIn();
void forgot();
void registr();

int main()
{
    int choice;
    log("****************Welcome!****************");
    log("1: Login");
    log("2: Register");
    log("3: Forgot password");
    log("4: Quit");
    cin >> choice;

    switch(choice)
    {
    case 1:
        {
            bool islog = isLogIn();
            if(islog)
            {
                log("Login Successful!");
                main();
            }
            else
            {
                log("Please Register!");
                main();
            }
            break;
        }

    case 2:
        {
            registr();
            main();
            break;
        }
    case 3:
        {
            forgot();
            main();
            break;
        }
    case 4:
        {
            log("Thanks for using our login system!");
            log("Made by Vickins");
            break;
        }
    default:
        log("Invalid Selection!");
        main();
        break;
    }
    return 0;
}

void registr()
{
    system("cls");
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;

    ofstream file("C:\\logins\\" + username + ".log");
    file << username << "\n" << password;
    cout << "\nRegistration Successful!" << endl;
    system("pause");
}

bool isLogIn()
{
    string username, password, uname, pass;
    cout << "Enter Username: ";
    cin >> username;
    cout << "\nEnter Password: ";
    cin >> password;

    ifstream read("C:\\logins\\" + username + ".log");
    getline(read, uname);
    getline(read, pass);
    if(username == uname && password == pass)
        return true;
    else
        return false;
}

void forgot()
{
    string username, password, uname;
    cout << "Enter Username: ";
    cin >> username;

    ifstream read("C:\\logins\\" + username + ".log");
    while(read>>uname)
    {
        if(username == uname)
        {
            cout << "\nEnter New Password: ";
            cin >> password;
            ofstream input("C:\\logins\\" + username + ".log");
            input << username << "\n" << password;
            cout << "\nPassword Changed Successfully!"<< endl;
            break;
        }
        else
        {
            cout << "\nThe User does not exist!" << endl;
            break;
        }
    }
    main();
}

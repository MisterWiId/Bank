#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> split(string s, string sep)
{
    vector<string> result = {};

    bool flag = true;
    while (flag)
    {
        flag = false;
        if (s.find(sep) != string::npos)
        {
            string t = s.substr(0, s.find(sep));
            result.push_back(t);
            flag = true;
            s = s.substr(s.find(sep) + 1, s.length() - s.find(sep));
        }
        else
        {
            result.push_back(s);
            break;
        }
    }
    return result;
}

class User 
{
private:
    string name;
    double money;
    string password;
public:
    User() 
    {
        name = "";
        money = 0;
        password = "";
    }
    User(string newName, double newMoney, string newPassword)
    {
        name = newName;
        money = newMoney;
        password = newPassword;
    }
};

enum class AppState {
    Enter,
    EnterLogin,
    EnterPassword,
    Menu
};

class Bank 
{
private:
    vector<User> users;
    User currentUser;
    AppState state;

    void LoadUsers() {
        fstream file;
        file.open("users.dat", ios::in);

        string line;

        while (getline(file, line)) {
            vector<string> userData = split(line, ":");
            User user = User(userData[0], stod(userData[2]), userData[1]);
            users.push_back(user);
        }
        file.close();
    }
    void SaveUsers() 
    {

    }
    void CreateUsers() 
    {

    }
    void Login()
    {
        
    }
    void RenderUI()
    {
        // 1. switch + tab
        // 2. switch(ввести) + enter
        system("cls");
        switch (state)
        {
        case AppState::Enter:
            cout << "========== Bank++ ==========" << endl 
                << "Welcome, deaf user. Choose next stop" << endl
                << "Enter \ login \ to login to your account" << endl
                << "Enter \ register \ to register as a new user" << endl
                << "10 000$ bonus to every new user" << endl;
            break;
        case AppState::EnterLogin:
            cout << "========== Bank++ ==========" << endl
                << "Enter your login below";
            break;
        case AppState::EnterPassword:
            break;
        case AppState::Menu:
            break;
        default:
            break;
        }
    }
    void GetUserInput()
    {
        string input;
        cout << "\nYour input: ";
        getline(cin, input);

        switch (state)
        {
        case AppState::Enter:
            if (input == "login")
            {
                state = AppState::EnterLogin;
            }
            else if (input == "register")
            {

            }
            break;
        case AppState::EnterLogin:
            break;
        case AppState::EnterPassword:
            break;
        case AppState::Menu:
            break;
        default:
            break;
        }
    }
public:
    Bank() 
    {
        state = AppState::Enter;
        LoadUsers();
        Login();
    }
    void StartApp()
    {
        while (true)
        {
            RenderUI();
            GetUserInput();
        }
    }
};

int main()
{
    Bank bank;

    /*string s = "Hello";
    hash<string> myhash;
    string tes = to_string(myhash(s));
    cout << tes;*/
    bank.StartApp();
}

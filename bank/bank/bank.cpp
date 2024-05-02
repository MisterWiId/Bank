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

class Bank 
{
private:
    vector<User> users;
    User currentUser;

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
public:
    Bank() 
    {
        LoadUsers();
        Login();
    }

};

int main()
{
    Bank bank;

    string s = "Hello";
    hash<string> myhash;
    string tes = to_string(myhash(s));
    cout << tes;
}

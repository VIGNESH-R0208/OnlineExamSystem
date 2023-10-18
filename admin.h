#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "questions.h"

struct SECURITY {
    std::string username;
    std::string password;
};

class admin {
private:
    SECURITY security;
    std::fstream file;
    int ch;
    int flag;
    questions q;

public:
    admin();
    void Register();
    int login();
};

admin::admin() {
    std::cout << "\t\t\t\t********Welcome To the Administrator Section********\n";
    std::cout << "\n1-Register\n2-Login\nEnter:";
    std::cin >> ch;
    if (ch == 1) {
        Register();
    } else if (ch == 2) {
        flag = login();
        if (flag) {
            std::cout << "\nLogin successful!!\n";
            q.ques();
        } else {
            std::cout << "\nIncorrect Username or Password!!\nRegister to change Username & Password\n\n";
        }
    } else {
        std::cout << "\nGood Bye!!\n";
    }
}

void admin::Register() {
    file.open("security.txt", std::ios::binary | std::ios::in | std::ios::out);
    file.seekp(0L, std::ios::beg);
    std::cout << "\nEnter new Username:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, security.username);
    std::cout << "\nEnter new Password:";
    std::getline(std::cin, security.password);
    file.write((char*)&security, sizeof(security));
    file.close();
    std::cout << "\nThank You for registering\n";
}

int admin::login() {
    std::string uname, passwd;
    file.open("security.txt", std::ios::binary | std::ios::in | std::ios::out);
    file.seekg(0L, std::ios::beg);
    std::cout << "\nENTER USERNAME:";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, uname);
    std::cout << "\nENTER PASSWORD:";
    std::getline(std::cin, passwd);
    file.read((char*)&security, sizeof(security));
    if (uname == security.username && passwd == security.password)
        flag = 1;
    else
        flag = 0;
    file.close();
    if (flag == 1)
        return 1;
    else
        return 0;
}

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
using namespace std;
class User;
class Transaction;
class Account {
private:
    string accountNumber;
    double balance;
    Transaction** transactions; 
    User *user; 
    int transactionCount;
public:
    Account(string accNo, double initialBalance,User *u);
    ~Account();
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account* target, double amount);
    double getBalance();
    void printMiniStatement();
    void addTransaction(Transaction* t);
    void saveToFile(){
    }
    void loadFromFile();
    User* getuser();
};
#endif
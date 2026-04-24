#include "Account.h"
#include "Transaction.h" 
#include <iostream>      
#include <fstream>

    Account::Account(string accNo, double initialBalance){
        accountNumber=accNo;
        balance=initialBalance;
        transactionCount=0;
    }
    Account::~Account(){
        delete [] transactions;
    }
    void Account::deposit(double amount){
        if(amount>0){
          balance=balance+amount;
        }
    }
    bool Account::withdraw(double amount){
        if(amount<=balance){
            balance=balance-amount;
            return true;
        }
        return false;
    }
    bool transfer(Account* target, double amount);
    double Account::getBalance(){
         return balance;
    }
    void Account::printMiniStatement(){
        for(int i=0;i<transactionCount;i++){
            if(*(transactions+i)!=nullptr){
            (*(transactions+i))->printReceipt();
        }
    }
    }
    void addTransaction(Transaction* t);
 void Account::saveToFile() {
    ifstream infile("account_record.txt");
    ofstream temp_f("temp.txt");
    
    string id;
    if (infile.is_open()) {
        while (infile >> id) {
            if (id != accountNumber) {
                
                float t_bal;
                int count2;
                infile >> t_bal >> count2;
                temp_f << id << " " << t_bal << " " << count2 << " ";
                for (int i = 0; i < count2; i++) {
                    float trashAmt;
                    infile >> trashAmt;
                    temp_f << trashAmt << " ";
                }
                temp_f << endl;
            } 
            else {
                float t_bal;
                int count2;
                infile >> t_bal >> count2;
                for (int i = 0; i < count2; i++) {
                    float trashAmt;
                    infile >> trashAmt; 
                }
            }
        }
        infile.close();
    }

    temp_f << accountNumber << " " << balance << " " << transactionCount << " ";
    for (int i = 0; i < transactionCount; i++) {
        temp_f << (*(transactions + i))->getAmount() << " ";
    }
    temp_f << endl;
    temp_f.close();
    remove("account_record.txt");
    rename("temp.txt", "account_record.txt");
}
    void Account::loadFromFile(){
         ifstream infile("account_record.txt");
        if(!infile){
            return;
        }
        while(!infile.eof()){
            string id;
            infile>>id;

            if(id==""){
                break;
            }
            if(id==accountNumber){
                infile>>balance;
                infile>>transactionCount;
                for (int i = 0; i < transactionCount; i++) {
                float amt;
                infile>>amt;
                Transaction* t = new Transaction("History", amt);
                *(transactions + i) = t;
            }
            break;
        }
        else{
            float t_bal;
            int count2;
            infile >> t_bal >> count2;
            for (int i = 0; i < count2; i++) {
                float trashAmt;
                infile >> trashAmt; 
            }
        }
    }
    infile.close();
    }
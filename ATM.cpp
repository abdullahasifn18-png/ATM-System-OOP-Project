#include "ATM.h"

ATM::ATM(){
    currentUser=nullptr;
    accounts=nullptr;
    accountCount=0;
    cashAvailable=0;
}
ATM::~ATM(){
    delete [] accounts;
    logFile.close();
}
void ATM::run(){
    loadAccounts();
    while(true){
        string acc;
        cout<<"Welcome to ATM"<<endl<<"Enter account number"<<endl;
        cin>>acc;
        string pin;
        cout<<"Enter Pin"<<endl;
        cin>>pin;
        bool ch=authenticate(acc,pin);
        if(ch==0){
            cout<<"Invalid Credentials"<<endl;
            continue;
        }
         while(ch==1){
        showMenu();
       int choice;
       cout<<"Enter choice(-1 to logout and 1 for transaction)"<<endl;
       cin>>choice;
       if(choice==-1){
        ch=0;
        currentUser=nullptr;
       }
       else{
       processTransaction(choice);
       }
}}
}
bool ATM::authenticate(string accNo, string pin){
    for(int i=0;i<accountCount;i++){
        if(*(accounts+i)!=nullptr){
            string temp=(*(accounts+i))->getAccountNumber();
            bool ch=(*(accounts+i))->verifyPin(pin);
            if(ch==1&&accNo==temp){
                currentUser=(*(accounts+i))->getuser();
                return true;
            }

        }
    }
    return false;
}
void ATM::processTransaction(int choice){
    if(choice==1){
        Account *source=nullptr;
         for(int i=0;i<accountCount;i++){
          if(currentUser==(*(accounts+i))->getAccount()){
            source=*(accounts+i);
            break;
          }}
          if(source==nullptr){
            cout<<"Account not found"<<endl;
          }
          else{
            cout<<"Current Balance is "<<source->getBalance()<<endl;
          }
    }
    else if(choice==2){
         Account *source=nullptr;
         for(int i=0;i<accountCount;i++){
          if(currentUser==(*(accounts+i))->getAccount()){
            source=*(accounts+i);
            break;
          }}
          if(source==nullptr){
            cout<<"Account not found"<<endl;
          }
          else{
        double amount;
        cout<<"Enter amount to deposit"<<endl;
        cin>>amount;
        
        source->deposit(amount);
        source->saveToFile();
          }
    }
    else if(choice==3){
          Account *source=nullptr;
         for(int i=0;i<accountCount;i++){
          if(currentUser==(*(accounts+i))->getAccount()){
            source=*(accounts+i);
            break;
          }}
          if(source==nullptr){
            cout<<"Account not found"<<endl;
          }
          else{
        double amount;
        cout<<"Enter amount to withdraw"<<endl;
        cin>>amount;
        
        source->withdraw(amount);
        source->saveToFile();
          }
    }
    else if(choice==4){
        string temp;
        cout<<"Enter account Number"<<endl;
        cin>>temp;
        Account* source=nullptr;
        Account*destination=nullptr;
        for(int i=0;i<accountCount;i++){
          if(currentUser==(*(accounts+i))->getAccount()){
            source=*(accounts+i);
            break;
          }
        }
         for(int i=0;i<accountCount;i++){
          if(temp==(*(accounts+i))->getAccountNumber()){
            destination=*(accounts+i);
            break;
          }
        }
        if(source==nullptr||destination==nullptr){
            cout<<"Transaction error as account wasnt found"<<endl;
        }
        else if(source==destination){
            cout<<"cant transfer to same account"<<endl;
        }
        else{
        double amount;
        cout<<"Enter Ammount to Transfer"<<endl;
        cin>>amount;
        source->transfer(destination,amount);
        }
    }
    else if(choice==5){
        Account *source=nullptr;
         for(int i=0;i<accountCount;i++){
          if(currentUser==(*(accounts+i))->getAccount()){
            source=*(accounts+i);
            break;
          }}
          if(source==nullptr){
            cout<<"Account not found"<<endl;
          }
          else{
            cout<<"Printing mini statement"<<endl;
            source->printMiniStatement();
          }
    }
    else{
        cout<<"Invalid choice"<<endl;
    }
}
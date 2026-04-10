class User {
protected:
    string name, accountNumber, pin;
public:
    User(string n, string acc, string p);
    bool verifyPin(string input);   // base version
    string getName();
};
//-----------------------------------------------------------------------------
class RegisteredUser : public User {
private:
    int failedAttempts;
    bool isLocked;
    Account* account;
public:
    RegisteredUser(string n, string acc, string p, Account* a);
    bool verifyPin(string input);   // redefines parent's version
    void lockAccount();
    void changePin(string oldPin, string newPin);
    Account* getAccount();
    bool getIsLocked();
};
//-----------------------------------------------------------------------------
class Account {
private:
    string accountNumber;
    double balance;
    Transaction* transactions[50];  // array of pointers
    int transactionCount;
public:
    Account(string accNo, double initialBalance);
    ~Account();
    void deposit(double amount);
    bool withdraw(double amount);
    bool transfer(Account* target, double amount);
    double getBalance();
    void printMiniStatement();
    void addTransaction(Transaction* t);
    void saveToFile();
    void loadFromFile();
};
//-----------------------------------------------------------------------------
class Transaction {
protected:
    string type, timestamp;
    double amount;
public:
    Transaction(string t, double amt);
    void execute(Account* acc);     // base version
    void printReceipt();            // base version
    double getAmount();
};
//-----------------------------------------------------------------------------
class Withdraw : public Transaction {
private:
    double limit;
public:
    Withdraw(double amt);
    void execute(Account* acc);     
    void printReceipt();            
};
//-----------------------------------------------------------------------------
class Deposit : public Transaction {
private:
    string source;
public:
    Deposit(double amount, string source = "Cash");
    void execute(Account* acc) override;
    void printReceipt() override;
};
//-----------------------------------------------------------------------------
class Transfer : public Transaction {
private:
    string toAccountNumber;
    Account* targetAccount;
public:
    Transfer(double amount, string toAccNo, Account* target);
    void execute(Account* acc) override;
    void printReceipt() override;
};
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
class ATM {
private:
    User* currentUser;
    Account* accounts[100];
    int accountCount;
    ofstream logFile;
public:
    ATM();
    ~ATM();
    void run();
    bool authenticate(string accNo, string pin);
    void showMenu();
    void processTransaction(int choice);
    void loadAccounts();
    void saveAccounts();
    void logTransaction(Transaction* t);
};
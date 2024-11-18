#include <iostream>
using namespace std;

class BankAccount {
public:
    const long long accountNO;
    static int MIN_HIGH_VALUE;
    double accountBalance;

public:
    static int totalNoOfAccounts;  // Global account counter
    BankAccount() : accountNO(totalNoOfAccounts + 188888000000) {
        totalNoOfAccounts++;
        accountBalance = 0;
    }

    BankAccount(double accountBalance) : accountNO(totalNoOfAccounts + 188888000000) {
        totalNoOfAccounts++;
        this->accountBalance = accountBalance;
    }
    long long accountNo() const{
        return accountNO;
    }

    void depositMoney(double money) {
        accountBalance += money;
    }

    void withdrawMoney(double money) {
        if (accountBalance < money) {
            cout << "Insufficient Balance" << endl;
            cout << "Your balance is : " << accountBalance << endl;
        } else {
            accountBalance -= money;
        }
    }

    void display() const {
        cout << "Your account no is : " << accountNO << endl;
        cout << "Your account balance is : " << accountBalance << endl;
    }

    bool isHighValuePerson() const {
        return accountBalance >= MIN_HIGH_VALUE;
    }
};

int BankAccount::totalNoOfAccounts = 0;
int BankAccount::MIN_HIGH_VALUE = 1000;

class Bank:protected BankAccount {

    BankAccount* accounts[50];
    int numAccounts;  // Tracks accounts added within this Bank instance
public:
    Bank() : numAccounts(0) {
        for (int i = 0; i < 50; i++) {
            accounts[i] = nullptr;
        }
    }

    ~Bank() {
        for (int i = 0; i < numAccounts; i++) {
            delete accounts[i];
        }
    }

    void addAccount(double money) {
        
            accounts[numAccounts] = new BankAccount(money);
            numAccounts++;  
        
    }

    void displayHighValueAccounts() const {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i]->isHighValuePerson()) {
                accounts[i]->display();
            }
        }
    }
    void searchAccount(long long accNo){
        for (int i = 0; i < numAccounts; i++) {
            if ( accounts[i]->accountNo() ==accNo ){
                cout<<"Account exists : \n Account details are as follows: "<< endl;
                accounts[i]->display();
            }
        }
    }
   

};

int main() {
    Bank bank;

    
    bank.addAccount(300);  
    bank.addAccount(100);  
    bank.addAccount(1300); 
    bank.addAccount(35000);
   
    bank.displayHighValueAccounts();
    bank.searchAccount(188888000003);

    return 0;
}
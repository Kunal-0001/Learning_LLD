#include<iostream>
using namespace std;
 
//In the below code, we have followed the LSP wrongly, Because we have tightly coupled the code. Here we have added the logic in the client code to differentiate between different accounts
//and perform transaction based no the account type. In future if we add more kind of accounts, then we will have to update the code of client as well. Which breaks the OCP.

class Account {
public:
    virtual void withdraw(double amount) = 0;
    virtual void deposit(double amoutn) = 0;
};

class SavingsAccount : public Account {
private:
    double balance;
public: 
    SavingsAccount(){
        balance = 0;
    }

    void deposit( double amount) {
        balance += amount;
        cout<<"Amount "<<amount<<" has been deposited to your Savings Account, Current balance is "<<balance<<endl;
    }

    void withdraw( double amount) {
        if(amount<=balance){
            balance -=amount;
        }
        else{
            cout<<"Current balance is less than the withdrawal amount"<<endl;
        }
    }
};

class CurrentAccount : public Account {
private:
    double balance;
public:
    CurrentAccount(){
        balance = 0;
    }

    void deposit( double amount ) {
        balance += amount;
        cout<<"Amount "<<amount<<" has been deposited to your Current Account, Current balance is "<<balance<<endl;
    }

    void withdraw( double amount) {
        if(amount<=balance){
            balance -=amount;
        }
        else{
            cout<<"Current balance is less than the withdrawal amount"<<endl;
        }
    }
};


class FixedTermAccount : public Account {
    private:
    double balance;
    public:
    FixedTermAccount(){
        balance = 0;
    }
    
    void deposit( double amount ) {
        balance += amount;
        cout<<"Amount "<<amount<<" has been deposited to your Fixed Term Account, Current balance is "<<balance<<endl;
    }
    
    void withdraw( double amount ){
        throw logic_error("Withdrawal not allowed in Fixed Term Account");
    }
};

class BankClient {
private:
    vector<Account*> accounts;
public:
    BankClient(vector<Account*> accounts){
        this->accounts = accounts;
    }

    void ProcessTransaction(){
        for(Account* acc : accounts) {
            acc->deposit(1000);

            if(typeid(*acc) == typeid(FixedTermAccount)){
                cout<<"Skipping withdrawal, as it is a fixed term account"<<endl;
            }
            else{
                try{
                    acc->withdraw(500);
                }
                catch(const logic_error& e){
                    cout<<"Exception: "<<e.what()<<endl;
                }
            }
            
        }
    }

};

int main(){
    vector<Account*> accounts;
    accounts.push_back(new SavingsAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());

    BankClient* client = new BankClient(accounts);
    client->ProcessTransaction();

return 0;
}
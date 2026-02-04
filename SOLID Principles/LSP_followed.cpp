#include<iostream>
using namespace std;
 
class DepsitOnlyAccount {
public:
    virtual void deposit(double amount) = 0;
};

class WithdrawableAccount : public DepsitOnlyAccount {
public:
    virtual void withdraw(double amount) = 0;
};

class SavingsAccount: public WithdrawableAccount {
private:
    double balance;
public:
    void deposit(double amount) {
        balance += amount;
        cout<<"Amount "<<amount<<" has been deposited to your Savings Account, Current Balance is "<<balance<<endl;
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

class CurrentAccount : public WithdrawableAccount {
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

class FixedTermAccount : public DepsitOnlyAccount {
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
};

class BankClient {
private:
    vector<DepsitOnlyAccount*> depositAcc;
    vector<WithdrawableAccount*> WithdrawAcc;
public:
    BankClient(vector<DepsitOnlyAccount*> depositAcc, vector<WithdrawableAccount*> WithdrawAcc){
        this->depositAcc = depositAcc;
        this->WithdrawAcc = WithdrawAcc;
    }

    void ProcessTransaction(){
        for(WithdrawableAccount* acc : WithdrawAcc) {
            acc->deposit(1000);
            acc->withdraw(500);
        }

        for(DepsitOnlyAccount* acc: depositAcc) {
            acc->deposit(1000);
        }
    }
};

int main(){
vector<WithdrawableAccount*> withdrawAcc;
vector<DepsitOnlyAccount*> depositAcc;

withdrawAcc.push_back(new SavingsAccount());
withdrawAcc.push_back(new CurrentAccount());
depositAcc.push_back(new FixedTermAccount());

BankClient* client = new BankClient(depositAcc,withdrawAcc);
client->ProcessTransaction();

return 0;
}
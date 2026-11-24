#include <iostream>
using namespace std;
string names[3]={"john","mary","peter"};
int accounts[3]={1001,1002,1003};
int pins[3]={1111,2222,3333};
double balance[3]={5000,3000,7000};

int findAccount(int number)
{
    for(int i = 0 ; i < 3 ; i++)
    {
        if(accounts[i] == number)
        {
            return i;
        }
    }
    return -1;
}

void menu()
{
    cout<<"\n=====GCC BANK====="<<endl;
    cout<<"1.Deposit"<<endl;
    cout<<"2.Withdraw"<<endl;
    cout<<"3.Send Cash"<<endl;
    cout<<"4.Check Balance"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<"Enter choice"<<endl;
}
void deposit(int user)
{
    double amount;
    cout<<"\n===== DEPOSIT MONEY ====="<<endl;
    cout<<"enter amount:R";
    cin>>amount;
    if(amount>0)
    {
     balance[user]=balance[user]+amount;
     cout<<"\nDeposit successful"<<endl;
     cout<<"Amount deposited:R"<<amount<<endl;
     cout<<"new balance:R"<<balance[user]<<endl;
     return ;
    }
    else
    {
        cout<<"invalid amount!"<<endl;
    }
}
void withdraw(int user)
{
    double amount;
    cout<<"\n===== WITHDRAW ====="<<endl;
    cout<<"enter amount:R";
    cin>>amount;
    if(amount > 0 && amount <= balance[user])
    {
        balance[user] = balance[user] - amount;
        cout<<"money withdrawn!"<<endl;
        cout<<"Amount withdraw:R"<<amount<<endl;
        cout<<"new balance:R"<<balance[user]<<endl;
    }
        else
        {
            cout<<"not enough money "<<endl;
        }
}
void sendCash(int user)
{
    int receiverAccount;
    double amount;
    cout<<"enter receiver account number:";
    cin>>receiverAccount;
    int receiver = findAccount(receiverAccount);
    if(receiver == -1 || receiver == user)
    {
        cout<<"Account not found!"<<endl;
        return;
    }
    cout<<"Enter amount to send:R";
    cin>>amount;
    if (amount >0 && amount <= balance[user])
    {
        balance[user] = balance[user] -amount;
        balance[receiver] = balance[receiver] + amount;
        cout<<"Money sent successfully!"<<endl;
        cout<<"Amount sent:R"<<amount<<endl;
        cout<<"new balance:R"<<balance[user]<<endl;
    }
    else
    {
        cout<<"insufficint money!"<<endl;
    }
}
void CheckBalance(int user)
{
    cout<<"\nName:"<<names[user]<<endl;
    cout<<"Account number:"<<accounts[user]<<endl;
    cout<<"Balance:R"<<balance[user]<<endl;
}
int main()
{
    int number,pin,user,choice = 0;
    cout<< "Welcome to GCC Bank ! " <<endl;
    cout<<"enter account number:";
    cin>>number;
    cout<<"enter pin:"<<endl;
    cin>>pin;
    user = findAccount(number);
    if(user == -1)
    {
        cout<<"\nERROR:Account number does not exist!"<<endl;
        cout<<"please enter the correct account number"<<endl;
        return 0;
    }
    else if(pins[user] != pin)
    {
        cout<<"\nERROR:incorrect pin !"<<endl;
        cout<<"please enter the correct pin "<<endl;
        return 0;
    }
    else
    {
        cout<<"\login successful!"<<endl;
        cout<<"Welcome "<< names[user]<<endl;
    }
        do
    {
        menu();
        cin>>choice;
        switch(choice)
        {
        case 1:
            deposit(user);
            break;
        case 2:
            withdraw(user);
            break;
        case 3:
            sendCash(user);
            break;
        case 4:
            CheckBalance(user);
            break;
        case 5:
            cout<<"\nThank you for using GCC Bank!"<<endl;
            break;
        default:
            cout<<"ERROR: invalid meun choice"<<endl;
        }

     }



    while(choice != 5);
    return 0;
}

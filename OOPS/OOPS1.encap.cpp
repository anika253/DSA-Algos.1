#include <iostream>   
#include <string>                                                              
using namespace std;

class Account{
    private:
    string owner;
    int balance;
    public:
    Account(string name, int bal)
    {
        owner= name;
        balance = bal;
    }
    void deposit(int amt)
    {
        if(amt>0)
        {
            balance+=amt;
        }
    }
    void withdraw(int amt)
    {
        if(balance>amt)
        {
            balance=balance-amt;
        }
        else{
            cout << "balance not sufficient"<<endl;
        }
    }
    int getBalance()
    {
        return balance;
    }
    
};
int main() {
	Account a("chinu", 10000);

	a.deposit(500);
	cout << a.getBalance()<< endl;
	a.withdraw(40000);


}
/*OOPS principles in this code:

owner and balance are declared private — they cannot be accessed directly from outside the class.
  Only class methods like deposit(), withdraw(), and getBalance() can manipulate these variables.
  This ensures data protection and controlled access, which is encapsulation in action.

Abstraction is the process of hiding the internal implementation details and showing only the essential features to the user.


The user of the Account class doesn't need to know how deposit/withdraw logic works internally.

They just use a.deposit(500) or a.getBalance() — the complex logic is abstracted away.


*/

#include <iostream>   
#include <string>                                                              
using namespace std;
class User{
    private:
    string name;
    int password;
    public:
    User(string uname, int pass)
    {
        name = uname;
        password = pass;
    }
   void login(int input )
    {
        if(input== password)
        {
            cout << "you are now logged in";
        }
        else{
            cout << "wrong password";
        }
    }
    string getUserName(){
        return name;
    }
    void changePasword(int newP, int oldP)
    {
        if(oldP==password)
        {
            password= newP;
        }
        else{
            cout << "incorrect old password"<< endl;
        }
    }
    int getPassword()
    {
       return password;
       
    }
    
};

int main() {
User a("anika", 2025);
a.login(2024);
a.changePasword(2026, 2025);
 cout << a.getPassword()<< endl;


}

#include <iostream>   
#include <string>                                                              
using namespace std;

class Draw{
    public:
 virtual void draw()
    {
        cout << "draw a shape"<< endl;
    }
    
    
};
class Rect :public Draw{
    public:
    void draw()
    {
        cout << "draw a rect"<< endl;
    }
};
class circle: public Draw{
    public:
    void draw()
    {
        cout << "draw a circle" << endl;
    }
};
int main() {
     Draw*r1 = new Rect;
      circle*c1= new circle;// here i called the pointer of circle class not the Draw class...so this is not example  of runtime polymorphism.
        // if i had called Draw*c1= new circle(); then it would have been an example of runtime polymorphism.
      r1->draw();
      c1->draw(); 
      /*
      if i write r1->draw then it will call the pointer of this class Draw and it will call the fnxn.
      */
      delete r1; // memory cleanup needed!
      delete c1;
      return 0;


}

//___________________________________________________VIRTUAL FUNCTIONS____________________________________________________
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
      Draw*c1= new circle;
      r1->draw();
      c1->draw();
      delete r1; // memory cleanup needed!
      delete c1;
      return 0;


}

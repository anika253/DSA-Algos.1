#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int d)
    {
        this->data =d;
        this->next=NULL;
    }
    
};
void insert(Node*&tail,int el, int d)
{
   Node*temp = new Node(d);
   if(tail==NULL)
   {
       tail= temp;
      tail->next= tail;
       return;
   }
   else{
       Node*curr= tail;
       while(curr->data!=el)
       {
           curr= curr->next;
       }
       temp->next = curr->next;
       curr->next= temp;
       return;
       
       
   }
}

   
   
   
   
   

void deleteNode(Node*&tail, int el)
{
    
    if(tail==NULL)
    {
        cout << "noth to delete "<< endl;
        return;
    }
    Node*prev= tail;
    Node*curr= tail->next;
    while(curr->data!= el)
    {
        prev= curr;
        curr= curr->next;
    }
    prev->next = curr->next;
    if(prev==curr)
    {
        tail=NULL;
        
    }
    else if(tail==curr)
    {
        tail = prev;
    }
    curr->next=NULL;
    delete curr;
    return;
    
    
  
}
void print(Node*& tail) { // do while loop is used to print circular linked list so that we can start from any node and print the entire list
    // do-while loop will ensure that we print at least once even if the list has only one node
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

    
    
int main() {
    Node* tail = NULL;

    // First insert without needing element to match
    insert(tail, 0, 10);
    insert(tail, 10, 20);
    insert(tail, 20, 30);
    print(tail);  // Output: 10 20 30

    deleteNode(tail, 20);
    print(tail);  // Output: 10 30

    deleteNode(tail, 10);
    print(tail);  // Output: 30

    deleteNode(tail, 30);
    print(tail);  // Output: List is empty

    return 0;
}



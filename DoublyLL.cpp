#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int d)
    {
        this->data  =d;
        this->next = NULL;
        this->prev= NULL;
    }
};

void insert(Node*&head, int d, int pos)
{
  Node*temp = new Node(d);
  if(head==NULL)
  {
      head = temp;
      return;
  }
  if(pos==1)
{
    temp->next = head;
     if(head!=NULL)
     {
         head->prev= temp;
     }
     head= temp;
     return;
}
else{
    int cnt = 1;
    Node*curr= head;
    while(cnt<pos-1 && curr!=NULL)
    {
        cnt++;
        curr= curr->next;
    }
    if(curr==NULL)
    {
        cout << "out of bounds pos";
        return;
    }
    temp->next = curr->next;
    if(curr->next!=NULL)
    {
        curr->next->prev= temp;
    }
    curr->next = temp;
    temp->prev= curr;
    return;
}
}
void deleteN(Node*&head, int pos)
{
    if(head==NULL){
        return;
    }
    if(pos==1)
    {
        Node*temp = head;
        head= head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
        return;}
        
        else{
            Node*prev1=NULL;
            Node*curr= head;
            int cnt =1;
            while(cnt<pos && curr!=NULL)
            {
                cnt++;
                prev1=curr;
                curr= curr->next;
            }
            if(curr==NULL)
            {
                cout << "out of bounds";
                return;
            }
            if(prev1!=NULL)
            {
                prev1->next = curr->next;
            }
            if(curr->next!=NULL)
            {
                curr->next->prev= prev1;
            }
            curr->next=NULL;
            curr->prev=NULL;
            delete curr;
            return;}
}
void print(Node*&head)
{
   Node*curr = head;
   while(curr!=NULL)
   {
       cout << curr->data << endl;
       curr=curr->next;
   }
 return;
    
}
int main() {
Node*head= NULL;
insert(head,10,1);
insert(head, 20,2);
insert(head,30, 3);
print(head);
cout << endl<< endl<< endl;
deleteN(head,2);
print(head);
return 0;

}

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






//// THE CODE OF LINKED LIST (SIMPLE)
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    
    Node( int val)
    {
        this->val = val;
        this->next =NULL;
    }
    
};

void insertAtHead(Node*&head , int data)
{
    Node*temp = new Node(data);
    if(head == NULL) 
    {
       head = temp;
        return ;
    }
    temp->next = head;
    head = temp;
    
}
void insertAtTail(Node*&head  , int data)
{
    Node*temp= new Node(data);
    if( head==NULL)
    {
        temp = head;
        return ;
    }
    Node*temp1 = head;
    while(temp1->next!= NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    temp->next = NULL;
}
    
void insertatPos(Node*&head , int pos, int d)
{
   
    if(head==NULL || pos <=1)
    {
        insertAtHead(head , d);
        
    }
    Node*temp = head;
    int cnt = 0;
    while(temp!= NULL)
    {
        temp = temp->next;
        cnt++;
        
    }
    if(cnt < pos) {cout << "invlid pos";
    return ;}
    Node*curr = head;
    Node*prev = NULL;
    int cnt1 = 1;
    while(curr!= NULL && cnt1 < pos)
    {
        prev=curr;
        curr = curr->next;
        cnt1++;
        
    }
    Node* nn = new Node(d);
    prev->next= nn;
    nn->next = curr;
    
    
    
}
void deleten(Node*head , int pos)
{
    if( head==NULL) return ;
    Node* temp = head;
    int cnt = 0;
    
    while(temp!= NULL)
    {
        temp = temp->next;
        cnt++;
    }
    if( cnt < pos) 
    {
        cout << "invalid";
        return ;
    }
    Node*prev = NULL;    
    Node*curr = head;
    int cnt1 = 1;
    while(curr!= NULL &&  cnt1<pos)
    {
        prev = curr;
        curr = curr->next;
        cnt1++;
        
    }
    if(prev!= NULL && curr!= NULL)
    {
        prev->next = curr->next;
        delete curr;
        
    }
}
 void printList(Node*head)
 {
     Node*temp = head;
     while( temp !=NULL)
     {
         cout << temp-> val  << endl;
         temp = temp->next;
     }
 }
 



int main() {
Node*head = new Node(1);
insertAtHead(head,2);
printList(head);
return 0;


}


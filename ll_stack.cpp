#include<iostream>
using namespace std;

class stackL{
    public:
    struct node{
        int data;
        node* next;
    };
    node* top;
    int size=0;

    void push(int x){
        node* temp = new node; 
        temp ->data = x;
        temp ->next = top;
        size++;
    }

    void pop(){
        node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int top_ele(){
        return top->data;
    }
    void display(){
        node* temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};
int main(){
    stackL s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout<<endl;
    cout<<s.top_ele()<<endl;
    s.pop();
    s.display();
}

// the time and space complexity of push and pop is O(1) and the time complexity of top_ele is also O(1)
// and the time complexity of display is O(n) where n is the number of elements in the stack.
#include<iostream>
using namespace std;

class stack{
    public:
    int top=-1;
    int st[5];

    void push(int x){
        top = top+1;
        st[top] = x;
    }

    void pop(int x){
        if(top == -1) cout<<"Stack is empty"<<endl;
        else{
        top = top-1;
        }
    }
    void top_ele(){
        if(top == -1) cout<<"Stack is empty"<<endl;
        else{
        cout<<"Top element is: "<<st[top]<<endl;
        }
    }
    void display(){
        if(top == -1) cout<<"Stack is empty"<<endl;
        else{
        cout<<"Stack elements are: ";
        for(int i=0; i<=top; i++){
            cout<<st[i]<<" ";
        }}         cout<<endl;
    }
    
};
int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.top_ele();
    s.pop(30);
    s.display();
    return 0;
}
/*
 THe time complexity of push, pop, top_ele and display functions is O(1) in the average case. However,
 the display function has a time complexity of O(n) in the worst case, where n is the number of elements 
 in the stack. 
*/
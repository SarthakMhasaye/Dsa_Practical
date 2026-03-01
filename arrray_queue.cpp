#include<iostream>
using namespace std;

class queue{
    public:
    int st=-1,end=-1;
    int size = 5;
    int que[5];

    void push(int x){
        if(st == -1) st= st+1; end = end+1; que[end] = x;
        end = (end+1)%size;
        que[end] = x;

    }

    void pop(int x){
        st = (st+1)%size;
        if(st == end) st = -1, end = -1;
    }
    void front_ele(){
        if(st > end) cout<<"Queue is empty"<<endl;
        else{
        cout<<"Front element is: "<<que[st]<<endl;
        }
    }
    void display(){
        if(st > end) cout<<"Queue is empty"<<endl;
        else{
        cout<<"Queue elements are: ";
        for(int i=st; i<=end; i++){
            cout<<que[i]<<" ";
        }}         cout<<endl;
    }
};

// The time complexity of push, pop, front_ele and display functions is O(1) in the average case.
// However, the display function has a time complexity of O(n) in the worst case, where n is the
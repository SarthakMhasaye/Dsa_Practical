#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverseString(string str) {
    stack<char> s;
    for (char c : str) {
        s.push(c);
    }
    cout << "Reversed: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

bool isBalanced(string expr) {
    stack<char> s;
    for (char c : expr) {
        if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty()) return false;
            s.pop();
        }
    }
    return s.empty();
}

int evaluateExpression(int a, char op, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int main() {
    reverseString("Hello");
    
    cout << "Balanced: " << (isBalanced("((()))") ? "Yes" : "No") << endl;
    
    cout << "5 + 3 = " << evaluateExpression(5, '+', 3) << endl;
    
    return 0;
}

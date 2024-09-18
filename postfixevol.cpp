#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to evaluate the postfix expression
int evaluatePostfix(string expression) {
    stack<int> s;

    for (char& ch : expression) {
        // If the character is a digit (operand), push it to the stack
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        }
        // If the character is an operator, pop two elements and perform the operation
        else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result;
            
            switch(ch) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            
            // Push the result back onto the stack
            s.push(result);
        }
    }

    // The final result is the only element remaining in the stack
    return s.top();
}

int main() {
    string postfix = "234*+";
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Evaluated Result: " << evaluatePostfix(postfix) << endl;
    return 0;
}

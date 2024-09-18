//### 2. Prifix Evaluation
#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to evaluate the prefix expression
int evaluatePrefix(string str) {
    stack<int> s;

    // Scan the expression from right to left
    for (int i = str.length() - 1; i >= 0; i--) {
        char ch = str[i];

        // If the character is a digit (operand), push it to the stack
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        }
        // If the character is an operator, pop two elements and perform the operation
        else {
            int operand1 = s.top(); s.pop();
            int operand2 = s.top(); s.pop();
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
    string prefix = "+*234";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Evaluated Result: " << evaluatePrefix(prefix) << endl;
    return 0;
}

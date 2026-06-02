//this is best 
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int start = -1, end = -1;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') start = i;
        if (str[i] == ')') {
            end = i;
            break;
        }
    }

    // String case: console.log("Hello")
    if (str[start + 1] == '"') {
        for (int i = start + 2; i <= end - 2; i++)
            cout << str[i];
        cout << endl;
    }
    else {
        string expr = str.substr(start + 1, end - start - 1);

        int pos = -1;
        char op;

        for (int i = 0; i < expr.size(); i++) {
            if (expr[i] == '+' || expr[i] == '-' ||
                expr[i] == '*' || expr[i] == '/') {
                pos = i;
                op = expr[i];
                break;
            }
        }

        int a = stoi(expr.substr(0, pos));
        int b = stoi(expr.substr(pos + 1));

        if (op == '+')
            cout << a + b << endl;
        else if (op == '-')
            cout << a - b << endl;
        else if (op == '*')
            cout << a * b << endl;
        else {
            if (b == 0)
                cout << "Division by zero" << endl;
            else
                cout << a / b << endl;
        }
    }

    return 0;
}//this is valid for-----------> "console.log(121+13)""
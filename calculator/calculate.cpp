#include "calculate.h"
#include <QStack>
#include <QDebug>

// Helper function to check if a character is an operator (+, -, *, /)
bool isOperator(QChar ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Helper function to perform arithmetic operations
double performOperation(double num1, double num2, QChar op) {
    switch (op.toLatin1()) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0.0;
    }
}

QString Calculator::calculate(const QString& expression) {
    QStack<double> numStack;
    QStack<QChar> opStack;

    // Loop through the expression characters
    for (int i = 0; i < expression.length(); ++i) {
        QChar ch = expression[i];
        // Skip whitespaces
        if (ch.isSpace()) {
            continue;
        }

        if (ch.isDigit() || ch == '.') {
            // If the character is a digit or a decimal point, extract the full number
            int j = i;
            while (j < expression.length() && (expression[j].isDigit() || expression[j] == '.')) {
                ++j;
            }
            QString numberStr = expression.mid(i, j - i);
            bool conversionSuccess = false;
            double number = numberStr.toDouble(&conversionSuccess);
            if (conversionSuccess) {
                numStack.push(number);
            } else {
                // Handle invalid number format
                return "Error: Invalid number format";
            }
            i = j - 1;
        } else if (isOperator(ch)) {
            // If the character is an operator, perform necessary calculations
            while (!opStack.isEmpty() && isOperator(opStack.top())) {
                QChar prevOp = opStack.top();
                opStack.pop();
                if (numStack.size() < 2) {
                    // Handle insufficient operands for an operator
                    return "Error: Insufficient operands for operator";
                }
                double num2 = numStack.top();
                numStack.pop();
                double num1 = numStack.top();
                numStack.pop();
                double result = performOperation(num1, num2, prevOp);
                numStack.push(result);
            }
            opStack.push(ch);
        } else if (ch == '(') {
            // If the character is an opening parenthesis, push it to the operator stack
            opStack.push(ch);
        } else if (ch == ')') {
            // If the character is a closing parenthesis, perform calculations until the matching opening parenthesis
            while (!opStack.isEmpty() && opStack.top() != '(') {
                QChar prevOp = opStack.top();
                opStack.pop();
                if (numStack.size() < 2) {
                    // Handle insufficient operands for an operator
                    return "Error: Insufficient operands for operator";
                }
                double num2 = numStack.top();
                numStack.pop();
                double num1 = numStack.top();
                numStack.pop();
                double result = performOperation(num1, num2, prevOp);
                numStack.push(result);
            }
            if (opStack.isEmpty()) {
                // Handle mismatched parentheses
                return "Error: Mismatched parentheses";
            }
            opStack.pop(); // Pop the matching opening parenthesis
        } else {
            // Handle invalid characters in the expression
            return "Error: Invalid character in expression";
        }
    }

    // Perform remaining calculations
    while (!opStack.isEmpty()) {
        QChar op = opStack.top();
        opStack.pop();
        if (numStack.size() < 2) {
            // Handle insufficient operands for an operator
            return "Error: Insufficient operands for operator";
        }
        double num2 = numStack.top();
        numStack.pop();
        double num1 = numStack.top();
        numStack.pop();
        double result = performOperation(num1, num2, op);
        numStack.push(result);
    }

    // The final result will be at the top of the numStack
    if (numStack.isEmpty()) {
        // Handle empty expression
        return "Error: Empty expression";
    } else {
        double finalResult = numStack.top();
        return QString::number(finalResult);
    }
}

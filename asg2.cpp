#include <iostream>
#include <string>
#include <algorithm> // Include this header for the reverse function
#include <cmath>
using namespace std;

struct node
{
    char data;
    struct node *next;
};

int PUSH(node *&head, char data, int top, int n)
{
    if (top != (n - 1))
    {
        node *temp = new node();
        temp->data = data;
        temp->next = NULL;
        node *ptr = head;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        top++;
    }
    else
    {
        cout << "Cannot PUSH, stack overflowed \n";
    }
    return top;
}

int POP(node *&head, int top, int n)
{
    if (top != -1)
    {
        if (head == NULL)
        {
            cout << "Linked list is empty \n";
        }
        else
        {
            node *current = head;
            head = head->next;
            delete (current); // free that original head
            current = NULL;
        }
        top--;
    }
    else
    {
        cout << "Cannot POP, stack underflowed \n";
    }
    return top;
}

void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int getPrecedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

string infixToPostfix(string infix)
{
    int n = infix.size();
    string postfix = "";
    int top = -1;
    node *stack = NULL;

    int i = 0;
    while (i < n)
    {
        if (isalnum(infix[i]))
        {
            postfix += infix[i];
        }
        else if (infix[i] == '(')
        {
            top = PUSH(stack, infix[i], top, n);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack->data != '(')
            {
                postfix += stack->data;
                top = POP(stack, top, n);
            }
            if (top != -1)
                top = POP(stack, top, n); // Pop '(' from the stack
        }
        else
        {
            while (top != -1 && getPrecedence(infix[i]) <= getPrecedence(stack->data))
            {
                postfix += stack->data;
                top = POP(stack, top, n);
            }
            top = PUSH(stack, infix[i], top, n);
        }
        i++;
    }

    while (top != -1)
    {
        postfix += stack->data;
        top = POP(stack, top, n);
    }

    return postfix;
}

string infixToPrefix(string infix)
{
    int n = infix.size();
    string prefix = "";
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < n; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    int top = -1;
    node *stack = NULL;

    int i = 0;
    while (i < n)
    {
        if (isalnum(infix[i]))
        {
            prefix += infix[i];
        }
        else if (infix[i] == '(')
        {
            top = PUSH(stack, infix[i], top, n);
        }
        else if (infix[i] == ')')
        {
            while (top != -1 && stack->data != '(')
            {
                prefix += stack->data;
                top = POP(stack, top, n);
            }
            if (top != -1)
                top = POP(stack, top, n); // Pop '(' from the stack
        }
        else
        {
            while (top != -1 && getPrecedence(infix[i]) < getPrecedence(stack->data))
            {
                prefix += stack->data;
                top = POP(stack, top, n);
            }
            top = PUSH(stack, infix[i], top, n);
        }
        i++;
    }

    while (top != -1)
    {
        prefix += stack->data;
        top = POP(stack, top, n);
    }

    reverse(prefix.begin(), prefix.end());
    
    return prefix;
}

int postfixEvaluation(string postfix)
{
    int n = postfix.size();
    int top = -1;
    node *stack = NULL;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(postfix[i]))
        {
            top = PUSH(stack, postfix[i], top, n);
        }
        else
        {
            int operand2 = stack->data - '0';
            top = POP(stack, top, n);
            int operand1 = stack->data - '0';
            top = POP(stack, top, n);

            int result;

            switch (postfix[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1,operand2);
                break;
            case '%':
                result = operand1 % operand2;
                break;
            default:
                cout << "Invalid operator in the postfix expression" << endl;
                return 0;
            }

            top = PUSH(stack, result + '0', top, n);
        }
    }

    if (top != -1)
    {
        int result = stack->data - '0';
        return result;
    }
    else
    {
        cout << "Invalid postfix expression" << endl;
        return 0;
    }
}

int prefixEvaluation(string prefix)
{
    int n = prefix.size();
    int top = -1;
    node *stack = NULL;

    for (int i = n - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            top = PUSH(stack, prefix[i], top, n);
        }
        else
        {
            int operand1 = stack->data - '0';
            top = POP(stack, top, n);
            int operand2 = stack->data - '0';
            top = POP(stack, top, n);

            int result;

            switch (prefix[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            case '^':
                result = pow(operand1,operand2);
                break;
            case '%':
                result = operand1 % operand2;
                break;
            default:
                cout << "Invalid operator in the prefix expression" << endl;
                return 0;
            }

            top = PUSH(stack, result + '0', top, n);
        }
    }

    if (top != -1)
    {
        int result = stack->data - '0';
        return result;
    }
    else
    {
        cout << "Invalid prefix expression" << endl;
        return 0;
    }
}

int main()
{
    string infix;
    string postfix;
    string prefix;

    int ch;
    cout << "Enter 1 for postfix\nEnter 2 for prefix\nEnter 3 for postfix evaluation\nEnter 4 for prefix evaluation:\n";
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << "Enter the infix:\n";
        cin >> infix;
        postfix = infixToPostfix(infix);
        cout << "Postfix Expression: " << postfix << endl;
        break;
    case 2:
        cout << "Enter the infix:\n";
        cin >> infix;
        prefix = infixToPrefix(infix);
        cout << "Prefix Expression: " << prefix << endl;
        break;
    case 3:
        cout << "Enter the postfix expression:\n";
        cin >> postfix;
        cout << "Postfix Evaluation Result: " << postfixEvaluation(postfix) << endl;
        break;
    case 4:
        cout << "Enter the prefix expression:\n";
        cin >> prefix;
        reverse(prefix.begin(), prefix.end());
        cout << "Prefix Evaluation Result: " << prefixEvaluation(prefix) << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
    }
    return 0;
}
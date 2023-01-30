#include "Stack.h"

string infixToPostfix(string);
bool isOperand(char);
int precedence(char);
double evalPostfix(string);
double pow(double, double);

int main()
{
  string infix, postfix;
  ifstream file("expr.txt");
  if (file.is_open())
  {
    while (getline(file, infix))
    {
      postfix = infixToPostfix(infix);
      cout << "Infix: " << infix << " Postfix: " << postfix << endl;
      cout << "Result: " << evalPostfix(postfix) << endl;
    }
    file.close();
  }
  else
  {
    cout << "Unable to open file";
  }

  return 0;
}

string infixToPostfix(string infix)
{
  char c;
  string postfix = "";
  Stack<char> stack;
  string operand = "";

  for (int i = 0; i < infix.length(); i++)
  {
    if (infix[i] == ' ' || infix[i] == ',')
      continue;
    c = infix[i];
    if (isOperand(c))
    {
      operand += c;
      if (i == infix.length() - 1 || !isOperand(infix[i + 1]))
      {
        postfix += operand + " ";
        operand = "";
      }
    }
    else if (c == '(')
    {
      stack.push(c);
    }
    else if (c == ')')
    {
      while (stack.peek() != '(')
      {
        postfix += stack.pop();
        postfix += " ";
      }
      stack.pop();
    }
    else
    {
      while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek()))
      {
        postfix += stack.pop();
        postfix += " ";
      }
      stack.push(c);
    }
  }

  while (!stack.isEmpty())
  {
    postfix += stack.pop();
    postfix += " ";
  }

  return postfix;
}

double evalPostfix(string postfix)
{
  Stack<double> stack;
  double op1, op2;
  string operand = "";

  for (int i = 0; i < postfix.length(); i++)
  {
    if (postfix[i] == ' ' || postfix[i] == ',')
      continue;
    if (isOperand(postfix[i]))
    {
      operand += postfix[i];
      if (i == postfix.length() - 1 || !isOperand(postfix[i + 1]))
      {
        stack.push(stod(operand));
        operand = "";
      }
    }
    else
    {
      op2 = stack.pop();
      op1 = stack.pop();
      switch (postfix[i])
      {
      case '+':
        stack.push(op1 + op2);
        break;
      case '-':
        stack.push(op1 - op2);
        break;
      case '*':
        stack.push(op1 * op2);
        break;
      case '/':
        stack.push(op1 / op2);
        break;
      case '^':
        stack.push(pow(op1, op2));
        break;
      case '%':
        stack.push((int)op1 % (int)op2);
        break;
      }
    }
  }

  return stack.pop();
}

double pow(double base, double exp)
{
  double result = 1;
  for (int i = 0; i < exp; i++)
  {
    result *= base;
  }
  return result;
}

bool isOperand(char c)
{
  if (c >= '0' && c <= '9')
    return true;
  if (c >= 'a' && c <= 'z')
    return true;
  if (c >= 'A' && c <= 'Z')
    return true;
  return false;
}

int precedence(char c)
{
  if (c == '^')
    return 3;
  if (c == '*' || c == '/' || c == '%')
    return 2;
  if (c == '+' || c == '-')
    return 1;
  return -1;
}
#include <iostream>
#include <string>



using namespace std;

#define MAX_SIZE 1000

template <typename T>
struct Stack {
  int top;
  T element[MAX_SIZE];

  Stack() {
    top = 0;
  }
  int size() {
    return top;
  }
  void clear() {
    for (int i = top; i >= 0; i--) {
      element[i] = NULL;
    }
    top = 0;
  }
  void push(T e) {
    if (top < MAX_SIZE) {
      element[top] = e;
      top++;
    }
  }
  T pop() {
    T e;
    if (top > 0) {
      top--;
      e = element[top];
      element[top] = NULL;
      return e;
    }
  }
  T back() {
    return element[top - 1];
  }
  bool empty() {
    return top == 0;
  }
};
struct Queue {
  int element[MAX_SIZE];
  int first, last;

  Queue() {
    first = 1;
    last = 0;
  }

  void push(int e) {
    if (last < MAX_SIZE - 1) {
      last++;
      element[last] = e;
    }
  }

  int front() {
    return element[first];
  }

  int back() {
    return element[last];
  }

  int pop() {
    int e;
    e = element[first];
    first++;
    return e;
  }

  int size() {
    return (last + 1) - first;
  }

  void clear() {
    for (int i = first; i >= 1; i--) {
      element[i] = 0;
    }
    first = 1;
    last = 0;
  }

};


int chtoi(char c) {
  int ret = 0;
  if (c >= '0' && c <= '9') {
    return ret * 10 + c - '0';
  }
}
bool checkNum(char c) {
  if (c >= '0' && c <= '9') {
    return true;
  }
  return false;
}
int calculate(int a, char ch, int b) {
  switch (ch) {
  case '-':	return a - b;
    break;
  case '+': return a + b;
    break;
  case '*': return a * b;
    break;
  case '/': return a / b;
    break;
  default:
    break;
  }
}



Stack<char> stringToStackChar(string input) {
  Stack<char> tmp;
  for (int i = input.size() - 1; i > -1; i--) {
    tmp.push(input[i]);
  }
  return tmp;
}
int calculateInversePolishNotation(string input) {
  Stack<char> read = stringToStackChar(input);
  Stack<int> calc;

  while (read.empty() != true) {
    if (checkNum(read.back())) {
      calc.push(chtoi(read.pop()));
    } else {
      calc.push(calculate(calc.pop(), read.pop(), calc.pop()));
    }
  }
  return calc.pop();
}



void Task3() {
  string in = "";
  int out = 0;

  cin >> in;

  out = calculateInversePolishNotation(in);
}

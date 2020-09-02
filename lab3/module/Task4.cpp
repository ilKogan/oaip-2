#include <iostream>

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


bool checkBracketsBalance(string userInput) {
  Stack<char> brackets;
  int left = 0;
  int right = 0;

  for (int i = 0; i < userInput.size();i++) {
    switch (userInput[i]) {
    case '(': 
      brackets.push(userInput[i]);
      left++;
      break;
    case ')':
      brackets.push(userInput[i]);
      right++;
        break;
    default:
      cout << "Input error";
      break;
    }
  }
  return left == right;
}

void Task4() {
  char input[100] ;
  cin >> input;
  cout.setf(ios::boolalpha);
  cout << checkBracketsBalance(input);;

}


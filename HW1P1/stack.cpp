using namespace std;
#include <iostream>
#include "stack.h"

stack::stack() {
  top = -1; 
}

stack::~stack(){

}

bool stack::isEmpty() {
  if(top == -1) {
    return true;
  } else {
    return false;
  }
}

bool stack::isFull(){
  if(top == MAX-1) {
    return true;
  } else {
    return false;
  }
}

void stack::push(el_t elem) {
  if(isFull()){
    throw Overflow();
  } else {
    top++;
    el[top] = elem;
  }
}

void stack::pop(el_t &elem) {
  if(isEmpty()) {
    throw Underflow();
  } else {
    elem = el[top];
    top--;
  }
}

void stack::topElem(el_t& elem) {
  if (isEmpty()) {
    throw Underflow();
  } else {
    elem = el[top];
  }
}

void stack::displayAll(){
  cout << "STACK:---------" << endl;
  if(isEmpty()) {
    cout << " [ empty ] " << endl;
  } else {
    for(int i = top; i > 0; i--) {
      cout << el[i] << endl;
    }
  }
  cout << "--------------" << endl;
}

void stack::clearIt() {
  el_t temp;
  while(isEmpty() != true) {
    pop(temp);
  }
}
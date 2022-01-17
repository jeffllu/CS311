using namespace std;
#include <iostream>
#include "queue.h"

queue::queue(){
  rear = -1;
  front = 0;
  count = 0;
}

queue::~queue(){
}

bool queue::isEmpty(){
  if(count == 0) {
    return true;
  } else {
    return false;
  }
}

bool queue::isFull(){
  if(count == MAX_SIZE-1) {
    return true;
  } else {
    return false;
  }
}

void queue::add(el_t newElem) {
  if(isFull()) {
    throw Overflow();
  } else {
    rear = (rear+1)%MAX_SIZE;
    el[rear] = newElem;
    count++;
  }
}

void queue::remove(el_t& removedElem) {
  if(isEmpty()) {
    throw Underflow();
  } else {
    removedElem = el[front];
    front = (front+1)%MAX_SIZE;
    count--;
  }
}

void queue::frontElem(el_t& theElem) {
  if(isEmpty()) {
    throw Underflow();
  } else {
    theElem = el[front];
  }
}

int queue::getSize(){
  return count;
}


void queue::displayAll(){
  if(isEmpty()) {
    cout << "[ empty ]" << endl;
  } else {
    cout << "[";
    for(int i = front; i <= count; i++) {
      cout << el[i] << " ";
    }
    cout << "]" << endl;
  }
}

void queue::goToBack(){
  if (isEmpty()) {
    throw Underflow();
  }
  el_t temp;
  if(count > 1) {
    remove(temp);
    add(temp);
  }
}
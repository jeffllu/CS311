#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
  stack postfixstack;  
  string expression;   
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  
  char item;  
  
  int box1; 
  int box2; 
  
  while (expression[i] != '\0')
    {
     try
       {
	 item = expression[i];  
	
	 if(item >= '0' && item <= '9'){
	   postfixstack.push(item-48);
	 }
	 else if(item == '+' || item == '-' || item == '*') {
	   postfixstack.pop(box1);
	   postfixstack.pop(box2);
	   if(item == '-') {
	     box1 = box2 - box1;
	   } else if (item == '+'){
	     box1 = box2 + box1;}
	   else if (item == '*'){
	     box1 = box2 * box1;}
	   postfixstack.push(box1);}
	 else throw "Error: Invalid Item";}
	   
      catch (stack::Overflow) 
	{cerr << "Expression too long" << endl; exit(1); }
      catch (stack::Underflow)
	{cerr << "Expression too short" << endl; exit(1); }
      catch (char const* errormsg ) 
	{cerr << errormsg << endl; exit(1) ;}

	 i++;
    }
  

     postfixstack.pop(box1);
     cout << "Result: " << box1 << endl;

     if(!postfixstack.isEmpty()) {
       cout << "Error: Incomplete expression" << endl;}

}

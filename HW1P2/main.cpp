using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"

int main()
{ 
  queue abc;
  abc.add("A");
  abc.add("B");
  abc.add("C");

  while (true)
    {
      try
	{ 
	  string temp;
	  abc.remove(temp);
	  cout << temp << endl;
	  abc.add(temp + "A");
	  abc.add(temp + "B");
	  abc.add(temp + "C");
	}
    
	  catch(queue::Overflow) 
	    {cerr << "Cannot add" << endl; exit(0);}
	  catch(queue::Underflow)
	    {cerr << "Expression too short" << endl; exit(0); }
    }

}
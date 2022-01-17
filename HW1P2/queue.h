using namespace std;
#include<string>

typedef string el_t;      

const int MAX_SIZE = 50;  

class queue  
{
  private:
    el_t el[MAX_SIZE]; 
  int  count;          
  int  front;          
  int  rear;           

  public:   

  class Overflow{}; 
  class Underflow{};

   queue();  
   ~queue();  

   bool isEmpty();

   bool isFull();

   void add(el_t);

   void remove(el_t&);

   void frontElem(el_t&);

   int getSize();

   void displayAll();

   void goToBack();


};           
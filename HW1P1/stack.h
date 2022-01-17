const int MAX = 10;
typedef int el_t;

class stack{
  private:
    el_t el[MAX];
    int top;
  public:
    class Overflow{};
    class Underflow{};

    stack();
    ~stack();
    void push(el_t);
    void pop(el_t&);
    void topElem(el_t&);
    bool isEmpty();
    bool isFull();
    void displayAll();
    void clearIt();
};
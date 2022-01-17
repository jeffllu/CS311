using namespace std; //1238 3792
#include <iostream>
#include <vector>

void combine(vector<int> A, vector<int> B, vector<int> &R) {
  int ia = 0;
  int ib = 0;
  int ir = 0;
  while(ia < A.size() && ib < B.size()) {
    if(A[ia] < B[ib]) {
      R[ir] = A[ia];
      ia++;
    } else {
      R[ir] = B[ib];
      ib++;
    }
    cout << "comparison" << endl;
    ir++;
  }
  if(ia < A.size()) {
    while(ia < A.size()) {
      R[ir] = A[ia];
      ia++;
    }
  } else {
    while(ib < B.size()) {
      R[ir] = B[ib];
      ib++;
      ir++;
    }
  }
}

int main(){
  vector<int> L1;
  vector<int> L2;
  vector<int> L3;
  int N;  
  int e;  

  cout << "How many elements in each list?" << endl;
  cin >> N;
  L3.resize(2*N);

  cout << "List1"  << endl;
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L1.push_back(e);} 

  cout << "List2"  << endl; 
  for (int i = 1; i <=N; i++)
    { cout << "element :"; cin >> e; L2.push_back(e);} 
  
  combine(L1, L2, L3);
  cout << "The result is: ";
  for (int i = 0; i < N*2; i++)
    { cout << L3[i]; } cout << endl;
}

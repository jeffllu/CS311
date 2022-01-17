using namespace std;
#include <iostream>
#include <cmath>

int binarySearch(int L[], int x, int first, int last) 
{
  int middle = floor((first+last)/2);
  cout << "comparing against an element in slot " << middle << endl;
  if (x == L[middle]){
    return middle;
  } else if (x < L[middle]) {
    last = middle - 1;
  } else if (x > L[middle]) {
    first = middle + 1;
  }
  return binarySearch(L, x, first, last);
  if(first >= last ){
    return -1;
  }
}


int main()
{ 
  int A[10];
  int e; 

  A[0] = 1; A[1]= 3; A[2]=5; A[3]= 7; A[4]=9; A[5]=11; A[6]=13;
  A[7] =15; A[8]= 17; A[9]= 19;

  for(int i = 0; i < 10; i++) {
    cout << A[i] << " ";
  }
  cout << endl << "What do you want to look for? ";
  cin >> e;

  int respos = binarySearch(A, e, 0, 9);
  if (respos == -1) cout << "Element not found" << endl; 
  else cout << "Found it in position " << respos+1 << endl;
}

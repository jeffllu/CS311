#include <iostream>
using namespace std;

int partition(int a[], int f, int r) {
  int pivot = a[f]; //pivot is the first element
  int small = f; //pointer from the left
  int large = r; //pointer from the right
  int temp; 

  while (small <= large) {//until they cross
    while(a[small] < pivot) {
      small++;
    }
    while(a[large] > pivot) {
      large--;
    }
    if(a[large] <= pivot && a[small] >= pivot) { //swap if both are bad
      temp = a[small];
      a[small] = a[large];
      a[large]= temp;
      small++;
      large--;
    }
  }
  return small;
}

int main(){
  int x;
  int nums[10];
  cout << "How many elements? (must be less than 10) ";
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for(int i = 0; i < x; i++) {
    cin >> nums[i];
  }
  //the pivot is always the first element
  cout << "Ok the pivot is " << nums[0] << endl;

  int part = partition(nums, 0, x-1);
  cout << "Results..." << endl;
  for(int i = 0; i < part; i++) {
    cout << nums[i];
  }
  cout << "|";
  //display from the partition on.. without endl
  for(int i = part; i < x; i++) {
    cout << nums[i];
  }

  cout << endl;
}

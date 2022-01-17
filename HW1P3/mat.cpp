#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int const R = 3;
int const C = 4;
int const VM = 3;

vector <char> T[R][C]; //3 rows, 4 columns

int convert(char x){
  return x - 'a';
}

int readTable(){
  int row, col;
  char col_c;
  ifstream fin("lines.txt", ios::in);

  while (fin >> row){ //getting row number
    fin >> col_c; //getting column number
    col = convert(col_c);
    vector<char> v;
    char c;

    for(int i = 0; i < VM; i++) {
      fin >> c; //getting all chars after the space
      v.push_back(c);
    }
    T[row][col] = v;
  }
}

void showVector(vector<char> v, ostream& ost) {
  if(v.size() == 0) {
    for (int i = 1; i < VM; i++) {
      cout << "- ";
    }
  } else {
    for( int x = 0; x < v.size(); x++) {
      cout << " " << v[x];
    }
  }
}

void displayTable(){
  for(int r = 0; r < R; r++) {
    cout << r;
    for (int c = 0; c < C; c++) {
      cout << "|";
      showVector(T[r][c], cout);
    }
    cout << endl;
  }
}


int main() {
  cout << "Reading table from lines.txt..." << endl;
  readTable();
  displayTable();
}
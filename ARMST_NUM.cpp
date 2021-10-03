#include <iostream>
using namespace std;
int cube(int x) { return x * x * x; }
int main() {
  int n;
  cout << "Enter the Number: ";
  cin >> n;
  int temp = n, sum = 0;
  while (n > 0) {
    sum = sum + cube(n % 10);
    n = n / 10;
  }
  if (temp == sum)
    cout << "\nGiven Number is Armstrong Number." << endl;
  else
    cout << "\nGiven Number is Not Armstrong Number." << endl;
  return 0;
}
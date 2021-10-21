#include <iostream>
#include <limits>

using namespace std;

int main() {

  int nr = 5;
  // double allNumbers[nr];

  /* Test #0 */
  // double allNumbers[nr] = {1.5, 3.14, 7.5, 1.25, 3.42};

  /* Test #1 */
  double allNumbers[nr] = {-55, -44, -33, 11, 22};

  double sumNumbers = 0;
  double average = 0;
  double lowNumber = numeric_limits<double>::lowest();
  double lowNumberDifference = 0;
  double highNumber = numeric_limits<double>::max();
  double highNumberDifference = 0;
  double closestNumber = 0;

  cout << "Enter 5 numbers: ";
  cout << '\n';

  for (int i=0; i<nr; i++) {

    // cin >> allNumbers[i];

    sumNumbers += allNumbers[i];
  }

  average = sumNumbers / nr;

  for (int i=0; i<nr; i++) {

    cout << "Number " << i << ": " << allNumbers[i] << '\n';

    if (allNumbers[i] <= average && allNumbers[i] >= lowNumber) {
      lowNumber = allNumbers[i];
    }
    else if (allNumbers[i] >= average && allNumbers[i] <= highNumber) {
      highNumber = allNumbers[i];
    }
  }

  lowNumberDifference = average - lowNumber;
  highNumberDifference = highNumber - average;

  if (lowNumberDifference <= highNumberDifference) {
    closestNumber = lowNumber;
  }
  else {
    closestNumber = highNumber;
  }

  cout << '\n';
  cout << "Average = " << average;

  cout << '\n';
  cout << "Closest Number = " << closestNumber;

  cout << '\n';
  cout << "Low Number = " << lowNumber;

  cout << '\n';
  cout << "High Number = " << highNumber;  

  cout << '\n';
  cout << "Low Number Difference = " << lowNumberDifference;

  cout << '\n';
  cout << "High Number Difference = " << highNumberDifference;  
}
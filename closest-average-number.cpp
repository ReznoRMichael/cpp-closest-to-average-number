#include <iostream>

/* This allows us to use lowest/highest possible number of a variable (like double)
https://en.cppreference.com/w/cpp/types/numeric_limits/ */
#include <limits>

using namespace std;

int main() {

  /* how many total numbers there are */
  int nr = 5;

  /* uncomment for manual user input */
  // double allNumbers[nr];

  /* Test #0 */
  // double allNumbers[nr] = {1.5, 3.14, 7.5, 1.25, 3.42};

  /* Test #1 */
  // double allNumbers[nr] = {-55, -44, -33, 11, 22};

  /* Test #2 */
  // double allNumbers[nr] = {3, 5, 3, 1, 3};

  /* Test #3 */
  double allNumbers[nr] = {6.5, 3.5, 0, 15, 0};

  /* For storing average value and sum of all numbers */
  double sumNumbers = 0;
  double average = 0;

  /* 
  https://en.cppreference.com/w/cpp/types/numeric_limits/lowest
  https://en.cppreference.com/w/cpp/types/numeric_limits/max
  */
  double lowNumber = numeric_limits<double>::lowest(); // lowest possible number in double
  double highNumber = numeric_limits<double>::max(); // highest possible number in double

  /* For storing differences between average and lowNumber/highNumber */
  double lowNumberDifference = 0;
  double highNumberDifference = 0;

  /* Store closest number */
  double closestNumber = 0;

  /* ======================= Program Start ========================= */

  cout << "Enter 5 numbers: ";
  cout << '\n';

  for (int i=0; i<nr; i++) {

    /* uncomment for manual user input */
    // cin >> allNumbers[i];

    /* Calculate sum of all numbers */
    sumNumbers += allNumbers[i];
  }

  /* Calculate average of all numbers */
  average = sumNumbers / nr;

  for (int i=0; i<nr; i++) {

    cout << "Number " << i << ": " << allNumbers[i] << '\n';

    /* Find closest number below average */
    if (allNumbers[i] <= average && allNumbers[i] > lowNumber) {
      lowNumber = allNumbers[i];
    }
    /* Find closest number above average */
    else if (allNumbers[i] >= average && allNumbers[i] < highNumber) {
      highNumber = allNumbers[i];
    }
  }

  /* Calculate what is the difference between average and found numbers, so a comparison can be made to find the closest one */
  lowNumberDifference = average - lowNumber;
  highNumberDifference = highNumber - average;

  /* Find the closest number from the two */
  if (lowNumberDifference <= highNumberDifference) {
    closestNumber = lowNumber;
  }
  else {
    closestNumber = highNumber;
  }

  /* ==================== Show calculation results =================== */

  cout << "-------------\n";
  cout << "Average        = " << average;

  cout << '\n';
  cout << "Closest Number = " << closestNumber;

  /* Optionally show 2 closest numbers, if both have the same difference to the average */
  if (lowNumberDifference == highNumberDifference) {
    cout << '\n';
    cout << "Closest Number #2 = " << highNumber;
  }

  cout << "\n-------------\n";
  cout << "Low Number  = " << lowNumber;

  cout << '\n';
  cout << "High Number = " << highNumber;  

  cout << "\n-------------\n";
  cout << "Low Number Difference  = " << lowNumberDifference;

  cout << '\n';
  cout << "High Number Difference = " << highNumberDifference;  
}
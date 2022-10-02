#include <iostream>

/*
Author: Ewa Zalewska
Concept: BMI calculator
All rights reserved
Github: https://github.com/Mewwaa
*/

using namespace std;

int ask_number(){

  int number ;

  cin >> number;
  while (cin.fail() || number < 0 ) {

    cout << "Enter a positive integer please" << '\n';

    cin.clear();
    cin.ignore(256,'\n');
    cin >> number;

  }
  return number;
}

int main () {
  int fromYear , toYear, total_years =0 ;

  cout << "Enter the year you wanna start" << '\n';
  fromYear = ask_number();

  cout << "Enter the year you wanna end" << '\n';
  toYear = ask_number();
  while (toYear<=fromYear) {
    cout << "ending year should be smaller then starting year" << '\n';
    toYear = ask_number();
  }

  for (int i = fromYear-1; i < toYear+1; i++) {

    if ((i%100)!=0 ? (i%4==0) : i%400==0 ) {
      cout << i << '\n';
      total_years++;
    }

  }
  cout << "total number of leap years in betweeen :"<< total_years << '\n';

  return 0;

}

/*
Given a decimal number (integer N), convert it into binary and print.
The binary number should be in the form of an integer.
Note : The given input number could be large, so the corresponding binary number can exceed the integer range. So you may want to take the answer as long for CPP and Java.

Input format :
Integer N
Output format :
Corresponding Binary number (long)
Constraints :
0 <= N <= 10^5
Sample Input 1 :
12
Sample Output 1 :
1100
Sample Input 2 :
7
Sample Output 2 :
111

*/
#include<iostream>
#include<cmath>
using namespace std;
int main(){
 int N;
 cin>>N;
 int rem, count=0;
 long int binary=0;
 while(N!=0){
     rem=N%2;
    //  cout<<"rem: "<<rem;
     binary+=rem*pow(10, count);
    //  cout<<"binary: "<<binary;
     N=N/2;
    //  cout<<"N: "<<N;
     count++;
 }
 cout<<binary;
}
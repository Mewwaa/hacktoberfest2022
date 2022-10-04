#include<iostream>
using namespace std;
int binary_Search(int array[],int start, int end, int searchedElement){
    int mid=(start+end)/2;
    if (start<=end){
        if (array[mid]==searchedElement){
            return mid;
        }
        else if( array[mid]>searchedElement){
            return binary_Search(array, start, mid-1, searchedElement);
        }
        else if(array[mid]<searchedElement){
            return binary_Search(array, mid+1, end, searchedElement);
        }
    }
    else {
        return -1;
    }
    
}
int main(){
 int number_of_testqueries, array[50], testqueries_array[50], arraySize;
 cin>>arraySize;
 for(int i=0; i<arraySize; i++){
     cin>>array[i];
 }
 cin>>number_of_testqueries;
 for(int i=0; i<number_of_testqueries; i++){
     cin>>testqueries_array[i];
 }
 for(int i=0; i<number_of_testqueries; i++){
     cout<<binary_Search(array, 0, arraySize-1, testqueries_array[i])<<endl;;;
 }

}
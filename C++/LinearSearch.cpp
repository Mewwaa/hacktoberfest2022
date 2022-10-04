#include<iostream>
using namespace std;
int LinearSearch(int array[], int n, int searched_element){
    for(int i=0;i<n;i++){
        if (array[i]==searched_element){
            return i;
        }
    }
    return -1;
}
int main(){
 int array[50];
 int n, searched_element;
 cin>>n;
 cin>>searched_element;
 for(int i=0;i<n;i++){
     cin>>array[i];
 }
 int storage=LinearSearch(array, n, searched_element);
 if (storage!=-1){
     cout<<"Searched element is present in the array at "<<storage<<" index. ";
 }
 else{
     cout<<"Searched element is not present in the array.";
 }

}
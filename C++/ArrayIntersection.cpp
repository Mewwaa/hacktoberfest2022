#include<iostream>
using namespace std;

void merge(int array[], int start, int mid, int end){
    int i=start, j=mid, k=0;
    int temparray[100];
    while(i<mid && j<end){
        if (array[i]<array[j]){
            temparray[k]=array[i];
            i++;
        }
        else{
            temparray[k]=array[j];
            j++;
        }
        k++;
    }
    while(i<mid){
        temparray[k]=array[i];
        i++;
        k++;
    }
    while(j<end){
        temparray[k]=array[j];
        j++;
        k++;
    }
    for(int m=start, l=0; m<end, l<k; m++,l++){
        array[m]=temparray[l];
    }
    
}
void merge_sort_array(int array[], int start, int end){
    if (end-1>start){
        int mid=(start+(end))/2;
        merge_sort_array(array, start,mid);
        merge_sort_array(array, mid, end);
        merge(array, start, mid, end);
    }    
}
void find_intersection(int array1[],int start1, int end1, int array2[], int start2, int end2){
    merge_sort_array(array1, start1, end1);
    merge_sort_array(array2, start2, end2);
    int i=start1, j=start2, k=0;
    int temparray[100];
    while(i<end1 && j<end2){
        if (array1[i]==array2[j]){
            temparray[k]=array1[i];
            i++;
            j++;
            k++;
        }
        else if(array1[i]<array2[j]){
            i++;
        }
        else if(array1[i]>array2[j]){
            j++;
        }
    }
    for(int l=0; l<k; l++){
        cout<<temparray[l]<<" ";
    }

}


int main(){
 int t;
 cin>>t; //number of testqueries

 int test_queries[10],array1[20], array2[20];
 int ind1=0, ind2=0;

 for(int j=0;j<2*t; j++){

    cin>>test_queries[j];
    int i;
    for(i=ind1; i<test_queries[j]+ind1; i++){
        cin>>array1[i];
    }
    ind1=i;
    j++;
    cin>>test_queries[j];
    for(i=ind2; i<test_queries[j]+ind2; i++){
        cin>>array2[i];
    }
    ind2=i;
 }
ind1=0;
ind2=0;
for(int j=0;j<2*t; j=j+2){
      find_intersection(array1, ind1, test_queries[j]+ind1, array2, ind2, test_queries[j+1]+ind2);
      ind1=ind1+test_queries[j];
      ind2=ind2+test_queries[j+1];
      cout<<endl;
    }

}

/*
1
4
3 5 6 3
3
5 6 4
*/
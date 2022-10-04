//Problem:We have to place N-Queen on NxN matrix such that no Queen cuts each other.
//Problem Link:https://leetcode.com/problems/n-queens/
#include<iostream>
using namespace std;

bool isSafe(int** arr,int x,int y,int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }
    //FOR DOWNWARD DIAGONAL
    int col=0;
    int row=0;
    while(col<n && row<n){
        if(arr[x][y]==1){
            return false;
        }
        col++;
        row++;
    }
    //FOR UPWARD DIAGONAL
    col=x;
    row=y;
    while(col<n && row>=0){
        if(arr[x][y]==1){
            return false;
        }
        col++;
        row--;
    }
    return true;

}

bool nQueen(int **arr,int x,int n){
    if(x>=n){
        return true;
    }
    for(int col=0;col<n;col++){
    if(isSafe(arr,x,col,n)==true){
        arr[x][col]=1;
        if(nQueen(arr,x,n)==true){
            return true;
        }    
        arr[x][col]=0;//This is backtracking
    }
}
    return false;
}

int main(){
    int n;
    cin>>n;

    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j];
        }
    }

    if(nQueen(arr,0,n)==true){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }

    }

    return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    // string str;
    char str[100];
    cin>>str;
    int count=49;
    char last_char=str[0];
    int j=0;
    // for(int i=1;i<=str.length(); i++){
    for(int i=1;i<=strlen(str); i++){
        if(last_char!=str[i]){
            last_char=str[i];
            if (count>49)
            {
                str[++j]=count;
                count=49;
            }
            str[++j]=last_char;
        }
        else{
            count++;
        }
    }
    cout<<j<<endl;
    str[j]='\0';
    cout<<str;
 
}
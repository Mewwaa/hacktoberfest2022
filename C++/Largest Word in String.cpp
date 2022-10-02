#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Length of String: ";
    cin>>n;
    cin.ignore();
    char str[n+1];
    cout<<"Enter the string: ";
    cin.getline(str,n);
    cin.ignore();
    int i=0,currlen=0,maxlen=0;
    int st=0,maxst=0;
    while(1)
    {
        if(str[i]==' ' || str[i]=='\0')
        {
            if(currlen>maxlen)
            {
                maxlen=currlen;
                maxst=st;
            }
            currlen=0;
            st=i+1;
        }
        else
        currlen++;
        if(str[i]=='\0')
        {
            break;
        }
        i++;
    }

    cout<<"Maximum Length: "<<maxlen<<endl;
    cout<<"Maximum Word: ";
    for(int j=0;j<maxlen;j++)
    {
        cout<<str[j+maxst];
    }
    return 0;
}

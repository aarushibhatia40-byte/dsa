#include<iostream>
using namespace std;

int main()
{
    int a[100],n;

    cout<<"Enter size: ";
    cin>>n;

    cout<<"Enter elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Reverse array: ";
    for(int i=n-1;i>=0;i--)
        cout<<a[i]<<" ";

    return 0;
}
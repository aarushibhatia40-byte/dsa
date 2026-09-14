#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string arr[]={"Banana", "Apple", "Mango", "Orange"};
    int n=4;

    sort(arr, arr+n);

    cout<<"Strings in alphabetical order:"<<endl;

    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
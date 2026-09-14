#include<iostream>
#include<cctype>
using namespace std;

int main(){
    char ch;

    cout<<"Enter an uppercase character: ";
    cin>> ch;

    ch = tolower(ch);

    cout<<"Lowercase character: "<< ch;

    return 0;
}
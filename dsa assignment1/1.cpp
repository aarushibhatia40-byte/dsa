#include<iostream>
using namespace std;

int main()
{
    int a[100], n=0,ch,pos,value,key;

    while(1)
    {
        cout<<"\n1.CREATE";
        cout<<"\n2.DISPLAY";
        cout<<"\n3. INSERT";
        cout<<"\n4.DELETE";
        cout<<"\n5. LINEAR SEARCH";
        cout<<"\n6.EXIT";

        cout<<"\nEnter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"Enter size: ";
                cin>>n;

                for(int i=0;i<n;i++)
                    cin>>a[i];
                break;

            case 2:
                cout<<"Array: ";
                for(int i=0;i<n;i++)
                    cout<<a[i]<<" ";
                break;

            case 3:
                cout<<"Enter position and value: ";
                cin>>pos>>value;

                for(int i=n;i>pos;i--)
                    a[i]=a[i-1];
                a[pos]=value;
                n++;
                break;

            case 4:
                cout<<"Enter position: ";
                cin>>pos;

                for(int i=pos;i<n-1;i++)
                    a[i]=a[i+1];
                n--;
                break;

            case 5:
                cout<<"Enter value: ";
                cin>>key;

                for(int i=0;i<n;i++)
                {
                    if(a[i]==key)
                    {
                        cout<<"Found at position "<<i;
                        break;
                    }

                    if(i==n-1)
                        cout<<"Element not found";
                }
                break;

            case 6:
                return 0;

            default:
                cout<<"Wrong choice";
        }
    }
}
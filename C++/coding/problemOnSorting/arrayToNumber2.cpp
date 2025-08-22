#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int b=0;
    for(int i=0; i<n; i++){
        int min=INT_MAX;
        int mindx=-1;
        for(int j=0; j<n; j++){
            if(min>a[j] && a[j]>0){
                min=a[j];
                mindx=j;
            }
        }
        a[mindx]=b;
        b--;

    }
    for(int i=0; i<n; i++){
       if(a[i]<0){
        cout<<a[i]*(-1)<<" ";
       }
       else cout<<a[i]<<" ";
    }
}
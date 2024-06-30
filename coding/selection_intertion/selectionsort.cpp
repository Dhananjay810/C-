#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int ele : a){               // FOR EACH loop
        cout<<ele<<" ";
    }
    cout<<endl;
    // insertion sorting
    for(int i=0; i<n-1; i++){
        int min =INT_MAX;
        int mindex = -1;
        for(int j=i; j<n; j++){
            if(a[j]<min){
            mindex=j;
            min=a[j];
            }
        }
        swap(a[i],a[mindex]);
    }
    for(int ele : a){
        cout<<ele<<" ";
    }
}

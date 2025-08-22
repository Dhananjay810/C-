#include <iostream>
using namespace std;
int sort(int a[], int n){
    int fst=0, end=n-1,temp,mid=0;
    while(mid<end){
        if(a[mid]==2){
            a[end]=temp;
            a[end]=a[mid];
            a[mid]=temp;
            end--;

        }
        else if(a[mid]==0){
            a[fst]=temp;
            a[fst]=a[mid];
            a[mid]=temp;
            fst++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<a[i];
    }
}
int main(){
    int n;
    cout<<"enter no. of element : ";
    cin>>n;
    int array[n];
    cout<<"enter value : ";
    for(int i=0; i<n; i++)
    {
        cin>>array[i];
    }

    int y = sort(array,n);
}
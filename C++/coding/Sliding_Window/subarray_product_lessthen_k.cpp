#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={10,5,2,6};
    int k=100;
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=0,count=0,product=1;
    while(j<n){
        product *= arr[j];
        while(product>=k){
            count = count+(j-i);
            product /= arr[i];
            i++;
        }
        j++;
    }
    while(i<n){
        count += (j-i);
        product /= arr[i];
        i++;
    }
    cout<<count;
}
#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={1,0,1,1,0,0,1,1,1,1,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=2;
    int maxlen=INT_MIN;
    int i=0,j=0,flip=0;
    int len=0;
    while(j<n){
        if(arr[j]==1) j++;
        else{
            if(flip<k){
                flip++;
                j++;
            }
            else{
                len=j-i;
                maxlen=max(maxlen,len);
                while(arr[i]==1){
                    i++;
                }
                i++;
                j++;
            }
        }
    }
    len=j-i;
    maxlen=max(maxlen,len);
    cout<<maxlen;
}
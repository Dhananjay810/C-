#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[]={1,1,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0,j=0,len=0;
    int maxlen=INT_MIN;
    int rem=0;
    while(j<n){
        if(arr[j]==1) j++;
        else{
            if(rem<1){
                rem++;
                j++;
            }
            else{
                len=j-i-1;
                maxlen=max(maxlen,len);
                while(arr[i]==1) i++;
                i++;
                j++;;
            }
        }
    }
    len=j-i-1;
    maxlen=max(maxlen,len);
    cout<<maxlen;
}
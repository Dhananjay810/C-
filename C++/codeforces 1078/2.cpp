#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int maxa=-1;
        for(int i=0; i<n; i++){
            int num;
            cin>>num;
            maxa=max(maxa,num);
        }
        cout<<maxa*n<<endl;
    }
}
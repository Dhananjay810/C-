#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(4);
    for(int i=n+1; i>0; i++){
        int y=i;
        bool flag=false;
        for(int j=0; j<4; j++){
            int reminder=y%10;
            a[j]=reminder;
            y=y/10;
        }
        sort(a.begin(),a.end());
        for(int j=0; j<3; j++){
            if(a[j]==a[j+1]){
                flag=false;
                break;
            }
            else{
                flag=true;
                continue;
            }
        }
        if(flag==true){
            cout<<i;
            break;
        }
        else continue;
    }
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> a={5,8,6,7,5,9,10};
    for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";
    cout<<endl;
    int fi,se;
    if(a[0]>a[1]) fi=a[0];
    if(a[a.size()-1]<a[a.size()-2]) se=a[a.size()-1];
    for(int i=1; i<a.size()-1; i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            fi=i;
            i=i+2;
        }
        if(a[i]<a[i-1] && a[i]<a[i+1]){
            se=i;
            i=i+2;
        }
    }
    swap(a[fi],a[se]);
    for(int i=0; i<a.size(); i++) cout<<a[i]<<" ";
}
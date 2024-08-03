#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> t={1,2,3,4,5,6,7,8,9};
    int left=2;
    int right=4;
    for(int i=0; i<t.size(); i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
    reverse(t.begin()+left-1,t.end()-right-1);
    for(int i=0; i<t.size(); i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
}
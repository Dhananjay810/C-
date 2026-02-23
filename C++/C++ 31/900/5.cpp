#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        bool z=false;
        vector<int> zero;
        for(int i=0; i<n; i++){
            cin>>v[i];
            if(v[i]==0) zero.push_back(i);
        }
        if(n==2){
            cout<<"2"<<endl;
            cout<<"1"<<" "<<n<<endl;
            cout<<"1"<<" "<<n<<endl;
        }
        else{
            cout<<"4"<<endl;
            cout<<"1"<<" "<<"2"<<endl;
            cout<<"1"<<" "<<"2"<<endl;
            if(n%2==0){
                cout<<"3"<<" "<<n<<endl;
                cout<<"3"<<" "<<n<<endl;
            }
            else{
                cout<<"2"<<" "<<n<<endl;
                cout<<"2"<<" "<<n<<endl;
            }
        }
    }
}
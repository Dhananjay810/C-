#include<iostream>
using namespace std;
bool on(int n){
    int e=0;
    while(n>0){
        int rem=n%10;
        if(rem!=0) e++;
        n/=10;
        if(e>1) return false;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n<=9){
            cout<<n<<endl;
            continue;
        }
        int ans=9;
        for(int i=1; i<=9; i++){
            int y=i;
            y=y*10;
            while(y<=n){
                ans++;
                y=y*10;
            }
        }
        cout<<ans<<endl;
    }
}
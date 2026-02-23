#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
// bool isPalindrome(string s){
//     unordered_map<char,int> m;
//     for(int i=0; i<s.size(); i++) m[s[i]]++;
//     int odd=0;
//     for(auto x : m){
//         if(x.second%2!=0) odd++;
//     }
//     if(s.size()%2==0){
//         if(odd==0) return true;
//         return false;
//     }
//     else{
//         if(odd==1) return true;
//         return false;
//     }
// }
// bool f(string s, int i, string hh, int k){
//     if(i==s.size()){
//         if(k==0) return isPalindrome(hh);
//         else return false;
//     }
//     if(k==0){
//         for(int j=i; j<s.size(); j++){
//             hh += s[j];
//         }
//         return isPalindrome(hh);
//     }
//     return (f(s,i+1,hh,k-1) | f(s,i+1,hh+s[i],k));
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        unordered_map<char,int> m;
        bool ans=false;
        for(int i=0; i<n; i++) m[s[i]]++;
        int odd=0;
        for(auto x : m){
            if(x.second%2!=0) odd++;
        }
        int remov=max(0,odd-1);
        if(k<remov){
            cout<<"NO"<<endl;
            continue;;
        }
        int newsize=n-k;
        if(newsize>0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
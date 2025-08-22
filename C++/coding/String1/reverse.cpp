#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string n = "Dhananajay";
    cout<<n<<endl;
//    reverse(n.begin(),n.end());
//    cout<<n<<endl;

//    reverse(n.begin()+2,n.end()-1);  
//    cout<<n<<endl;
   reverse(n.begin()+1,n.begin()+5);
   cout<<n<<endl;
}
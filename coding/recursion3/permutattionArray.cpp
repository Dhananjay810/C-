 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 void sub(vector<int>& nums,vector<int> v){
   int n=nums.size();
   if(n==0){
      for(int i=0; i<v.size(); i++){
         cout<<v[i]<<" ";
      }
      cout<<endl;
      return;
   }
   for(int i=0; i<n; i++){
      int d=nums[i];
      v.push_back(nums[i]);
      vector<int> c;
      for(int j=0; j<n; j++){
         if(nums[j]!=nums[i]) c.push_back(nums[j]);
      }
      sub(c,v);
      v.pop_back();
   }
 }
 int main(){
    vector<int> nums={3,2,1};
   //  for(int i=0; i<3; i++){
   //    cout<<nums[i]<<" ";
   //  }
   //  cout<<endl;
   //  auto it = nums.begin() + 0;
   //  nums.erase(it);
   //  for(int i=0; i<nums.size(); i++){
   //    cout<<nums[i]<<" ";
   //  }
    vector<int> v;
    vector<vector<int>> s;
    sub(nums,v);
 }
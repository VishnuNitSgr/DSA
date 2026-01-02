#include<iostream>
using namespace std;
void findcount(string &  s,char target,int i,int &ans){
    if(i>=s.size())
    return;
    if(s[i]==target){
  
    ans=i;
  }
  findcount(s,target,i+1,ans);
 
}

    int main(){
    cout<<"enter the string"<<endl;
    string s;
    cin>>s;
    char target;
    cout<<"enter the target"<<endl;
    cin>>target;
    int ans=-1;
   findcount(s,target,0,ans);
    cout <<ans<<endl;
    return 0;
}
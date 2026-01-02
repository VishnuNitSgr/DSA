#include<iostream>
#include<string>
using namespace std;
int main(){
cout<<"enter the string"<<endl;
string s;
cin>>s;
int hash[26]={0};
for(int i=0;i<s.size();i++){
    hash[s[i]-'a']++;
}
cout<<"enter the queryies"<<endl;
int q;
cin>>q;
while(q--){
    char ch;
    cin>>ch;
    
    cout<<hash[ch-'a']<<endl;
}
return 0;
}
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    cout<<"enter the array size5"<<endl;
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    cout<<"enter the query";
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<mp[number]<<endl;
    }
    return 0;
}
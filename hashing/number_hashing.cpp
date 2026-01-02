#include<iostream>
#include<string>
using namespace std;
int main(){
    // this is a creation of number hashing
    cout<<"enter the array size5"<<endl;
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompute
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;

    }
    cout<<"enter the query";
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
    }
    return 0;
}



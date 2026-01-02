#include<iostream>
#include<vector>
using namespace std;
 void mergeTwoSortedArray(int arr1[],int n1,int arr2[],int n2,vector<int>& ans){
       int i,j=0;
       while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i++]);
        }
        else
        {
             ans.push_back(arr2[j++]);
        }
       }
       // is loop se bahar aane ke baad me hame pata chalega ki koi ek pointer out of bound chala gaya hai ya fir aise hoga ki ans vector poora sorted ban gaya hai
       while(i<n1){
        ans.push_back(arr1[i++]);
       }
       while(j<n2){
        ans.push_back(arr2[j++]);

       }
    }

int main(){
    int arr1[]={10,20,30};
    int size1=5;
    int arr2[]={5,15,25,30};
    int size2=4;
    vector<int>ans;
    mergeTwoSortedArray(arr1,size1,arr2,size2,ans);
    for(int num:ans){
        cout<<num<<" ";
    }
    return 0;
}
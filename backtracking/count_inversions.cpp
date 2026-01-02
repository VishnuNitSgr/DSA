#include<iostream>
using namespace std;
int main(){
    int arr[6]={8,4,5,6,1,5};
    int n=6;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                count++;

    }

    }


}
    
    return count;
}

#include<iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end){
    // creation of left and right arrays
    int leftLength=mid-start+1;
    int rightLength=end-mid;
    int* leftArray=new int[leftLength];
    int* rightArray=new int[rightLength];

    // fill and copy the left and right arrays
    // copy for the left array
    int index=start;
    for(int i=0;i<leftLength;i++){
        leftArray[i]=arr[index++];
    }
    //copy for the right array
    // index=mid+1;
     index=mid+1;
    for(int i=0;i<rightLength;i++){
        rightArray[i]=arr[index++];
    }

    int i=0,j=0;
    int mainArrayIndex=start;
    while(i<leftLength && j<rightLength){
        if(leftArray[i]<rightArray[j]){
            arr[mainArrayIndex++]=leftArray[i++];
        }
        else
        {
            arr[mainArrayIndex++]=rightArray[j++];
        }


}
while(i<leftLength){
    arr[mainArrayIndex++]=leftArray[i++];
}
while(j<rightLength){
    arr[mainArrayIndex++]=rightArray[j++];
}
// Free the allocated memory
delete[] leftArray;
delete[] rightArray;
}

void mergeSort(int arr[],int start,int end){
     
     if(start>=end)return;
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);

    merge(arr,start,mid,end);
}

int main(){
    int arr[]={10,80,110,90,50,30,40,20};
    
    int n=8;
    int s=0,e=n-1;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    mergeSort(arr,s,e);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
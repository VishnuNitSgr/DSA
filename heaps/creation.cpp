#include<iostream>
#include <vector>
using namespace std;
class Heap{
    public:
    int* arr;
    int capacity;
    int index;
    Heap(int n){
       capacity=n;
       arr=new int[capacity];
       index=0;
    //    jab bhi insert krna hai to index++ krke insert krna hai

    }
    void printHeap(){
        for(int i=1;i<=index;i++){
            cout<<arr[i]<<" ";

        }
    }
    void insert(int val){
        if(index==capacity-1){
            // hame 1 based indexing krni hai
            cout<<"jagah nahi bachi hai bhai"<<endl;
        }
        index++;
        arr[index]=val;
        // ab hame inserted value ko uske parent se compare karwana hai
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                arr[parent]=arr[index];
                arr[index]=arr[parent];
                index=parent;
            }
            else{
                break;
                // matlb parent ki value already badi hai 
            }
        }
 
    }
    void deleteFromHeap(){

    }

};
int main(){
    Heap h(3);
    h.insert(10);
    h.insert(20);
    // h.insert(35);
    // h.insert(25);
    // h.insert(15);
    h.printHeap();
    return 0;
}

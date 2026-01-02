#include<iostream>
#include<algorithm>
using namespace std;
// if string is passed without reference it will create a copy of the string
void printPermutation(string str,int i){
    if(i>=str.length()){
        cout<<str<<endl;
        return;
    }
    int j=i;
    while(j<str.length()){
        swap(str[i],str[j++]);
        printPermutation(str,i+1);
    }
    
}

// if string is passed with refrence
// void printPermutation(string &str,int i){
//         if(i>=str.length()){
//             cout<<str<<endl;
//             return;
//         }
        
//         for(int j=i;j<str.length();j++){
            
        
//             swap(str[i],str[j++]);
//             printPermutation(str,i+1);
//             // backtrack
//             swap(str[i],str[j]);
//         }
        
//     }
int main(){
    string str="abc";
    printPermutation(str,0);
    return 0;
}
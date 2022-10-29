#include<iostream>
using namespace std;
bool binarySearch(int arr[], int x, int low, int high){
    if(low > high) return false;
    else{
        int mid=(low+high)/2;
        if(arr[mid]==x) return true;
        else if( arr[mid]<x) return binarySearch(arr, x, mid + 1, high);
        else if(arr[mid]>x) return binarySearch(arr, x, low, mid-1);
    }
    return false;
   

}
    
int main(){
    int n,x;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>x;
    if(binarySearch(a,x,0,n-1)) cout<<"Yes";
    else cout<<"No";


}
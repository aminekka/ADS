#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n,f;
vector<int> v;
int ok(int mid,int n){
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        cnt += ceil((double)v[i]/mid);
    }
    return cnt;
}
int main(){
    cin >> n >> f;
    int x;
    int max = 0;
    for(int i = 0 ;i < n ; i++){
        cin >>x;
        v.push_back(x);
        if(max<x){
            max=x;
        }
    }
    int l=1;
    int r=max;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(ok(mid,n)>f){
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
}
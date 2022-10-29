#include<iostream>
#include<algorithm>
using namespace std;

int n,a[10000],p;
int binsearch(int e){
    int l=0,r=n-1;
    while(l<=r) {
        int m = l+(r-l)/2;
        if(a[m] <= e) {
            l = m + 1;
        }
        else r = m - 1;
    }
    return l;


}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    cin>>p;
    while(p--){
        int e;cin>>e;
        int ans=binsearch(e);
        int sum=0;
        for(int i=0;i<ans;i++){
            sum+=a[i];
        }
        cout<<ans<<" "<<sum<<endl;

    }
}
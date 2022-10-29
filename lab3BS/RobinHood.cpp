#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int n,h;
vector<int> v;
int robin(int h,int l, int r){
    set<long long > s;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        int cnt=0;
        for(int i=0;i<v.size();i++){
            if(v[i]%mid!=0){
                cnt+=v[i]/mid+1;
            }
            else{
                cnt+=v[i]/mid;
            }
        }
        if(cnt<=h){
            s.insert(mid);
        }

        if(cnt>h) l=mid+1;
        else r=mid-1;

    }
    if(!s.empty()){
        return *s.begin();
    }
    return -1;
}
int main(){
    cin>>n>>h;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    float max=v[v.size()-1];
    cout<<robin(h,0,max);

}
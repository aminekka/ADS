#include <bits/stdc++.h>
using namespace std;
int binarySearch(int* a, int l, int r, int tt){
    while(l <= r){
        int m = (l+r)/2;
        if(a[m-1] < tt && tt <= a[m]){
            return m;
        }else if(a[m] < tt){
            l = m + 1;
        }else{
            r = m - 1;
        }

    }
    return -1;

}
int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int pr[n + 1];
    pr[0] = 0;
    for(int i = 1; i < n + 1; i++){
        pr[i] = pr[i-1] + a[i-1];
    }
    while(m--){
        int tt;
        cin >> tt;
        cout << binarySearch(pr, 0, n+1, tt) << endl;
    }
    return 0;
}
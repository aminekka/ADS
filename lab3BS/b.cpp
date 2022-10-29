#include <bits.stdc++.h>
using namespace std;

bool check(int arr[], int n, int mid, int k){
    int cnt;
    long long sum = 0;

    for (int i = 0; i < n; i++){
        sum += arr[i];
        if (sum > mid) sum = arr[i], cnt++;

    }
    return cnt < k;


}

int main(){
    int n, k, mx = 0, ans;
    long long sum = 0;

    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (mx < arr[i]) mx = arr[i];
        sum += arr[i];

    }

    int left = mx;
    long long right = sum, mid;

    while (left<= right){
        mid = (left+right)/2;
        if (check(arr, n, mid, k)) right = mid-1, ans = mid;
        else left = mid +1;
        // cout << "[" << left << ", " << right << "]\n";
        cout << ans;

    }



}
#include <bits/stdc++.h>
using namespace std;

int binSearch1(int n, int arr[], int tar, int l, int r){
    int mid = (l + r) / 2;
    if(l > r) return -1;
    if(arr[mid] == tar) return mid;
    else if(arr[mid] > tar) return binSearch1(n, arr, tar, l, mid - 1);
    return binSearch1(n, arr, tar, mid + 1, r);
}

int binSearch2(int n, int arr[], int tar, int l, int r){
    int mid = (l + r) / 2;
    if(l > r) return -1;
    if(arr[mid] == tar) return mid;
    else if(arr[mid] > tar) return binSearch2(n, arr, tar, mid + 1, r);
    return binSearch2(n, arr, tar, l, mid - 1);
}

int main(){
    int t; cin >> t;
    int arr[t], flag;
    for(int i = 0; i < t; i++) cin >> arr[i];

    int n, m; cin >> n >> m;
    int snake[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> snake[i][j];
        }
    }

    bool found;
    for(int num : arr){
        found = 0;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) flag = binSearch2(m, snake[i], num, 0, m - 1);
            else flag = binSearch1(m, snake[i], num, 0, m - 1);

            if(flag != -1){
                cout << i << " " << flag << "\n";
                found = 1;
                break;
            }
        }
        if(!found) cout << -1 << '\n';
    }
}
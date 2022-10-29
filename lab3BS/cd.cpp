#include <iostream>
#include <algorithms>
using namespace std;

int BinarySearch()

int check(int left, int right, int arr[], int n){
    int pos;
    for (int i = left; i < right; i++){
        pos = BinarySearch(i, arr, n);
        if(pos != -1){
            leftPos = pos;
            break;
        }
    }
    for (int i = right; i>= left; i--){
        pos = BinarySearch(i, arr, n);
        if(pos != -1){
            rightPos = pos;
            break;
        }
    }
    return rightPos - leftPos + 1;
    

}

int main(){
    int n, q; cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for (int i = 0; i < q; i++){
        int left1, left2, right1, right2, mid;
        cin >> left1 >> right1 >> left2 >> right2;
        for(int j)
    }
}
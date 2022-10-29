#include<iostream>
using namespace std;
int a[10000];
int snake[801][801];
int oddBinSearch(int l , int r, int x, int row ){
   if(l<=r){
        int mid = l + (r-l)/2;
        if(snake[row][mid] == x) return mid;
        else if(snake[row][mid] > x) return oddBinSearch(l,mid-1,x,row);
        return oddBinSearch(mid+1,r ,x, row);
    }
    return -1;
}
int evenBinSearch(int l , int r, int x, int row ){
    if(l<=r){
        int mid = l + (r-l)/2;
        if(snake[row][mid] == x) return mid;
        else if(snake[row][mid] < x) return evenBinSearch(l,mid-1,x,row);
        return evenBinSearch(mid+1,r ,x, row);
    }
    return -1;
}
pair <int,int> findSnake(int l,int x,int r){
    int ans;
    for(int i=0;i<l;i++){
        if(i%2==0){
            if(x <= snake[i][0] && x>= snake[i][r-1]){
                ans = evenBinSearch(0,r,x,i);
                if( ans  != -1){
                    return make_pair(i,ans);
                }
                else{
                    return make_pair(-1,-1);
                }
            }
            else if(i == l-1){
                return make_pair(-1,-1);
            }
        }
        if(i%2!=0){
            if(x<=snake[i][r-1] && x>= snake[i][0]){
                ans = oddBinSearch(0,r,x,i);
                if(ans != -1){
                    return make_pair(i,ans);
                }
                else{
                    return make_pair(-1,-1);
                }
            }
            else if(i == l-1){
                return make_pair(-1,-1);
            }
        }
    }
}

int main(){
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
int l,r; cin>>l>>r;
for(int i=0;i<l;i++){
    for(int j=0;j<r;j++){
        cin>>snake[i][j];
    }
}
 for(int i=0;i<n;i++){
        int x = a[i];
        pair <int,int> res = findSnake(l,x,r);
        if(res.first != -1){
            cout << res.first << " " << res.second << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;


int main(){
    int n ; cin >> n ;
    vector<int>p(n);
    for(int i = 0 ;i < n ; i++){
        int x ; cin >> x ;
        p[i]=  x;
    }
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i+1 ; j < n ; j++){
            if(p[i] > p[j]){
                swap(p[i] , p[j]);
            }
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;


// intiution behind merge sort is that a single element in the array is always sorted 
// so we are dividing the given array  untill we get the singel element and then mergeing the divided array in sorted order




void merge(int a[], int start , int mid , int end){
        int size1 = mid-start+1;
        int size2 = end-mid;
        // int mid = (start+end)/2;
        int *l1 = new int[size1];
        int *l2 = new int[size2];
        for(int i = 0 ; i < size1 ; i++){
            l1[i] = a[i+start];
        }
        for(int i = 0 ; i < size2 ; i++){
            l2[i] = a[i+mid+1];
        }
        int i = 0 , j = 0 ;
        int p = start ;
        while(i < size1 && j < size2){
            if(l1[i] <= l2[j]){
               a[p++] = l1[i++];
            }
            else {
                a[p++] = l2[j++];
            }
            // else {
            //     farr[p++] = l1[i++];
            //     farr[p++] = l2[j++];
            // }
        }
        while(i < size1){
            a[p++] = l1[i++];
        }
        while(j < size2){
            a[p++] = l2[j++];
        }
 delete[] l1;
 delete[] l2;
}

void mergef(int start , int end  , int a[]){
   
    if(start >= end){
        return ;
    }
     int mid = (start+end)/2;
    mergef(start , mid , a );
    mergef(mid+1  , end, a);
    merge(a , start , mid , end);

}



int main(){
    int n ; cin >> n ;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    mergef(0 , n-1 , a);
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }

}
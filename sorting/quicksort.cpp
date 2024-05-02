#include <bits/stdc++.h>
using namespace std;


// sorting by taking first element as pivot element
// traverse the array from high to low compare every element with pivot element if it greater than pivot element store it from end 
// and move a[low] to its correct position
// return the index as it will be pivot element 
// separately sort low to index-1 and from index+1 to end            done with quick sort 


int partition(int a[], int low  , int high){
    int pivot = a[low];
        int k = high;
        
        for(int i = high ; i > low ; i--){
            if(a[i] > pivot){
                swap(a[i], a[k--]);
            }
        }
        swap(a[low] , a[k]);
        return k;
}

void quicksort(int a[], int low , int high){
    if(low < high){
        int index = partition(a , low , high);
        quicksort(a , low , index-1);
        quicksort(a , index+1 , high);
    }
}


int main(){
    int n ; cin >> n ;
    int a[n];
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    quicksort(a , 0 , n-1);
    for(int i = 0 ; i < n ; i++){
        cout << a[i] << " ";
    }
 

}




#include <iostream>
#include <algorithm>
using namespace std;

void quick_sort(int ara[],int left, int right){
    int i=left;
    int j=right;
    int pivot=ara[(left+right)/2];

    while(i<=j){
        while(ara[i]<pivot) i++;
        while(ara[j]>pivot) j--;
        if(i<=j) {
            swap(ara[i],ara[j]);
            i++;
            j--;
        }
    }
    if(left<j) quick_sort(ara,left,j);
    if(i<right) quick_sort(ara,i,right);
    
}

int main()
{
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++) cin>>ara[i];
    quick_sort(ara,0,n-1);
    for(int i=0;i<n;i++) cout<<ara[i]<<" ";
}
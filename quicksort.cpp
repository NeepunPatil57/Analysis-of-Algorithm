#include<iostream>
#include<algorithm>
using namespace std;
int partition(int *arr,int low,int high){
    int pivot=arr[high];
    int i=(low-1);
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);
}
void quickSort(int *arr,int low,int high){
    if(low<high){
        int pi;
        pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
void print(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={5,2,3,1,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    print(arr,n);
}

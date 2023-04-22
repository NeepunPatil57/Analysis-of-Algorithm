#include<stdio.h>
struct pair{
    int min;
    int max;
};
struct pair getMaxMin(int *arr, int low,int high){
    struct pair minmax,mml,mmr;
    int mid;
    if(low==high){
        minmax.min =arr[low];
        minmax.max =arr[low];
        return minmax;
    }

    if(high==low+1){
        if(arr[low]>arr[high]){
            minmax.max=arr[low];
            minmax.min =arr[high];
        }
        else{
            minmax.max=arr[high];
            minmax.min=arr[low];
        }
        return minmax;
    }
    mid=(low+high)/2;
    mml=getMaxMin(arr,low,mid);
    mmr=getMaxMin(arr,mid+1,high);
    //compare minimum of mml and mmr
    if(mml.min<mmr.min){
        minmax.min=mml.min;
    }
    else{
        minmax.min=mmr.min;
    }
    //compare maximum of mml and mmr
    if(mml.max>mmr.max){
        minmax.max=mml.max;
    }
    else{
        minmax.max=mmr.max;
    }
    return minmax;
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    struct pair minmax = getMaxMin(arr,0,n-1);
    printf("Minimum is %d\n",minmax.min);
    printf("Maximum is %d\n",minmax.max);
    return 0;
}
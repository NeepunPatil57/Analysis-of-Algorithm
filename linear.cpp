#include<iostream>
using namespace std;
int linear_search(int *arr,int n,int x){
    if(n>=0){
        if(arr[n]==x){
            return n;
        }
        return linear_search(arr,n-1,x);
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7},x,ans;
    cin>>x;
    int n=sizeof(arr)/sizeof(arr[0]);
    ans=linear_search(arr,n,x);
    (ans==-1)?cout<<"element not present in array":cout<<"element present in array at index "<<ans<<endl;
    return 0;
}

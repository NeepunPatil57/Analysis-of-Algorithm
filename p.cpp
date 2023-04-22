#include<iostream>
#define INF 999999
using namespace std;
void prim(int cost [10][10],int n){
    int visited[10]={0},no_e=1,min_cost=0;
    int min ,a,b;

    visited[1]=1;
    while(no_e<n){
        min=INF;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(cost[i][j]<min){
                    if(visited[i]!=0){
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            
            }
        }
        if(visited[b]==0){
            cout<<"cost from "<<a<<" to"<<b<<" is"<<min<<endl;
            min_cost+=min;
            no_e++;
        }

        if(visited[b]=1){
            cost[a][b]=cost[b][a]=INF;
        }

    }
    cout<<"The Minimum cost is"<<min_cost <<endl;
}
int main(){
    int n,cost[10][10];
    cout<<"\nEnter Nunber of nodes"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>cost[i][j];
            if(cost[i][j]==0){
                cost[i][j]=INF;
            }
        }
    }
    prim(cost,n);
    
    
    return 0;
}
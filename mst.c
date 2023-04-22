#include<stdio.h>
# define INF 999999
void prim_mst(int cost[10][10],int n){
    int visited[10]={0},no_e=1,min_cost=0;
    int min, a,b;
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
            printf("\nMini cost from %d to %d is %d",a,b,min);
            min_cost+=min;
            no_e++;
        }

        visited[b]=1;
        cost[a][b]=cost[b][a]=INF;
    }
    printf("\ntotal cost is %d",min_cost);
}
int main(){
   int cost[10][10];
   int n;
   printf("\nEnter the number of nodes");
   scanf("%d",&n);
   printf("Enter the cost in form of adjacency matrix\n");
   for(int i=1; i<=n; i++){
       for(int j=1; j<=n; j++){
           scanf("%d",&cost[i][j]);
           if(cost[i][j]==0){
               cost[i][j] =INF;
           }
       }
   }

   prim_mst(cost,n);

    return 0;
}
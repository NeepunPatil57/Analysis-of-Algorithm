#include<stdio.h>
#define INF 999999
void print(int adj_mat[10][10], int n){
    printf("\n\n");
    for(int i=0; i<n;i++){
        for(int j=0; j< n; j++){
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }
}
void floydWarshall(int adj_mat[10][10], int n){
    for(int i=0; i<n;i++){
        for(int j=0; j< n; j++){
            for(int k=0; k < n; k++){
                if(adj_mat[k][j]>adj_mat[k][i]+adj_mat[i][j]){
                    adj_mat[k][j] = adj_mat[k][i] + adj_mat[i][j];
                }
            }
        }
    }
    print(adj_mat,n);
}
int main(){
    int adj_mat[10][10];
    int n;
    printf("Enter Number of vertices: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj_mat[i][j]);
            if(i!=j && adj_mat[i][j]==0){
                adj_mat[i][j]=INF;
            }

        }
    }
    floydWarshall(adj_mat, n);
}
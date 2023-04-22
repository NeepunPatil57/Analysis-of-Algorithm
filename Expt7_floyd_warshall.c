#include<stdio.h>
#include<stdlib.h>

#define INF 999999

void printSolution(int ad_mat[10][10], int n)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf ("%d ", ad_mat[i][j]);
		}
		printf("\n");
	}
}

void floydWarshall (int ad_mat[10][10], int n){

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			for (int k = 0; k < n; k++){
				if (ad_mat[k][j] > ad_mat[k][i] + ad_mat[i][j]){
					ad_mat[k][j] = ad_mat[k][i] + ad_mat[i][j];
				}
			}
		}
	}

	printSolution(ad_mat, n);
}

int main(){

	int ad_mat[10][10];
	int n;
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
    printf("Etner cost in form of adjacency matrix: \n");
    for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &ad_mat[i][j]);
			if(i != j && ad_mat[i][j] == 0)
				ad_mat[i][j] = INF;
		}
	}

    printf("\nShortest path matrix using Floyd Warshall's algorithm is: \n");
    floydWarshall(ad_mat, n);
	return 0;
}
#include <stdio.h>
#include<stdlib.h>
struct items{
    char name[20];
    float weight;
    float profit;
    float fraction;
    float ratio; 
};
void knapsack(int n,struct items *object,float capacity){
    unsigned int i;
    float total_profit=0;
    for(i=0;i<n;i++){
        if(object[i].weight>capacity){
            break;
        }
        else{
            object[i].fraction=1.0;
            total_profit+=object[i].profit;
            capacity -= object[i].weight;
        }
    }
    if(i<n){
        object[i].fraction =(capacity/object[i].weight);
    }
    total_profit+=object[i].fraction*object[i].profit;
    printf("Total profit is %.2f",total_profit);
    printf("-------------------%% of per item--------------------");
    for(int i=0; i<n; i++){
        if(i==n-1){
            printf("%s (%.2f%%).\n",object[i].name, object[i].fraction*100);
        }
        else{
            printf("%s (%.2f%%)-->",object[i].name, object[i].fraction*100);
        }
    }
}
int main(){
    unsigned int n;
    float capacity;
    printf("Enter Capacity of bag :");
    scanf("%f",&capacity);
    printf("\nEnter No of items in bag :");
    scanf("%d",&n);
    struct items item[n];
    printf("\nEnter Item Details");
    for(unsigned int i=0; i<n; i++){
		printf("========== Item No %d ==========\n", i+1);
        printf("Item Name: ");
		scanf("%s",item[i].name);
		printf("Weight: ");
		scanf("%f",&item[i].weight);
		printf("Profit:  ");
		scanf("%f",&item[i].profit);
        //printf("\n");
	}

    for(unsigned int i=0; i<n; i++){
        item[i].ratio= item[i].profit / item[i].weight;
        item[i].fraction = 0.0;
    }

    for(unsigned int i=0; i<n; i++){
        for(unsigned int j=i+1; j<n; j++){
            if(item[i].ratio < item[j].ratio){
                struct items temp=item[i];
                item[i]=item[j];
                item[j]=temp;
            }
        }
    }

    // for(unsigned int i=0; i<n; i++){
    //     printf("%d ",item[i].ratio);
    // }
    knapsack(n,item, capacity);
}
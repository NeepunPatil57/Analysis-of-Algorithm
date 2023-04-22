#include <stdio.h>
#include <stdlib.h>

struct pair{
    int min, max;
};

struct pair getMaxMin(int Arr[], int low, int high){
    struct pair maxmin;
    if(low == high){
        maxmin.min = maxmin.max = Arr[low];
    }
    else if(low == high-1){
        if(Arr[low] < Arr[high]){
            maxmin.min = Arr[low];
            maxmin.max = Arr[high];
        }
        else{
            maxmin.min = Arr[high];
            maxmin.max = Arr[low];
        }
    }
    else{
        int mid = (low + high) / 2;
        struct pair Left  = getMaxMin(Arr, low, mid);
        struct pair Right = getMaxMin(Arr, mid+1, high);

        if(Left.max > Right.max){
            maxmin.max = Left.max;
        }
        else{
            maxmin.max = Right.max;
        }
        if(Left.min < Right.min){
            maxmin.min = Left.min;
        }
        else{
            maxmin.min = Right.min;
        }
    }
    return maxmin;
}

int main(){
    int size, *Arr;
    size:
        printf("Enter size of array: ");
        scanf("%d", &size);
        if(size < 1){
            printf("Error: Size of array cannot be less than 1!\n");
            goto size;
        }
        Arr = (int *) malloc(size * sizeof(int));
        printf("Enter element of array: ");
        for(int i=0; i < size; i++)
            scanf("%d", &Arr[i]);
    printf("\n");
    struct pair maxmin = getMaxMin(Arr, 0, size-1);
    printf("Minimum element is %d\n", maxmin.min);
    printf("Maximum element is %d\n", maxmin.max);
}


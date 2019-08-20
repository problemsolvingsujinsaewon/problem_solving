#include <iostream>

void merge_sort(int start, int end);
void merge(int start, int end, int mid);

int length;
int* number = NULL;
int* number_sorted = NULL;

int main(void){
    //get input
    scanf("%d", &length);
    number_sorted = (int*)malloc(sizeof(int)*length);
    number = (int*)malloc(sizeof(int)*length);
    for(int i=0; i<length; i++){
        scanf("%d", &number[i]);
    }
    
    //merge sort
    merge_sort(0, length-1);

    //print
    // for(int i=0; i<length; i++){
    //   printf("%d\n", number_sorted[i]);
    // }
}

void merge_sort(int start_idx, int end_idx){
    int start = start_idx;//0
    int end = end_idx;//2
    while(start < end){
        int mid = (end-start)/2; //1 0
        merge_sort(start, mid);//0,1  0,0
        merge_sort(mid+1, end);//2,2  1,1
        merge(start, end, mid);//0,1,0
    }
}

void merge(int start, int end, int mid){
    int idx_sorted=start; //0
    while(start<mid+1 && mid<end){
        while(number[start] < number[end] && start<mid+1){
            number_sorted[idx_sorted]=number[start];
            idx_sorted++;
            start++;
        }
        while(number[start] > number[end] && mid<end){
            number_sorted[idx_sorted]=number[end];
            idx_sorted++;
            end--;
        }
    }

    if(start<mid+1){
        while(start>mid+1){
            number_sorted[idx_sorted]=number[start];
            idx_sorted++;
            start++;
        }
    }

    else if(mid<end){
        while(end<mid){
            number_sorted[idx_sorted]=number[end];
            idx_sorted++;
            end--;
        }
    }

    for(int i=0; i<length; i++){
      printf("%d\n", number[i]);
    }
    printf("sorted\n");

    for(int i=0; i<length; i++){
      printf("%d\n", number_sorted[i]);
    }
    printf("\n\n");
}

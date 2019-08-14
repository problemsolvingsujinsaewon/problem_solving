#include <iostream>

int main(){
    int num[1000];
    int length;
    //get array length and number
    scanf("%d", &length);
    for(int i=0; i<length; i++)
        scanf("%d", &num[i]);
    
    //insertion sort
    for(int i=1; i<length; i++){
        int sorting_num = num[i];
        int j = i-1;
        while(sorting_num < num[j] && j > -1){
            num[j+1]=num[j];
            j--;
        }
        num[j+1]=sorting_num;
    }
    
    //print in ascending order
    for(int i=0; i<length; i++)
        printf("%d\n", num[i]);
}

//틀린 이유 : 적절한 위치를 찾고 선택된 number를 넣을 때, sorting_num이 아니라 num[i]로 줘버림.

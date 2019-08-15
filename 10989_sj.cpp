#include <iostream>

int max=0;
int length;
int count[100001] = {0,};

int main(){
    //get input
    scanf("%d", &length);
    for(int i=0; i<length; i++){
        int count_idx;
        scanf("%d",&count_idx);
        count[count_idx]++;
        if(max<count_idx)
          max = count_idx;
    }
    //count sort
    for(int i=1; i<max+1; i++){
        count[i] = count[i-1]+count[i];
    }

    //print
    for(int i=1; i<max+1; i++){
        int print_num = count[i] - count[i-1];
        for(int j=0; j<print_num; j++)
            printf("%d\n", i);
    }
    return 0;
}
//틀린이유 : 기존 counting sort는 extra memory가 필요했지만, print만 하는 경우에는 extra memory가 필요하지 않았다.
//또 정해진 count_araay size <= 10,000, input_array size <= 10,000,000 이기 때문에 count_array를 사용하는 것이 더 적은 메모리가 든다.
//처음으로 기존 배웠던 sorting algorithm을 적용해본 느낌

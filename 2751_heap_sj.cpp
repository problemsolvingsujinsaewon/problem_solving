#include <iostream>

int length;
int* number = NULL;
int* heap = NULL;
int heap_count=0;

void push(int i);
int pop(int i);

int main(void){
    //get input
    scanf("%d", &length);
    heap = (int*)calloc(0, (length+1)*sizeof(int));
    number = (int*)malloc(sizeof(int)*(length+1));
    for(int i=1; i<length+1; i++){
        scanf("%d", &number[i]);
    }
    
    //pop
    for(int i=1; i<length; i++){
      int tmp = pop(i);
      printf("%d\n", tmp);
    } 
}

void heap_sort(void){
  //push
  for(int i=1; i<length+1; i++){
    push(i);
  }
}


int get_child_idx(int i){
 int child_idx = i*2;
}

int get_parent_idx(int i){
  int parent_idx = i/2;
}

int swap(int* swp1, int* swp2){
  int tmp = *swp1;
  *swp1 = *swp2;
  *swp2 = tmp;
}

void push(int i){
  int new_num = number[i];
  heap[++heap_count] = new_num;
  int current_idx = i;
  int parent_idx = get_parent_idx(i);
  while(parent_idx>0 && heap[parent_idx] > new_num){
    swap(&heap[parent_idx], &number[current_idx]);
    current_idx = parent_idx;
    parent_idx = get_parent_idx(current_idx);
  }
}

int pop(int i){
  int pop_num = heap[0];
  heap[0] = heap[heap_count--];
  int current_idx = 1;
  int child_idx = get_child_idx(current_idx);
  while(child_idx <= heap_count && heap[child_idx] < heap[current_idx]){
    swap(&heap[child_idx], &number[current_idx]);
    current_idx = child_idx;
    child_idx = get_parent_idx(current_idx);
  }
  return pop_num;
}

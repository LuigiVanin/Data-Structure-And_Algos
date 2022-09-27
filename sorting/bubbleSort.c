
void bubble_sort(int *v, int len) {
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(v[j] > v[j+1]) swap(v, j, j+1);
        }
    }
}

void swap(int* v, int i, int j){
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
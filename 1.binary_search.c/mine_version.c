#include <stdio.h>
int binary(int list[], int *, int);

int main(){
    int list[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int search = 0;
    int high = sizeof(list)/sizeof(list[0]);
    int x = binary(list, &search, high);
    printf("Индекс введенного числа %d = %d\n", search, x);
    return 0;
}

int binary(int list[], int *search, int high){
    int low = 0;
    int mid = 0;
    scanf("%d", &*search);
    while(low <= high){
        mid = (low + high)/2;
        int item = list[mid];
        if (*search > item){
            low = mid + 1;
        }

        else if (*search < item){
            high = mid - 1;
        }

        else if (*search == item)
            return mid;
    }
    return -1;

}
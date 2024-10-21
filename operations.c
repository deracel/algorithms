#include <stdio.h>
#include <stdlib.h>

void filling(int* arr, int n);
int search(int* arr, int* selected, int n);
int insert(int* arr, int ind_insert, int numb_insert, int n);
void delete(int* arr, int n, int ind_delete);


int main(){
    int* arr;
    int n = 0, selected = 0;
    printf("Задайте длину массива: ");
    scanf("%d", &n);
    arr = (int* )malloc(n * sizeof(int));
    filling(arr, n);//filling our array with random numbers
    //search
    printf("Выбертье число для поиска: ");
    scanf("%d", &selected);
    int s = search(arr, &selected, n);
    printf("index of searched number = %d, searched number = %d\n", s, selected);
    printf("\n");
    //insert
    int ind_insert;
    int numb_insert;
    printf("Выберите индекс массива для вставки от 0 до %d: ", n);
    scanf("%d", &ind_insert);
    printf("Напишите число, которое хотите вставить в массив: ");
    scanf("%d", &numb_insert);
    int status = insert(arr, ind_insert, numb_insert, n);
    printf("status ---- %d\n", status);
    for (int i = 0; i < n + 1; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");
    //delete
    int ind_delete;
    printf("Выберите индекс массива для удаления от 0 до %d: ", n + 1);
    scanf("%d", &ind_delete);
    delete(arr, n, ind_delete);
    
    free(arr);
    return 0;
}
void filling(int* arr, int n){
    for (int i = 0; i < n; ++i){
        arr[i] = arr[i - 1] + rand() % 100;
    }
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search (int* arr, int* selected, int n){
    int low = 0;
    int high = n;
    int mid;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] < *selected){
            low = mid + 1;
        }
        else if(arr[mid] > *selected){
            high = mid - 1;
        }
        else if(arr[mid] == *selected){
            return mid;
        }
    }
    return -1;//searched number does not exist
}

int insert(int* arr, int ind_insert, int numb_insert, int n){
    if(ind_insert < 0){
        return -1;
    }
    if(ind_insert > n - 1){
        ind_insert = n;
    }
    int i = n - 1;
    while (i >= ind_insert){
        arr[i + 1] = arr[i];
        i = i - 1;
    }
    arr[i + 1] = numb_insert;
    return 0;
}

void delete(int* arr, int n, int ind_delete){
    if (0 <= ind_delete < n){
        int i = ind_delete;
        while (i < n){
            arr[i] = arr[i + 1];
            i = i + 1;
        }
    }
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
} 
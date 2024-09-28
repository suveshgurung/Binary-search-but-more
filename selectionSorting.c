#include <stdio.h>
#include "macros.h"

#define MAX_SIZE 100

void sort(int *arr, int s); 

int main() {
    int i, n;

    printf("Enter the number of elements of the array to generate: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        fprintf(stderr, "Ivalid value of n\n");
        exit(EXIT_FAILURE);
    }

    int *arr = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, n);
    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    FILE *fp = fopen("sorted_array.txt", "w+");
    if (fp == NULL) {
        perror("fopen\n");
        exit(EXIT_FAILURE);
    }

    char *buf = (char *)malloc((n * 3) + (n));
    char *p = buf;
    int len, totalLen = 0;

    for (i = 0; i < n; i++) {
        len = snprintf(p, (n * 3 + n) - totalLen, "%d ", arr[i]);
        p += len;
        totalLen += len;
    }
    *p = '\n';
    fwrite(buf, totalLen, 1, fp);

    free(buf);
    fclose(fp);

    return EXIT_SUCCESS;
}

void sort(int *arr, int s) {
    int i, j, min, temp;

    for (i = 0; i < s - 1; i++) {
        min = i;
        for (j = i + 1; j < s; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        SWAP(arr[i], arr[min], temp);
    }
}

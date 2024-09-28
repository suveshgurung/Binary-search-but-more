#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "macros.h"

int binSearch(int *arr, int searchNum, int size);

int main() {

    FILE *fp = fopen("sorted_array.txt", "r");
    if (fp == NULL) {
        perror("fopen\n");
        exit(EXIT_FAILURE);
    }
    
    char *buf = NULL;
    char *eachNum = NULL;
    char *tempNum = NULL;
    size_t lineCap;

    getline(&buf, &lineCap, fp);

    int i = 0, j = 0, numCount = 0;
    int *arr = NULL;

    while (buf[i] != '\0') {
        if (buf[i] != ' ') {
            eachNum = (char *)realloc(eachNum, i + 1);
            eachNum[i] = buf[i];
            j++;
        } else {
            tempNum = &eachNum[i - j];
            j = 0;

            numCount++;

            arr = (int *)realloc(arr, sizeof(int) * numCount);
            arr[numCount - 1] = atoi(tempNum);
        }

        i++;
    }

    int searchNum;
    printf("Enter the number you want to see the position of: ");
    scanf("%d", &searchNum);

    int searchPos = binSearch(arr, searchNum, numCount);
    if (searchPos == -1) {
        fprintf(stderr, "The number %d does not exists.\n", searchNum);
        exit(EXIT_FAILURE);
    }
    printf("The number %d is in the position %d.\n", searchNum, searchPos + 1);

    free(arr);
    free(eachNum);
    free(buf);
    fclose(fp);

    return EXIT_SUCCESS;
}

int binSearch(int *arr, int searchNum, int size) {
    int left = 0, right = size - 1, middle;
    
    while (left <= right) {
        middle = (left + right) / 2;
        switch (COMPARE(searchNum, arr[middle])) {
            case -1:
                right = middle - 1;
                break;
            case 1:
                left = middle + 1;
                break;
            case 0:
                return middle;
                break;
        }
    }

    return -1;
}

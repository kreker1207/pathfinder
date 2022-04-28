#include "pathf.h"

void sum_check(int **arr, int size) {
    double temp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp += arr[i][j];
            if(temp > 2147483647) {
                mx_printerr("error: sum of bridges lengths is too big\n");
                exit(0);
            }
        }
    }
}


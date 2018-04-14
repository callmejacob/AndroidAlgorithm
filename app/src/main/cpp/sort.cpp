//
// Created by Jacob on 2018/4/14.
//

#include "common.h"

#define N 10
static int s_array[N] = {0};

/**
 * 冒泡排序
 * @param array 数组
 * @param len   数组长度
 */
static void bubble(int array[], int len) {
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/**
 * 选择排序
 * @param array 数组
 * @param len   数组长度
 */
static void select(int array[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

/**
 * 插入排序
 * @param array 数组
 * @param len   数组长度
 */
static void insert(int array[], int len) {
    for (int i = 1; i < len; i++) {
        int val = array[i];
        int j = i;
        while (j > 0 && val < array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = val;
    }
}

/**
 * 快速排序
 * @param array 数组
 * @param len   数组长度
 */
static void quick(int array[], int len) {
    if (len <= 1) {
        return;
    }

    int key = 0;
    int l = 0;
    int r = len - 1;
    while (l < r) {
        while (r > l) {
            if (array[r] < array[key]) {
                break;
            }
            r--;
        }

        while (l < r) {
            if (array[l] > array[key]) {
                break;
            }
            l++;
        }

        if (l != r) {
            int temp = array[l];
            array[l] = array[r];
            array[r] = temp;
        }
    }

    if (l != key) {
        int temp = array[key];
        array[key] = array[l];
        array[l] = temp;
    }

    quick(array, l);
    quick(array + l + 1, len - l - 1);
}

/**
 * 堆排序
 * @param array 数组
 * @param len   数组大小
 */
static void heap(int array[], int len) {
    int count = 0;

    // 建堆（大顶）
    for (int i = len / 2 - 1; i >= 0; i--) {
        int maxIndex = i;
        if (2 * i + 1 < len && array[2 * i + 1] > array[maxIndex]) {
            maxIndex = 2 * i + 1;
        }
        if (2 * i + 2 < len && array[2 * i + 2] > array[maxIndex]) {
            maxIndex = 2 * i + 2;
        }
        if (maxIndex != i) {
            int temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;

            // 依次调整
            int k = maxIndex;
            while (k < len) {
                int maxIndex = k;
                if (2 * k + 1 < len && array[2 * k + 1] > array[maxIndex]) {
                    maxIndex = 2 * k + 1;
                }
                if (2 * k + 2 < len && array[2 * k + 2] > array[maxIndex]) {
                    maxIndex = 2 * k + 2;
                }

                if (maxIndex == k) {
                    break;
                } else {
                    int temp = array[k];
                    array[k] = array[maxIndex];
                    array[maxIndex] = temp;
                    k = maxIndex;
                }

                count++;
            }

        }

        count++;
    }

    // 交换根节点和调整
    while (len > 0) {
        // 交换掉根节点
        int temp = array[0];
        array[0] = array[len - 1];
        array[len - 1] = temp;

        // 减少总节点大小
        len--;

        // 依次调整
        int k = 0;
        while (k < len) {
            int maxIndex = k;
            if (2 * k + 1 < len && array[2 * k + 1] > array[maxIndex]) {
                maxIndex = 2 * k + 1;
            }
            if (2 * k + 2 < len && array[2 * k + 2] > array[maxIndex]) {
                maxIndex = 2 * k + 2;
            }

            if (maxIndex == k) {
                break;
            } else {
                int temp = array[k];
                array[k] = array[maxIndex];
                array[maxIndex] = temp;
                k = maxIndex;
            }

            count++;
        }

    }

    LOGI("compute count: %d", count);
}

void sort(int type) {
    LOGI("========================================");
    LOGI("sort type: %d", type);

    // 初始化原始数组
    for (int i = 0; i < N; i++) {
        s_array[i] = N - i;
    }

    // 打印数组
    for (int i = 0; i < N; i++) {
        LOGI("%d", s_array[i]);
    }

    // 排序
    switch (type) {
        case SORT_TYPE_BUBBLE:
            bubble(s_array, N);
            break;
        case SORT_TYPE_SELECT:
            select(s_array, N);
            break;
        case SORT_TYPE_INSERT:
            insert(s_array, N);
            break;
        case SORT_TYPE_QUICK:
            quick(s_array, N);
            break;
        case SORT_TYPE_HEAP:
            heap(s_array, N);
            break;
        default:
            break;
    }

    // 打印数组
    LOGI("result:");
    for (int i = 0; i < N; i++) {
        LOGI("%d", s_array[i]);
    }

    LOGI("========================================");
}


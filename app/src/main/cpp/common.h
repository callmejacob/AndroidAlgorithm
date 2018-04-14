//
// Created by Jacob on 2018/4/14.
//

#ifndef ALGORITHM_COMMON_H
#define ALGORITHM_COMMON_H

#include <jni.h>
#include <string>
#include <math.h>

#include <Android/log.h>

#define TAG "algorithm" // 这个是自定义的LOG的标识
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型


/**
 * sort
 */
#define SORT_TYPE_BUBBLE 1
#define SORT_TYPE_SELECT 2
#define SORT_TYPE_INSERT 3
#define SORT_TYPE_QUICK 4
#define SORT_TYPE_HEAP 5

extern void sort(int type);


#endif //ALGORITHM_COMMON_H

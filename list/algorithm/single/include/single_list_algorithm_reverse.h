#ifndef _SINGLE_LIST_ALGORITHM_OVERTURN_H_
#define _SINGLE_LIST_ALGORITHM_OVERTURN_H_

#include "single_list_data.h"

#define LOG(fmt, ...) printf("%s-%d: "fmt, __func__, __LINE__, ##__VA_ARGS__)

list_head * init_list(int num);

#endif
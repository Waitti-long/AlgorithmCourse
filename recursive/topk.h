//
// Created by Waitti on 2020/5/20.
//

#ifndef ALGORITHMCOURSE_TOPK_H
#define ALGORITHMCOURSE_TOPK_H

#include <bits/stdc++.h>

/*
 * use func to choose use which select_func
 * func == 0 : select 0
 * func == 1 : select random
 * func == 2 : select mid
 * */
void select(int *a, int l, int r, int k, int func);

#endif //ALGORITHMCOURSE_TOPK_H

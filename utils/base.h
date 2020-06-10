#ifndef ALGORITHMCOURSE_BASE_H
#define ALGORITHMCOURSE_BASE_H

#include <bits/stdc++.h>

#define TIME(a, time_) {int t1 = now();a;int t2 = now(); time_ = t2 - t1;}
#define RAND_ARRAY(a) {for(auto &i:a)i = (rand()%2)?rand() % N:rand() % N * -1;}
#define PRINT_ARRAY(a) {for(auto &i:a)cout << i << ' ';cout << endl;}
long long now();



#endif //ALGORITHMCOURSE_BASE_H

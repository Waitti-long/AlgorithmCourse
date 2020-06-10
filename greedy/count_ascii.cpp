//
// Created by Waitti on 2020/6/4.
//

#include "count_ascii.h"

using namespace std;

void count_ascii_(const string& f){
    //重定向至文件 f
    freopen(f.c_str(), "r", stdin);
    int c, ascii[128];
    memset(ascii, 0, sizeof ascii);
    while ((c = getchar()) != EOF) {
        //如果所读字符在ascii范围内则其对应的ascii字符数加一
        if (c >= 0 && c < 128)ascii[c]++;
    }
    //输出
    for (int i = 0; i < 128; ++i) {
        cout << i << " " << char(i) << " " << ascii[i] << endl;
    }
}
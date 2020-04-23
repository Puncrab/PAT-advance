//
//  main.cpp
//  1002
//
//  Created by 李波 on 16/7/29.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int main() {
    double a[1004];
    memset(a, 0, sizeof(a));
    int k1,k2,exp;
    scanf("%d",&k1);
    double temp;
    while (k1--) {
        scanf("%d%lf",&exp,&temp);
        a[exp]=temp;
    }
    scanf("%d",&k2);
    while (k2--) {
        scanf("%d%lf",&exp,&temp);
        a[exp]+=temp;
    }
    int count=0;
    for (int i=0; i<1001; ++i) {
        if (a[i]!=0.0) {
            ++count;
        }
    }
    printf("%d",count);
    for (int i=1000; i>=0; --i) {
        if (a[i]==0.0) {
            continue;
        }else{
            printf(" %d %0.1lf",i,a[i]);
        }
    }
    return 0;
}

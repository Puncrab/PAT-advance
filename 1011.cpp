//
//  main.cpp
//  1011
//
//  Created by 李波 on 16/8/2.
//  Copyright © 2016年 李波. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int getMaxIndex(double *a)
{
    int index=0;
    if (a[1]>a[0]) {
        index=1;
    }
    return a[2]>a[index]? 2:index;
}

int main() {
    char s[3]={'W','T','L'};
    double a[3];
    double sum=1;
    int index;
    for (int i=0; i<3; ++i) {
        scanf("%lf%lf%lf",&a[0],&a[1],&a[2]);
        index=getMaxIndex(a);
        printf("%c ",s[index]);
        sum*=a[index];
    }
    sum=(sum*0.65-1)*2;
    printf("%0.2lf",sum);
    return 0;
}

//
//  main.cpp
//  1001
//
//  Created by 李波 on 16/7/29.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int a,b;
    cin>>a>>b;
    a=a+b;
    b=abs(a);
    if (a==0) {
        printf("0");
        return 0;
    }
    string s;
    int count=0;
    while (b) {
        if (count==3) {
            s.push_back(',');
            count=0;
            continue;
        }
        s.push_back(b%10+'0');
        ++count;
        b/=10;
    }
    if (a<0) {
        printf("-");
    }
    for (int i=(int)s.size()-1; i>=0; --i) {
        printf("%c",s[i]);
    }
    return 0;
}

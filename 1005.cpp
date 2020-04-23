//
//  main.cpp
//  1005
//
//  Created by 李波 on 16/8/1.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

char *s[10]={"zeo","one","two","three","four","five","six","seven","eight","nine"};

int main() {
    char c;
    int sum=0;
    while (c=getchar(),c!='\n') {
        sum+=c-'0';
    }
    vector<int> myVec;
    while (sum) {
        myVec.push_back(sum%10);
        sum/=10;
    }
    for (vector<int>::reverse_iterator rt=myVec.rbegin(); rt!=myVec.rend(); ++rt) {
        printf("%s",s[*rt]);
        if ((rt+1)!=myVec.rend()) {
            printf(" ");
        }
    }
    return 0;
}

//
//  main.cpp
//  1010
//
//  Created by 李波 on 16/8/1.
//  Copyright © 2016年 李波. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getSum(vector<int> &IntVec,int radix)
{
    int sum=0;
    for (const auto &w: IntVec) {
        sum=sum*radix+w;
    }
    return sum;
}

int max(int a,int b)
{
    return a>b? a:b;
}

int main() {
    vector<int> a[2];
    int radix,index;
    char c;
    while (c=getchar(),c!=' ') {
        if (c>='0'&&c<='9') {
            a[0].push_back(c-'0');
        }else if(c>='a'&&c<='z'){
            a[0].push_back(c-'a'+10);
        }
    }
    while (c=getchar(),c!=' ') {
        if (c>='0'&&c<='9') {
            a[1].push_back(c-'0');
        }else if(c>='a'&&c<='z'){
            a[1].push_back(c-'a'+10);
        }
    }
    scanf("%d%d",&index,&radix);
    int temp=getSum(a[index-1],radix);
    if (index==1) {
        index=2;
    }else{
        index=1;
    }
    int sum=0;
    for (int i=max((*max_element(a[index-1].begin(), a[index-1].end())+1),2); ; ++i) {
        sum=getSum(a[index-1],i);
        if (sum==temp) {
            printf("%d",i);
            break;
        }else if(sum>temp){
            printf("Impossible");
            break;
        }
    }
    return 0;
}
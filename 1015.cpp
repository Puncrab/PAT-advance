//
//  main.cpp
//  1015
//
//  Created by 李波 on 16/8/10.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n==0||n==1) {
        return false;
    }
    for (int i=2; i<=sqrt((double)n); ++i) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}

int reverse_prime(int n,int index)
{
    vector<int> myVec;
    while (n) {
        myVec.push_back(n%index);
        n=n/index;
    }
    int sum=0;
    for (vector<int>::iterator it=myVec.begin(); it!=myVec.end(); ++it) {
        sum=sum*index+*it;
    }
    return sum;
}

int main() {
    int n,index;
    while (scanf("%d",&n)!=EOF&&n>=0) {
        scanf("%d",&index);
        if (isPrime(n)&&isPrime(reverse_prime(n, index))) {
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

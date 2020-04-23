//
//  main.cpp
//  1009
//
//  Created by 李波 on 16/8/1.
//  Copyright © 2016年 李波. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int,double> A;
    int n,exp;
    scanf("%d",&n);
    while (n--) {
        scanf("%d",&exp);
        scanf("%lf",&A[exp]);
    }
    map<int,double> B;
    scanf("%d",&n);
    double temp;
    while (n--) {
        scanf("%d%lf",&exp,&temp);
        for (const auto &w:A)
        {
            B[exp+w.first]+=w.second*temp;
        }
    }
    int count=0;
    for (const auto &w:B)
    {
        if (w.second!=0.0) {
            ++count;
        }
    }
    printf("%d",count);
    for (map<int,double>::reverse_iterator rt=B.rbegin(); rt!=B.rend(); ++rt) {
        if (rt->second!=0.0) {
            printf(" %d %0.1lf",rt->first,rt->second);
        }
    }
    return 0;
}

//
//  main.cpp
//  1004
//
//  Created by 李波 on 16/7/29.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<vector<int>> edge;

void level_order()
{
    int  k,max=1;
    pair<int, int> n;
    vector<pair<int, int>> myvector;
    deque<pair<int, int>> mydeque;
    mydeque.push_back(pair<int, int>(0,1));
    while (mydeque.size()) {
        n=mydeque.front();
        if (n.second>max) {
            max=n.second;
        }
        myvector.push_back(n);
        k=(int)edge[n.first].size();
        for (int i=0; i<k; ++i) {
            mydeque.push_back(pair<int, int>(edge[n.first][i],n.second+1));
        }
        mydeque.pop_front();
    }
    int a[max];
    memset(a, 0, sizeof(a));
    for(auto &w:myvector)
    {
        if (edge[w.first].size()==0) {
            ++a[w.second-1];
        }
    }
    printf("%d",a[0]);
    for (int i=1; i<max; ++i) {
        printf(" %d",a[i]);
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    edge.clear();
    edge.resize(n);
    int a, k;
    while (m--)
    {
        scanf("%d%d", &a,&k);
        while (k--)
        {
            int b;
            scanf("%d",&b);
            edge[a-1].push_back(b-1);
        }
    }
    level_order();
    return 0;
}
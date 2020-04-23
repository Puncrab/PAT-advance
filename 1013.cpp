//
//  main.cpp
//  1013
//
//  Created by 李波 on 16/8/5.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

map<int,vector<int>> edges;

map<int,bool> visit;

void BFS(int first,int checked)
{
    if (!visit[first]&&first!=checked) {
        visit[first]=true;
        for (const auto &w:edges[first]) {
            BFS(w,checked);
        }
    }
}

int main() {
    int  N,M,K,a,b,checked,count=0;
    scanf("%d%d%d",&N,&M,&K);
    for (int i=1; i<=N; ++i) {
        edges[i].size();
    }
    for (int i=0; i<M; ++i) {
        scanf("%d%d",&a,&b);
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=0; i<K; ++i) {
        scanf("%d",&checked);
        count=0;
        for(const auto &w:visit)
        {
            visit[w.first]=false;
        }
        for(const auto &w:edges)
        {
            if (!visit[w.first]&&w.first!=checked) {
                BFS(w.first,checked);
                count++;
            }
        }
        if (count==0) {
            printf("%d\n",count);
        }else{
            printf("%d\n",count-1);
        }
    }
    return 0;
}
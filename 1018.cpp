//
//  main.cpp
//  1018
//
//  Created by 李波 on 16/8/15.
//  Copyright © 2016年 李波. All rights reserved.
//

#include <iostream>
#define n 501

int map[n][n];

bool visit[n]={0};

int capacity,N;

int cur_capacity[n];

int short_path[n];

typedef struct node{
    node()
    :shortpath(0xFFFFFFF),cur_bike(0){}
    int shortpath;
    int cur_bike;
}*pNode;
//DFS
void DFS(int start,int end,pNode p,int *a,int cur_path,int cur_bike,int length)
{
    a[length]=start;
    if (start==end) {
        if (cur_path<p->shortpath) {
            p->shortpath=cur_path;
            a[0]=length;
            for (int i=0; i<=length; ++i) {
                short_path[i]=a[i];
            }
        }else if(cur_path==p->shortpath){
            if (cur_bike>p->cur_bike) {
                a[0]=length;
                for (int i=0; i<=length; ++i) {
                    short_path[i]=a[i];
                }
            }
        }
    }
    if (cur_path>=p->shortpath) {
        return;
    }
    int bike;
    for (int i=0; i < N; ++i) {
        if (!visit[i]&&map[start][i]!=-1) {
            visit[i]=1;
            if (cur_capacity[i]>capacity/2) {
                bike=cur_capacity[i]-capacity/2;
            }else{
                bike=0;
            }
            DFS(i, end, p, a, cur_path+map[start][i], cur_bike+bike, length+1);
            visit[i]=0;
        }
    }
}

int main() {
    int end,M;
    scanf("%d%d%d%d",&capacity,&N,&end,&M);
    for (int i=1; i<=N; ++i) {
        scanf("%d",&cur_capacity[i]);
    }
    for (int i=0; i<N; ++i) {
        
    }
    return 0;
}

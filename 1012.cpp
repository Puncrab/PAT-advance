//
//  main.cpp
//  1012
//
//  Created by 李波 on 16/8/2.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int n;

char s[4]={'A','C','M','E'};

int flag=0;

typedef struct node
{
    int id;
    int C;
    int M;
    int E;
    double A;
    int rank[4];
}student,*pStudent;

void insert_rank(pStudent p,int index)
{
    p[0].rank[index]=1;
    for (int i=2; i<=n ; ++i) {
        switch (index) {
            case 0:
                if (p[i-1].A==p[i-2].A) {
                    p[i-1].rank[index]=p[i-2].rank[index];
                }else {
                    p[i-1].rank[index]=i;
                }
                break;
            case 1:
                if (p[i-1].C==p[i-2].C) {
                    p[i-1].rank[index]=p[i-2].rank[index];
                }else {
                    p[i-1].rank[index]=i;
                }
                break;
            case 2:
                if (p[i-1].M==p[i-2].M) {
                    p[i-1].rank[index]=p[i-2].rank[index];
                }else {
                    p[i-1].rank[index]=i;
                }
                break;
            case 3:
                if (p[i-1].E==p[i-2].E) {
                    p[i-1].rank[index]=p[i-2].rank[index];
                }else {
                    p[i-1].rank[index]=i;
                }
                break;
            default:
                break;
        }
    }
}

int compare(student a,student b)
{
    switch (flag) {
        case 0:
            return a.A>b.A;
            break;
        case 1:
            return a.C>b.C;
            break;
        case 2:
            return a.M>b.M;
            break;
        case 3:
            return a.E>b.E;
            break;
        default:
            break;
    }
    return 0;
}

int getBestRank(int *a)
{
    int best=99999;
    int index=0;
    for (int i=0; i<4; ++i) {
        if (a[i]<best) {
            best=a[i];
            index=i;
        }
    }
    return index;
}

int main() {
    int quires;
    scanf("%d%d",&n,&quires);
    student stu[n];
    int id;
    map<int,pStudent> myMap;
    for (int i=0; i<n; ++i) {
        scanf("%d%d%d%d",&stu[i].id,&stu[i].C,&stu[i].M,&stu[i].E);
        stu[i].A=((double)stu[i].C+(double)stu[i].M+(double)stu[i].E)/(double)3;
    }
    for (int i=0; i<4; ++i) {
        flag=i;
        std::sort(stu, stu+n, compare);
        insert_rank(stu, i);
    }
    for (int i=0; i<n; ++i) {
        myMap[stu[i].id]=&stu[i];
    }
    int index;
    while (quires--) {
        scanf("%d",&id);
        if (myMap[id]) {
            index=getBestRank(myMap[id]->rank);
            printf("%d %c\n",myMap[id]->rank[index],s[index]);
        }else{
            printf("N/A\n");
        }
    }
    return 0;
}

//
//  main.cpp
//  1003
//
//  Created by 李波 on 16/7/29.
//  Copyright © 2016年 李波. All rights reserved.
//

#include<iostream>
#include<vector>
#include <map>

#define INF -1

using namespace std;

vector<vector<int>> _map;
vector<int> team;
map<int,bool> visit;

static int cnt=0;

typedef struct node
{
    int shortest;
    int max_team;
}*pNode;

void DFS(int start,int d,pNode p,int cur_team,int cur_path)
{
    if (!visit[start]) {
        visit[start]=true;
        if (start==d) {
            if (cur_path<p->shortest) {
                cnt=1;
                p->shortest=cur_path;
                p->max_team=cur_team+team[start];
            }else if(cur_path==p->shortest){
                ++cnt;
                if (cur_team+team[start]>p->max_team) {
                    p->max_team=cur_team+team[start];
                }
            }
            return;
        }
        if (cur_path>=p->shortest) {
            return;
        }
        for (int i=0; i<_map[start].size(); ++i) {
            if (_map[start][i]!=-1&&!visit[i]) {
                DFS(i, d, p, cur_team+team[start], cur_path+_map[start][i]);
                visit[i]=false;
            }
        }
    }
}

int main()
{
    int n,m,c1,c2;
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    _map.resize(n);
    team.resize(n);
    for (int i=0; i<n; ++i) {
        _map[i].assign(n,INF);
        scanf("%d",&team[i]);
    }
    int a,b,c;
    for (int i=0; i<m; ++i) {
        scanf("%d%d%d",&a,&b,&c);
        _map[a][b]=c;
        _map[b][a]=c;
    }
    node p;
    p.shortest=0x7FFFFFFF;
    p.max_team=0;
    DFS(c1, c2, &p, 0, 0);
    printf("%d %d",cnt,p.max_team);
    return 0;
}

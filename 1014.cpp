//
//  main.cpp
//  1014
//
//  Created by 李波 on 16/8/18.
//  Copyright © 2016年 李波. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <deque>

using namespace std;

void print_time(int cur_time)
{
    if (cur_time>540) {
        printf("Sorry\n");
        return;
    }
    printf("%02d:%02d\n",8+cur_time/60,cur_time%60);
}

int main() {
    int n,m,k,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    int result[100];
    int cur_windows_time[21]={0};
    deque<int> windows[21];
    int cur_time,fast_time,fast_window;
    bool isFull=false,isFirst=false;
    for (int i=0; i<k; ++i) {
        scanf("%d",&cur_time);
        if (!isFull) {
            isFull=true;
            isFirst=false;
            for (int j=0; j<n; ++j) {
                if (windows[j].size()==0) {
                    windows[j].push_back(cur_time);
                    result[i]=cur_time;
                    isFirst=true;
                    isFull=false;
                    break;
                }
            }
            if (!isFirst) {
                for (int j=0; j<n; ++j) {
                    if (windows[j].size()<m) {
                        windows[j].push_back(cur_time);
                        result[i]+=cur_windows_time[j];
                        for (auto &w:windows[j])
                        {
                            result[i]+=w;
                        }
                        isFull=false;
                        break;
                    }
                }
            }
        }
        if (isFull) {
            fast_window=0;
            fast_time=windows[0][0]+cur_windows_time[0];
            for (int j=1; j<n; ++j) {
                if (windows[j][0]+cur_windows_time[j]<fast_time) {
                    fast_window=j;
                    fast_time=windows[j][0]+cur_windows_time[j];
                }
            }
            cur_windows_time[fast_window]+=windows[fast_window].front();
            windows[fast_window].pop_front();
            windows[fast_window].push_back(cur_time);
            result[i]+=cur_windows_time[fast_window];
            for (auto &w:windows[fast_window])
            {
                result[i]+=w;
            }
        }
    }
    int query;
    while (q--) {
        scanf("%d",&query);
        print_time(result[query-1]);
    }
    return 0;
}

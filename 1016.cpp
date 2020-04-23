//
//  main.cpp
//  1016
//
//  Created by 李波 on 16/8/10.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int rate[24],n;

typedef struct event
{
    string name;
    string time;
    bool state;
}Event,*pEvent;

int compare(Event a,Event b)
{
    if (a.name==b.name) {
        return a.time<b.time;
    }
    return a.name<b.name;
}

int aoto(char a,char b)
{
    return (a-'0')*10+(b-'0');
}

double count_price(string start,string end,int *a)
{
    double sum=0;
    *a=0;
    int start_time=aoto(start[6], start[7]);
    int end_time=aoto(end[6], end[7]);
    *a=60-aoto(start[9], start[10]);
    sum=((double)*a/(double)60)*(double)rate[start_time];
    start_time++;
    while (start_time<end_time) {
        *a+=60;
        sum+=rate[start_time];
        start_time++;
    }
    *a=*a+aoto(start[9], start[10]);
    sum=sum+((double)aoto(start[9], start[10])/(double)60)*(double)rate[start_time];
    return sum;
}

int main() {
    for (int i=0; i<24; ++i) {
        scanf("%d",&rate[i]);
    }
    scanf("%d",&n);
    string state;
    vector<Event> myEvent;
    while (n--) {
        Event e;
        cin>>e.name>>e.time>>state;
        if (state=="on-line") {
            e.state=1;
        }else{
            e.state=0;
        }
        myEvent.push_back(e);
    }
    sort(myEvent.begin(), myEvent.end(), compare);
    double sum=0;
    string cur_people=(myEvent.front()).name;
    int cur_state=0;
    
    return 0;
}

//
//  main.cpp
//  1008
//
//  Created by 李波 on 16/8/1.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <math.h>
#include <stdio.h>
#include <iostream>

int main() {
    int n,sum=0;
    int inter_time[3]={4,5,6};
    scanf("%d",&n);
    int quaris,cur_high=0;
    while (n--) {
        scanf("%d",&quaris);
        //if the '=' is deleted,The problem will occur by the case of same layer quarise.
        if ((quaris-cur_high)>=0) {
            sum+=(quaris-cur_high)*inter_time[2];
            sum+=inter_time[1];
        }else if((cur_high-quaris)>=0){
            sum+=(cur_high-quaris)*inter_time[0];
            sum+=inter_time[1];
        }
        cur_high=quaris;
    }
    printf("%d",sum);
    return 0;
}

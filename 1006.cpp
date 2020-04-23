//
//  main.cpp
//  1006
//
//  Created by 李波 on 16/8/1.
//  Copyright © 2016年 李波. All rights reserved.
//
#include <string.h>
#include <stdio.h>
#include <iostream>

int main() {
    char last_time[10]="00:00:00",first_time[10]="23:59:59",first_name[10],last_name[10];
    char temp_name[10],temp_first[10],temp_last[10];
    int n;
    scanf("%d\n",&n);
    while (n--) {
        scanf("%s%s%s",temp_name,temp_first,temp_last);
        if (strcmp(first_time,temp_first)>0) {
            strcpy(first_time, temp_first);
            strcpy(first_name, temp_name);
        }
        if (strcmp(temp_last, last_time)>0) {
            strcpy(last_time, temp_last);
            strcpy(last_name, temp_name);
        }
    }
    printf("%s %s",first_name,last_name);
    return 0;
}

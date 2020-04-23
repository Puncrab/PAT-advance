//
//  main.cpp
//  1007
//
//  Created by 李波 on 16/8/1.
//  Copyright © 2016年 李波. All rights reserved.
//

#include <stdio.h>
#include <iostream>

int main() {
    int max_sum=0,cur_sum=0,n,cur_max_sum=0;
    int low_index=0,high_index,cur_low=0,cur_high=0;
    scanf("%d",&n);
    high_index=n-1;
    int a,b[n];
    for (int i=0; i<n; ++i) {
        scanf("%d",&a);
        b[i]=a;
        cur_sum+=a;
        if (a==0&&cur_sum==0) {
            if (max_sum==0) {
                high_index=i;
                low_index=i;
            }
        }
        if (cur_sum<=0) {
            cur_low=i+1;
            cur_sum=0;
        }else if (cur_sum>cur_max_sum)
        {
            cur_max_sum=cur_sum;
            cur_high=i;
            if (cur_max_sum>max_sum) {
                max_sum=cur_max_sum;
                low_index=cur_low;
                high_index=cur_high;
            }
        }
    }
    printf("%d %d %d",max_sum,b[low_index],b[high_index]);
    return 0;
}

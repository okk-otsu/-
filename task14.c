#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define ll long long

void check_max(ll * cur, ll * cur_max, ll * prev_max){
    if (*cur_max <= *cur){
        *prev_max = *cur_max;
        *cur_max = *cur;
    }
    else{ 
        if (*prev_max < *cur) 
        { *prev_max= *cur; }
    }
}
void check_min(ll * cur, ll * cur_min, ll * prev_min){
    if (*cur <= *cur_min){
        *prev_min = *cur_min;
        *cur_min = *cur;
    }
    else { 
        if (*cur < *prev_min) 
        { *prev_min = *cur; }
    }
}

int main(void){
    ll N;                   scanf("%lld", &N);
    ll cur;                 scanf("%lld", &cur);
    ll prev_min = __LONG_LONG_MAX__;
    ll prev_max = __LONG_LONG_MAX__ * (-1);
    ll cur_min = cur;       ll cur_max = cur;
    // printf("%lld\n", prev_max);
    scanf("%lld", &cur);
    check_max(&cur, &cur_max, &prev_max);
    // printf("%lld %lld\n", prev_max, cur_max);
    check_min(&cur, &cur_min, &prev_min);

    for (int i = 2; i < N; i++) {
        scanf("%lld", &cur);
        check_max(&cur, &cur_max, &prev_max);
        check_min(&cur, &cur_min, &prev_min);
    }

    // ll ans_min;
    // ll ans_max;
    if (prev_min * cur_min < prev_max * cur_max){
        printf("%lld %lld", prev_max, cur_max);
    }
    if (prev_min * cur_min >= prev_max * cur_max){
        printf("%lld %lld", cur_min, prev_min);
    }
    printf("\n");
    // printf("%lld %lld %lld %lld\n", cur_min, prev_min, prev_max, cur_max);
    return 0;
}
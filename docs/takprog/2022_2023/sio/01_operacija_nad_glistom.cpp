#include <bits/stdc++.h>
using namespace std;

int n;

struct node{
    int val = -1;
    node* next = nullptr;
    node(int val):val(val){};
    node(int val, node* next):val(val),next(next){};
};

node *head, *tail;

int solve(node* l_ptr, int total_sum){
    /*for(node* i = head; i != 0; i = i->next){
        if(l_ptr == i){
            printf("*");
        }
        printf("%d ", i->val);
    }
    printf("-- %d\n", total_sum);*/
    if(l_ptr->val == total_sum){
        return 0;
    }
    int ans = 0;
    node* ptr = l_ptr;
    int cur_sum = l_ptr->val;
    while(cur_sum != total_sum/2){
        while(cur_sum < total_sum/2){
            ptr = ptr->next;
            cur_sum += ptr->val;
        }
        while(cur_sum > total_sum/2){
            int a = ptr->val;
            int la = a/2, ra = (a + 1)/2;
            cur_sum -= ra;
            ptr->val = la;
            ptr->next = new node(ra, ptr->next);
            ans++;
        }
    }
    ptr = ptr->next;
    return ans + solve(l_ptr, total_sum/2) + solve(ptr, (total_sum + 1)/2) + 1;
}

int Resi(int N, int* A){
    n = N;
    int total_sum = 0;
    for(int i = 0; i < n; i++){
        int in = A[i];
        total_sum += in;
        if(i == 0){
            head = new node(in);
            tail = head;
        }
        else{
            tail->next = new node(in);
            tail = tail->next;
        }
    }
    return solve(head, total_sum);
}

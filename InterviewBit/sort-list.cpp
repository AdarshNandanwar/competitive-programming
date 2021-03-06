// https://www.interviewbit.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* merge(ListNode* A, int na, ListNode* B, int nb){
    ListNode * head = NULL, * prev = NULL, * curA = A, * curB = B;
    int i = 0, j = 0;
    while(i<na and j<nb){
        if(curA->val > curB->val){
            if(prev){
                prev->next = curB;
                prev = prev->next;
            } else {
                head = prev = curB;
            }
            curB = curB->next;
            j++;
        } else {
            if(prev){
                prev->next = curA;
                prev = prev->next;
            } else {
                head = prev = curA;
            }
            curA = curA->next;
            i++;
        }
    }
    while(i<na){
        if(prev){
            prev->next = curA;
            prev = prev->next;
        } else {
            head = prev = curA;
        }
        curA = curA->next;
        i++;
    }
    while(j<nb){
        if(prev){
            prev->next = curB;
            prev = prev->next;
        } else {
            head = prev = curB;
        }
        curB = curB->next;
        j++;
    }
    prev->next = curB;
    return head;
}

ListNode* mergeSort(ListNode* A, int n){
    if(n <= 1) return A;
    int mid = n/2;
    ListNode * B = A;
    for(int i = 0; i<mid; i++) B = B->next;
    A = mergeSort(A, mid);
    B = mergeSort(B, n-mid);
    return merge(A, mid, B, n-mid);
}
 
 
ListNode* Solution::sortList(ListNode* A) {
    int n = 0;
    ListNode * head = A, * cur = A;
    while(cur){
        n++;
        cur = cur->next;
    }
    return mergeSort(A, n);
}

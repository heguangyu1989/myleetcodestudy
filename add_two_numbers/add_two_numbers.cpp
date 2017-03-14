#include <iostream>

using namespace std;

/*
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
 
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

void printListNode(ListNode* l);

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* res = NULL;
    ListNode* t = NULL;
    ListNode* tmp1 = l1;
    ListNode* tmp2 = l2;
    int tmp = 0;
    while(tmp1 != NULL || tmp2 != NULL)
    {
        if(tmp1 != NULL) tmp += tmp1->val;
        if(tmp2 != NULL) tmp += tmp2->val;
        if(res == NULL)
        {
            res = new ListNode(tmp);
            t = res;
        }
        else
        {
            t->next = new ListNode(tmp % 10);
            t = t->next;
        }
        tmp = (int)(tmp / 10);
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return res;
}

void printListNode(ListNode* l)
{
    ListNode* tmp = l;
    cout<<"Print ListNode : ";
    while(tmp != NULL)
    {
        cout<< tmp->val << ",";
        tmp = tmp->next; 
    }
    cout<<endl;
}

int main()
{
    ListNode* l3 = NULL;
    ListNode* l1 = new ListNode(2);
    ListNode* l1_2 = new ListNode(4);
    ListNode* l1_3 = new ListNode(3);
    l1->next = l1_2;
    l1_2->next = l1_3;
    ListNode* l2 = new ListNode(5);
    ListNode* l2_2 = new ListNode(6);
    ListNode* l2_3 = new ListNode(4);
    l2->next = l2_2;
    l2_2->next = l2_3;    
    printListNode(l1);
    printListNode(l2);    
    l3 = addTwoNumbers(l1, l2);
    printListNode(l3);

    return 0;
}

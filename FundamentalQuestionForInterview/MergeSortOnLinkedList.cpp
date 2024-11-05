#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *merge(ListNode *head1, ListNode *head2)
{
    ListNode *newhead = NULL;
    ListNode *ans = NULL;

    while (head1 && head2)
    {
        if (head1->val < head2->val)
        {
            if (!newhead)
            {
                newhead = head1;
                ans = newhead;
            }
            else
                newhead->next = head1, newhead = newhead->next;
            head1 = head1->next;
            newhead->next = NULL;
        }
        else
        {
            if (!newhead)
            {
                newhead = head2;
                ans = newhead;
            }
            else
                newhead->next = head2, newhead = newhead->next;
            head2 = head2->next;
            newhead->next = NULL;
        }
    }

    while (head1)
    {
        if (!newhead)
        {
            newhead = head1;
            ans = newhead;
        }
        else
            newhead->next = head1, newhead = newhead->next;
        head1 = head1->next;
        newhead->next = NULL;
    }

    while (head2)
    {
        if (!newhead)
        {
            newhead = head2;
            ans = newhead;
        }
        else
            newhead->next = head2, newhead = newhead->next;
        head2 = head2->next;
        newhead->next = NULL;
    }
    return ans;
}

ListNode *mergesort(ListNode *head)
{
    if (!head)
        return head;

    ListNode *cur = head, *mid = head;
    int cnt = 0;

    while (cur)
    {
        if (cnt & 1)
            mid = mid->next;
        cur = cur->next;
        cnt++;
    }

    if (cnt == 1)
        return head;

    cur = head;

    while (cur->next != mid)
        cur = cur->next;

    cur->next = NULL;

    ListNode *head1 = mergesort(head);
    ListNode *head2 = mergesort(mid);

    return merge(head1, head2);
}

ListNode *GetList(vector<int> &num)
{
    ListNode *head = nullptr;

    if (num.empty())
    {
        return head;
    }

    ListNode *cur = head;

    for (int i = 0; i < (int)num.size(); i++)
    {
        ListNode *temp = new ListNode(num[i]);
        if (!cur)
        {
            cur = temp;
            head = cur;
        }
        else
        {
            cur->next = temp;
            cur = temp;
        }
    }

    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num.push_back(x);
    }

    ListNode *head = GetList(num);

    head = mergesort(head);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";

    return 0;
}

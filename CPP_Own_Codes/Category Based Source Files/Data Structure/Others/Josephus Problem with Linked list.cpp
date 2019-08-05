#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node *next = NULL;
    node *prev = NULL;
};

class doubly{
    node *head, *tail;
    int list_size;
public:
    doubly()
    {
        head = new node;
        tail = new node;
        head->next = head->prev = tail;
        tail->prev = tail->next = head;
        list_size = 0;
    }
    void insert_at_end(int key)
    {
        node *q = new node;
        q->prev = tail->prev;
        q->prev->next = q;
        q->next = tail;
        tail->prev = q;
        q->value = key;
        list_size++;
    }
    void delete_node(node *temp)
    {
        node *q = temp->next;
        q->prev = temp->prev;
        temp->prev->next = q;
        free(temp);
        list_size--;
    }
    int josephus(int distance)
    {
        node *start = head->next;
        while(list_size > 1)
        {
            int counter = 0;
            while(1)
            {
                if(start == tail) start = head->next;
                counter++;
//                cout<<"VISITING "<<start->value<<endl;
                node *temp = start;
                start = start->next;
                if(counter == distance)
                {
//                    cout<<"DELETING "<<temp->value<<endl;
                    delete_node(temp);
                    break;
                }
            }
        }
        return head->next->value;
    }
};

int main()
{
    int TC,tcase;
    scanf("%d", &TC);

    for(tcase = 1; tcase <= TC; tcase++)
    {
        doubly a;
        int n,k;
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++)
        {
            a.insert_at_end(i);
        }
        printf("Case %d: %d\n", tcase, a.josephus(k));
    }
    return 0;
}

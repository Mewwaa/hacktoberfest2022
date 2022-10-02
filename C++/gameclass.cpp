#include <bits/stdc++.h>

using namespace std;
struct node
{
    char name[50];
    struct node* next;
};

class game
{
private:
    node* head;

public:
    game()
    {
        head=NULL;
    }
    void addlist()
    {
        node *temp = new node;
        cout << "Enter the name : ";
        cin >> temp->name;
        if (this->head == NULL)
        {
            head = temp;
            temp->next = head;
            temp = NULL;
            delete temp;
        }
        else
        {
            temp->next = head->next;
            head->next = temp;
            temp = NULL;
            delete temp;
            head = head->next;
        }
    }
    void takedata(int size)
    {
        head = NULL;
        for (int i = 0; i < size; i++)
            addlist();
        head = head->next;
    }

    char *solve(int s)
    {
        while (head->next != head)
        {
            int flag = (s - 1);
            for (int i = 0; i < flag; i++)
            {
                head = head->next;
            }
            node *temp = head->next;
            head->next = temp->next;
            temp->next = NULL;
            head = head->next;
            delete temp;
        }
        return head->name;
    }
};
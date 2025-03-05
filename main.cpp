#include <bits/stdc++.h>

using namespace std;

struct List
{
    string value;
    struct List *next;
    struct List *prev;
};

typedef struct List node;

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    cout << "Browser history simulator built in C++\n\n";
    cout << "Press 'q' to exit\n";
    cout << "Press 's' to show the current location\n";
    cout << "Press 'p' to move to the previous website\n";
    cout << "Press 'n' to move to the next website\n";
    cout << "Enter a new link to change the current location\n";

    node *head = NULL, *tail = NULL;

    while (true)
    {
        string input;
        cin >> input;

        if (input == "q")
        {
            return 0;
        }
        else if (input == "s")
        {
            if (head != NULL)
            {
                cout << "Current location: " << head->value << endl;
            }
            else
            {
                cout << "No websites visited yet.\n";
            }
        }
        else if (input == "p")
        {
            if (head != NULL && head->prev != NULL)
            {
                cout << "Previous website: " << head->prev->value << endl;
                head = head->prev;
            }
            else
            {
                cout << "No previous website.\n";
            }
        }
        else if (input == "n")
        {
            if (head != NULL && head->next != NULL)
            {
                cout << "Next website: " << head->next->value << endl;
                head = head->next;
            }
            else
            {
                cout << "No next website.\n";
            }
        }
        else
        {
            node *newNode = new node;
            newNode->value = input;
            newNode->next = NULL;
            newNode->prev = head;

            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                head->next = newNode;
                head = newNode;
            }
        }
    }
}

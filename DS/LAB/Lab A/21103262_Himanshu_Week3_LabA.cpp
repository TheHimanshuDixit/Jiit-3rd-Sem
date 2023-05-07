// #include <iostream>
// using namespace std;
// struct node
// {
//     int info;
//     node *next;

// public:
//     node(int n)
//     {
//         info = n;
//         next = NULL;
//     }
// };

// class linkedlist
// {
//     node *head = NULL;
//     node *tail = NULL;

// public:
//     void add(int n)
//     {
//         node *temp = new node(n);
//         if (head == NULL)
//         {
//             head = temp;
//             tail = temp;
//         }
//         else
//         {
//             tail->next = temp;
//             tail = temp;
//         }
//     }
//     void print()
//     {
//         node *cur = head;
//         while (cur != NULL)
//         {
//             cout << cur->info << " ";
//             cur = cur->next;
//         }
//     }
//     node *shifting()
//     {
//         if(head == NULL || head->next == NULL)
//         {
//             return head;
//         }
//         node *cur = head;
//         while(cur->next->next != NULL)
//         {
//             cur = cur->next;
//         }
//         node *temp =cur->next;
//         cur->next = NULL;
//         temp->next = head;
//         head = temp;
//         return head;
//     }
//     void transform()
//     {
//         head = shifting();
//     }
// };

// int main()
// {
//     linkedlist l;
//     int n;
//     cin >> n;
//     int num;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> num;
//         l.add(num);
//     }
//     cout << "Before shifting : ";
//     l.print();
//     l.transform();
//     cout << "\nAfter shifting : ";
//     l.print();
//     return 0;
// }

/*
class linkedlist;
class Node
{
    string info;
    Node *next;

public:
    Node(const string s, Node *link)
    {
        info = s;
        next = link;
    }
    friend class linkedlist;
};

class linkedlist
{

public:
    Node *rear;
    Node *tail;
    linkedlist()
    {
        tail = NULL;
        rear = NULL;
    }
    void cinsert(string s)
    {
        Node *temp = new Node(s, NULL);
        if (rear == NULL)
        {
            rear = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        tail->next = rear;
    }
    void ctraverse()
    {
        Node *cur = rear;
        if (cur == NULL)
        {
            cout << "list is empty\n";
        }
        else
        {
            cout << cur->info << endl;
            cur = cur->next;
            while (cur != rear)
            {
                cout << cur->info << endl;
                cur = cur->next;
            }
        }
    }
    void ListSplit(Node *&list, Node *&sub1, Node *&sub2)
    {
        sub1 = list;
        sub2 = list;
        while (sub2->next->next != list)
        {
            sub2 = sub2->next->next;
            sub1 = sub1->next;
        }
        sub2 = sub2->next->next;
        sub1 = sub1->next;
        list = list->next;
        sub2->next = sub1->next;
        sub1->next = list;
        sub1 = sub1->next;
        sub2 = sub2->next;
        list = NULL;
    }
};
int main()
{
    linkedlist l;
    linkedlist l1;
    linkedlist l2;
    string s;
    cin >> s;
    l.cinsert(s);
    cin >> s;
    l.cinsert(s);
    cin >> s;
    l.cinsert(s);
    cin >> s;
    l.cinsert(s);
    cin >> s;
    l.cinsert(s);
    cin >> s;
    l.cinsert(s);
    cin >> s;
    l.cinsert(s);
    cin >> s;
    l.cinsert(s);
    l.ListSplit(l.rear, l1.rear, l2.rear);
    l.ctraverse();
    l1.ctraverse();
    cout << endl;
    l2.ctraverse();
    return 0;
}
*/

/*
#include <iostream>
using namespace std;

template <class t = int>
class node
{
    t data;
    node *next;

public:
    node(t a)
    {
        data = a;
        next = NULL;
    }
    template <class u>
    friend class circular_list;
};

template <class t = int>
class circular_list
{
    node<t> *rear;

    node<t> *tail()
    {
        node<t> *temp = rear;
        while (temp->next != rear)
        {

            temp = temp->next;
        }
        return temp;
    }

public:
    circular_list()
    {
        int n;
        cout << "Enter number of nodes:\n";
        cin >> n;
        if (n < 1)
        {
            rear = NULL;
            return;
        }
        t ele;
        cout << "Enter Elements for your circular linked list:\n";
        cin >> ele;
        rear = new node<t>(ele);
        n--;
        node<t> *cur = rear;

        while (n--)
        {
            cin >> ele;
            node<t> *temp = new node<t>(ele);
            cur->next = temp;
            cur = temp;
        }
        cur->next = rear;
    }

    void print()
    {

        node<t> *temp = rear;
        if (temp == NULL)
        {
            cout << "Empty List\n";
            return;
        }
        while (temp->next != rear)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << temp->data << endl;
    }

    void push()
    {
        t a;
        cout << "Enter an element to enter at the end:\n";
        cin >> a;
        node<t> *temp = new node<t>(a);
        temp->next = rear;
        tail()->next = temp;
    }
    void push(t a)
    {

        node<t> *temp = new node<t>(a);
        temp->next = rear;
        tail()->next = temp;
    }
    void insert()
    {
        int n;
        t a;
        cout << "Enter Index:";
        cin >> n;
        if (n < 0)
        {
            cout << "Invalid\n";
            return;
        }

        cout << "Enter data:";
        cin >> a;
        if (n == 0)
        {
            push(a);
            rear = tail();
            return;
        }
        node<t> *cur = rear;
        while (--n)
        {
            cur = cur->next;
        }
        node<t> *temp = new node<t>(a);
        temp->next = cur->next;
        cur->next = temp;
    }
    void del()
    {
        cout << "Enter data to delete:";
        t a;
        cin >> a;
        node<t> *cur = rear;
        while (cur->next != rear)
        {
            if (cur->next->data == a)
            {
                cur->next = cur->next->next;
                continue;
            }
            cur = cur->next;
        }
        if (rear->data == a && cur == rear)
        {
            rear = NULL;
        }
        else if (rear->data == a)
        {
            cur->next = rear->next;
            rear = rear->next;
        }
    }

    void concat(circular_list l)
    {
        node<t> *r1 = rear;
        node<t> *r2 = l.rear;

        if (r2 == NULL)
        {
            return;
        }
        if (r1 == NULL)
        {
            rear = r2;
            return;
        }

        tail()->next = r2;
        l.tail()->next = r1;
    }

    void romove_duplicates()
    {
        node<t> *cur = rear;
        if (cur == NULL)
        {
            return;
        }

        while (cur->next != rear)
        {
            node<t> *temp = cur;

            t a = cur->data;

            while (temp->next != cur)
            {
                if (temp->next->data == a)
                {
                    temp->next = temp->next->next;
                    continue;
                }
                temp = temp->next;
            }
            cur = cur->next;
        }
    }
};

int main()
{

    circular_list<int> list1;
    // circular_list<int> list2;

    // list.insert();
    // list1.del();
    // list1.concat(list2);
    list1.romove_duplicates();
    list1.print();

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int coeff, power;
	Node* next;
};

Node* addnode(Node* start, int coeff, int power)
{
	// Create a new node
	Node* newnode = new Node;
	newnode->coeff = coeff;
	newnode->power = power;
	newnode->next = NULL;

	if (start == NULL)
		return newnode;

	Node* ptr = start;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = newnode;

	return start;
}

void printList(struct Node* ptr)
{
	while (ptr->next != NULL) {
		cout << ptr->coeff << "x^" << ptr->power ;
	if( ptr->next!=NULL && ptr->next->coeff >=0)
		cout << "+";

		ptr = ptr->next;
	}
	cout << ptr->coeff << "\n";
}

void removeDuplicates(Node* start)
{
	Node *ptr1, *ptr2, *dup;
	ptr1 = start;

	while (ptr1 != NULL && ptr1->next != NULL) {
		ptr2 = ptr1;

		while (ptr2->next != NULL) {

			if (ptr1->power == ptr2->next->power) {

				ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;

				delete (dup);
			}
			else
				ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	}
}

Node* multiply(Node* poly1, Node* poly2,
			Node* poly3)
{

	Node *ptr1, *ptr2;
	ptr1 = poly1;
	ptr2 = poly2;
	while (ptr1 != NULL) {
		while (ptr2 != NULL) {
			int coeff, power;

			coeff = ptr1->coeff * ptr2->coeff;

			power = ptr1->power + ptr2->power;

			poly3 = addnode(poly3, coeff, power);

			ptr2 = ptr2->next;
		}

		ptr2 = poly2;

		ptr1 = ptr1->next;
	}

	removeDuplicates(poly3);
	return poly3;
}

int main()
{

	Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

	poly1 = addnode(poly1, 3, 3);
	poly1 = addnode(poly1, 6, 1);
	poly1 = addnode(poly1, -9, 0);

	poly2 = addnode(poly2, 9, 3);
	poly2 = addnode(poly2, -8, 2);
	poly2 = addnode(poly2, 7, 1);
	poly2 = addnode(poly2, 2, 0);

	cout << "1st Polynomial:- ";
	printList(poly1);

	cout << "2nd Polynomial:- ";
	printList(poly2);

	poly3 = multiply(poly1, poly2, poly3);

	cout << "Resultant Polynomial:- ";
	printList(poly3);

	return 0;
}
*/

#include <iostream>
using namespace std;
bool isvowel(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        return true;
    return false;
}

template <typename t = int>
class node
{

    t data;
    int k=0;
    node *next;

public:
    node()
    {

        data = 0;
        next = NULL;
    }

    node(t a)
    {

        data = a;
        next = NULL;
    }

    void input(int n)
    {
        t a;
        if (n > 0)
        {
            cin >> a;
            this->data = a;
            n--;
        }
        node *tail = this;

        while (n--)
        {

            cin >> a;
            node *temp = new node(a);

            tail->next = temp;
            tail = tail->next;
        }
    }

    void print()
    {
        if (this == NULL)
        {
            cout << "Linkerd List is empty";
            return;
        }
        cout << "Elements of LinkedList are:\n";
        node *temp = this;

        while (temp != NULL)
        {

            cout << temp->data << " ";

            temp = temp->next;
        }
        cout << endl;
    }

    void info()
    {
        if (this == NULL)
        {
            return;
        }
        node *temp = this;

        int count = 0;
        t min = this->data;
        t max = this->data;

        while (temp != NULL)
        {
            count++;
            if (min > temp->data)
            {
                min = temp->data;
            }

            if (max < temp->data)
            {
                max = temp->data;
            }
            temp = temp->next;
        }

        cout << "Total Nodes:"
             << count << endl;
        cout << "Maximum:"
             << max << endl;
        cout << "Minimum:"
             << min << endl;
    }

    node *insertatend(t a)
    {
        node *temp = this;
        node *newnode = new node(a);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        return this;
    }
    node *insertatstart(t a)
    {
        node *temp = new node(a);
        temp->next = this;
        return temp;
    }

    node *insert(int n, t a)
    {
        if (n < 0)
        {
            cout << "Index out of range\n";
            return this;
        }
        if (n == 0)
        {
            insertatstart(a);
        }
        else
        {
            node *temp = this;
            while (--n)
            {
                if (temp == NULL)
                {
                    cout << "Index out of range\n";
                    return this;
                }
                temp = temp->next;
            }

            node<t> *newnode = new node<t>(a);
            newnode->next = temp->next;
            temp->next = newnode;
        }
        return this;
    }
    node *removevowol()
    {
        node *pre = this, *temp = this;

        while (temp != NULL)
        {
            if (isvowel(temp->data))
            {
                pre->next = temp->next;
            }

            temp = temp->next;
            if (temp != NULL && !isvowel(temp->data))
            {

                pre = temp;
            }
        }
        if (isvowel(this->data))
        {
            return this->next;
        }
        return this;
    }

    node *remove(node *b)
    {

        node *t1 = this, *t2 = b;
    }
};

node<int> *inttolist(int n)
{
    node<int> *head = new node<int>(n % 10);
    n = n / 10;
    while (n != 0)
    {
        head = head->insertatstart(n % 10);
        n = n / 10;
    }
    return head;
}

node<char> *stringtolist(string str)
{

    node<char> *head = new node<char>(str[0]);

    int i = 1;
    while (str[i] != '\0')
    {
        head->insertatend(str[i]);
        i++;
    }
    return head;
}

template <typename t = int>
class dnode
{
    t data;
    dnode *next;
    dnode *pre;

public:
    dnode()
    {
        data = 0;
        next = NULL;
        pre = NULL;
    }
    dnode(t a)
    {
        data = a;
        next = NULL;

        pre = NULL;
    }
    void input(int n)
    {
        t a;
        if (n > 0)
        {
            cin >> a;
            this->data = a;
            n--;
        }
        dnode<t> *tail = this, *pre = NULL;

        while (n--)
        {
            cin >> a;
            dnode *temp = new dnode(a);
            temp->pre = tail;
            tail->next = temp;
            pre = tail;
            tail = tail->next;
        }
    }
    void rprint()
    {
        if (this == NULL)
        {
            cout << "Linkerd List is empty";
            return;
        }
        dnode<int> *temp = this;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->pre;
        }
    }
    dnode *insert(int n, t a)
    {
        dnode<t> *temp = new dnode(a);
        if (n == 0)
        {
            if (temp == NULL)
            {
                cout << "Index out of range\n";
                return this;
            }
            temp->next = this;
            this->pre = temp;
            return temp;
        }

        dnode<t> *aux = this;

        while (--n)
        {
            if (aux == NULL)
            {
                cout << "Index out of range\n";
                return this;
            }
            aux = aux->next;
        }
        if (aux->next != NULL)
        {
            aux->next->pre = temp;
        }
        temp->next = aux->next;
        aux->next = temp;
        temp->pre = aux;
        return this;
    }
    void print()
    {
        if (this == NULL)
        {
            cout << "Linkerd List is empty";
            return;
        }
        cout << "Elements of LinkedList are:\n";
        dnode *temp = this;

        while (temp != NULL)
        {

            cout << temp->data << " ";

            temp = temp->next;
        }
        cout << endl;
    }
    dnode *delend()
    {
        if (this->next == NULL)
        {

            cout << "Last dnode deleted\n";
            return NULL;
        }
        dnode *temp = this;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        cout << "Last dnode deleted\n";
        return this;
    }
    // void ExtremeSwap()
    // {
    //     dnode *temp = this;
    //     while (temp->next != NULL)
    //     {
    //         temp = temp->next;
    //     }

    //     t x = this->data;
    //     this->data = temp->data;
    //     temp->data = x;
    //     cout << "Extreme Ends swaped\n";
    // }
    void ExtremeSwap()
    {
       
        int n = k;
        cout << k << "\n";
        if (k < length())
        {
            dnode<t> *tail = this->tail();
            dnode<t> *cur = this;
            while (cur != NULL && tail != NULL && n--)
            {
                cur = cur->next;
                tail = tail->pre;
            }
            swap(cur->data, tail->data);
        }
        k++;
    }

    dnode *removesubstr(dnode *x)
    {
        dnode *head = this;
        dnode *b = x->next;

        while (b->next != NULL)

        {
            if (head->next == NULL)
                break;
            dnode *a = head->next;

            while (a != NULL && a->next != NULL)
            {
                if (b->pre->data == a->pre->data && b->data == a->data && b->next->data == a->next->data)
                {
                    if (a->pre->pre == NULL)
                    {
                        head = a->next->next;
                        head->pre = NULL;
                        if (head->next == NULL)
                        {
                            break;
                        }
                        a = head->next;
                        continue;
                    }
                    a->pre->pre->next = a->next->next;

                    if (a->next->next != NULL)
                    {
                        a->next->next->pre = a->pre->pre;
                        a = a->next->next->next;
                        continue;
                    }
                }
                a = a->next;
            }
            b = b->next;
        }
        cout << "Substrings have been removed\n";
        return head;
    }
};

int main()
{
    int num, data;
    cout << "Enter Number of Nodes:";
    cin >> num;
    node<int> *head = new node<int>();
    head->input(num);
    head->info();
    head->print();

    cout << "Enter an integer to insert at the start of list:";
    cin >> data;
    head = head->insertatstart(data);
    head->info();
    head->print();

    cout << "\n\n";

    cout << "Enter an index and integer to insert in list:";
    cin >> num >> data;
    head = head->insert(num, data);
    head->print();
    head->info();

    cout << "\n\n";

    cout << "Enter an integer to create a linked list:";
    cin >> data;
    node<int> *head2 = inttolist(data);
    head2->info();
    head2->print();

    cout << "\n\n";
    cout << "Enter a string to make a Linked List:";
    cin.ignore();
    string str;
    getline(cin, str);
    node<char> *charh = new node<char>();

    cout << "\n\n";
    node<char> *head3 = stringtolist(str);
    head3 = head3->removevowol();
    cout << "Vowels has been removed from the List\n";
    head3->info();
    head3->print();
    cout << "\n\n";
    cout << "\nDoubly Linked List\n\n";

    dnode<char> *head4 = new dnode<char>;
    cout << "Enter 10 Characters:";
    head4->input(10);
    dnode<char> *head5 = new dnode<char>;
    cout << "Enter 5 Characters:";
    head5->input(5);
    head4 = head4->removesubstr(head5);
    head4->print();
    cout << "\n";
    dnode<> *head6 = new dnode<>;

    cout << "Enter number of nodes to input:";
    cin >> num;
    head6->input(num);
    cout << "Enter an index and integer to insert in list:";
    cin >> num >> data;
    head6 = head6->insert(num, data);
    head6 = head6->delend();
    head6->ExtremeSwap();
    head6->print();

    return 0;
}
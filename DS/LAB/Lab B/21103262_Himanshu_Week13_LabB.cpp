
//------------------SOLUTION 1----------------------------

#include <iostream>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = {1, 12, 9, 5, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}

//------------------SOLUTION 2----------------------------

#include <bits/stdc++.h>
using namespace std;
void maxHeapify(int arr[], int N, int idx)
{
    if (idx >= N)
        return;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int max = idx;
    if (l < N && arr[l] > arr[idx])
        max = l;
    if (r < N && arr[r] > arr[max])
        max = r;
    if (max != idx)
    {
        swap(arr[max], arr[idx]);
        maxHeapify(arr, N, max);
    }
}
void buildMaxHeap(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        maxHeapify(arr, N, i);
}
void mergeHeaps(int merged[], int a[], int b[], int N,
                int M)
{
    for (int i = 0; i < N; i++)
        merged[i] = a[i];
    for (int i = 0; i < M; i++)
        merged[N + i] = b[i];
    buildMaxHeap(merged, N + M);
}
int main()
{
    int a[] = {10, 5, 6, 2};
    int b[] = {12, 7, 9};
    int N = sizeof(a) / sizeof(a[0]);
    int M = sizeof(b) / sizeof(b[0]);
    int merged[N + M];
    mergeHeaps(merged, a, b, N, M);
    for (int i = 0; i < N + M; i++)
        cout << merged[i] << " ";
    return 0;
}

//------------------SOLUTION 3----------------------------

#include <bits/stdc++.h>
using namespace std;
int minOperations(int arr[], int K,
                  int size)
{
    int least, second_least,
        min_operations = 0,
        new_ele = 0, flag = 0;
    priority_queue<int, vector<int>,
                   greater<int>>
        heap;
    for (int i = 0; i < size; i++)
    {
        heap.push(arr[i]);
    }
    while (heap.size() != 1)
    {
        if (heap.top() >= K)
        {
            flag = 1;
            break;
        }
        least = heap.top();
        heap.pop();
        second_least = heap.top();
        heap.pop();
        new_ele = (1 * least) +
                  (2 * second_least);
        min_operations++;
        heap.push(new_ele);
    }
    if (
        heap.top() >= K)
    {
        flag = 1;
    }
    if (
        flag == 1)
    {
        return min_operations;
    }
    return -1;
}
int main()
{
    int N = 6, K = 7;
    int arr[] = {1, 2, 3, 9, 10, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << minOperations(arr, K, size);
    return 0;
}

//------------------SOLUTION 4----------------------------

#include <bits/stdc++.h>
using namespace std;
struct MinHeap
{
    unsigned size;
    unsigned capacity;
    int *harr;
};
struct MinHeap *createMinHeap(unsigned capacity)
{
    struct MinHeap *minHeap = new MinHeap;
    minHeap->size = 0; // current size is 0
    minHeap->capacity = capacity;
    minHeap->harr = new int[capacity];
    return minHeap;
}
void swapMinHeapNode(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void minHeapify(struct MinHeap *minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->harr[left] < minHeap->harr[smallest])
        smallest = left;
    if (right < minHeap->size && minHeap->harr[right] < minHeap->harr[smallest])
        smallest = right;
    if (smallest != idx)
    {
        swapMinHeapNode(&minHeap->harr[smallest],
                        &minHeap->harr[idx]);
        minHeapify(minHeap, smallest);
    }
}
int isSizeOne(struct MinHeap *minHeap)
{
    return (minHeap->size == 1);
}
int extractMin(struct MinHeap *minHeap)
{
    int temp = minHeap->harr[0];
    minHeap->harr[0] = minHeap->harr[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
void insertMinHeap(struct MinHeap *minHeap, int val)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && (val < minHeap->harr[(i - 1) / 2]))
    {
        minHeap->harr[i] = minHeap->harr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->harr[i] = val;
}
void buildMinHeap(struct MinHeap *minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
struct MinHeap *createAndBuildMinHeap(int len[], int size)
{
    struct MinHeap *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->harr[i] = len[i];
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
int minCost(int len[], int n)
{
    int cost = 0;
    struct MinHeap *minHeap = createAndBuildMinHeap(len, n);
    while (!isSizeOne(minHeap))
    {
        int min = extractMin(minHeap);
        int sec_min = extractMin(minHeap);
        cost += (min + sec_min);
        insertMinHeap(minHeap, min + sec_min);
    }
    return cost;
}
int main()
{
    int len[] = {4, 3, 2, 6};
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is "
         << minCost(len, size);
    return 0;
}

//------------------SOLUTION 6----------------------------

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <malloc.h>
using namespace std;
struct node
{
    node *parent;
    node *child;
    node *left;
    node *right;
    int key;
    int degree;
    char mark;
    char c;
};
struct node *mini = NULL;
int no_of_nodes = 0;
void insertion(int val)
{
    struct node *new_node = new node();
    new_node->key = val;
    new_node->degree = 0;
    new_node->mark = 'W';
    new_node->c = 'N';
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if (mini != NULL)
    {
        (mini->left)->right = new_node;
        new_node->right = mini;
        new_node->left = mini->left;
        mini->left = new_node;
        if (new_node->key < mini->key)
            mini = new_node;
    }
    else
    {
        mini = new_node;
    }
    no_of_nodes++;
}
void Fibonnaci_link(struct node *ptr2, struct node *ptr1)
{
    (ptr2->left)->right = ptr2->right;
    (ptr2->right)->left = ptr2->left;
    if (ptr1->right == ptr1)
        mini = ptr1;
    ptr2->left = ptr2;
    ptr2->right = ptr2;
    ptr2->parent = ptr1;
    if (ptr1->child == NULL)
        ptr1->child = ptr2;
    ptr2->right = ptr1->child;
    ptr2->left = (ptr1->child)->left;
    ((ptr1->child)->left)->right = ptr2;
    (ptr1->child)->left = ptr2;
    if (ptr2->key < (ptr1->child)->key)
        ptr1->child = ptr2;
    ptr1->degree;
}
void Consolidate()
{
    int temp1;
    float temp2 = (log(no_of_nodes)) / (log(2));
    int temp3 = temp2;
    struct node *arr[temp3 + 1];
    for (int i = 0; i <= temp3; i++)
        arr[i] = NULL;
    node *ptr1 = mini;
    node *ptr2;
    node *ptr3;
    node *ptr4 = ptr1;
    do
    {
        ptr4 = ptr4->right;
        temp1 = ptr1->degree;
        while (arr[temp1] != NULL)
        {
            ptr2 = arr[temp1];
            if (ptr1->key > ptr2->key)
            {
                ptr3 = ptr1;
                ptr1 = ptr2;
                ptr2 = ptr3;
            }
            if (
                ptr2 == mini)
                mini = ptr1;
            Fibonnaci_link(ptr2, ptr1);
            if (ptr1->right == ptr1)
                mini = ptr1;
            arr[temp1] = NULL;
            temp1++;
        }
        arr[temp1] = ptr1;
        ptr1 = ptr1->right;
    } while (ptr1 != mini);
    mini = NULL;
    for (int j = 0; j <= temp3; j++)
    {
        if (arr[j] != NULL)
        {
            arr[j]->left = arr[j];
            arr[j]->right = arr[j];
            if (mini != NULL)
            {
                (mini->left)->right = arr[j];
                arr[j]->right = mini;
                arr[j]->left = mini->left;
                mini->left = arr[j];
                if (arr[j]->key < mini->key)
                    mini = arr[j];
            }
            else
            {
                mini = arr[j];
            }
            if (
                mini == NULL)
                mini = arr[j];
            else if (arr[j]->key < mini->key)
                mini = arr[j];
        }
    }
}
void Extract_min()
{
    if (mini == NULL)
        cout << "The heap is empty" << endl;
    else
    {
        node *temp = mini;
        node *pntr;
        pntr = temp;
        node *x = NULL;
        if (temp->child != NULL)
        {
            x = temp->child;
            do
            {
                pntr = x->right;
                (mini->left)->right = x;
                x->right = mini;
                x->left = mini->left;
                mini->left = x;
                if (x->key < mini->key)
                    mini = x;
                x->parent = NULL;
                x = pntr;
            } while (pntr != temp->child);
        }
        (
            temp->left)
            ->right =
            temp->right;
        (temp->right)->left = temp->left;
        mini = temp->right;
        if (temp == temp->right && temp->child == NULL)
            mini = NULL;
        else
        {
            mini = temp->right;
            Consolidate();
        }
        no_of_nodes--;
    }
}
void Cut(struct node *found, struct node *temp)
{
    if (found == found->right)
        temp->child = NULL;
    (found->left)->right = found->right;
    (found->right)->left = found->left;
    if (found == temp->child)
        temp->child = found->right;
    temp->degree = temp->degree - 1;
    found->right = found;
    found->left = found;
    (mini->left)->right = found;
    found->right = mini;
    found->left = mini->left;
    mini->left = found;
    found->parent = NULL;
    found->mark = 'B';
}
void Cascase_cut(struct node *temp)
{
    node *ptr5 = temp->parent;
    if (ptr5 != NULL)
    {
        if (temp->mark == 'W')
        {
            temp->mark = 'B';
        }
        else
        {
            Cut(temp, ptr5);
            Cascase_cut(ptr5);
        }
    }
}
void Decrease_key(struct node *found, int val)
{
    if (mini == NULL)
        cout << "The Heap is Empty" << endl;
    if (found == NULL)
        cout << "Node not found in the Heap" << endl;
    found->key = val;
    struct node *temp = found->parent;
    if (temp != NULL && found->key < temp->key)
    {
        Cut(found, temp);
        Cascase_cut(temp);
    }
    if (
        found->key <
        mini->key)
        mini = found;
}
void Find(struct node *mini, int old_val, int val)
{
    struct node *found = NULL;
    node *temp5 = mini;
    temp5->c = 'Y';
    node *found_ptr = NULL;
    if (temp5->key == old_val)
    {
        found_ptr = temp5;
        temp5->c = 'N';
        found = found_ptr;
        Decrease_key(found, val);
    }
    if (
        found_ptr == NULL)
    {
        if (temp5->child != NULL)
            Find(temp5->child, old_val, val);
        if ((temp5->right)->c != 'Y')
            Find(temp5->right, old_val, val);
    }
    temp5->c =
        ' N';
    found = found_ptr;
}
void Deletion(int val)
{
    if (mini == NULL)
        cout << "The heap is empty" << endl;
    else
    {
        Find(mini, val, 0);
        Extract_min();
        cout << "Key Deleted" << endl;
    }
}
void display()
{
    node *ptr = mini;
    if (ptr == NULL)
        cout << "The Heap is Empty" << endl;
    else
    {
        cout << "The root nodes of Heap are: " << endl;
        do
        {
            cout << ptr->key;
            ptr = ptr->right;
            if (ptr != mini)
            {
                cout << "-->";
            }
        } while (ptr != mini && ptr->right != NULL);
        cout << endl
             << "The heap has " << no_of_nodes << " nodes" << endl
             << endl;
    }
}
int main()
{
    cout << "Creating an initial heap" << endl;
    insertion(5);
    insertion(2);
    insertion(8);
    display();
    cout << "Extracting min" << endl;
    Extract_min();
    display();
    cout << "Decrease value of 8 to 7" << endl;
    Find(mini, 8, 7);
    display();
    cout << "Delete the node 7" << endl;
    Deletion(7);
    display();
    return 0;
}

//------------------SOLUTION 7----------------------------

#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = {4, 6, 3, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}

#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
template <class T>
class Stack
{
public:
    struct Node
    {
        T data;
        Node *next=NULL;
    };
    Node* head=NULL;
    void push(T data)
    {
        Node *new_node=new Node;
        new_node->data=data;
        new_node->next=head;
        head=new_node;
    }
    bool isEmpty()
    {
        if (head==NULL)
            return true;
        else
            return false;
    }
    void pop()
    {
        if (head!=NULL)
        {
            Node* temp=head;
            head=head->next;
            delete temp;
        }
    }
    T top()
    {
        if (head!=NULL)
            return head->data;
        else
            cout << "Empty Stack!\n";
    }
    void display()
    {
        Node* temp=head;
        while (temp!=NULL)
        {
            cout << temp->data << " ";
            temp=temp->next;
        }
    }
};

void sortedInsert(Stack<int>* &s, int x)
{
    if (s->isEmpty() || x > s->top())
    {
        s->push(x);
        return;
    }
    int temp = s->top();
    s->pop();
    sortedInsert(s, x);
    s->push(temp);
}

void sortStack(Stack<int>* &s)
{
	if (!s->isEmpty())
    {
		int x = s->top();
		s->pop();
        sortStack(s);
		sortedInsert(s, x);
	}
}

void q1()
{
	Stack<int> *S=new Stack<int>;
	int n,temp;
	st :
	cout << "Enter the no. of elements in the stack : ";
	cin >> n;
	if (n<=0)
    {
        cout << "Enter valid input!!!\n";
        goto st;
    }
    for (int i=1;i<=n;i++)
    {
        cout << "Enter the element " << i << " : ";
        cin >> temp;
        S->push(temp);
    }
	cout << "Stack elements before sorting:\n";
	S->display();
	sortStack(S);
	cout << "\n";
	cout << "Stack elements after sorting:\n";
    S->display();
}

bool isPalindrome(string str, int low, int high)
{
	while (low < high)
	{
		if (str[low] != str[high])
			return false;
		low++;
		high--;
	}
	return true;
}

void allPalPartUtil(vector<vector<string>>&allPart, vector<string> &currPart, int start, int n, string str)
{
	if (start >= n)
	{
		allPart.push_back(currPart);
		return;
	}
	for (int i=start; i<n; i++)
	{
		if (isPalindrome(str, start, i))
		{
			currPart.push_back(str.substr(start, i-start+1));
			allPalPartUtil(allPart, currPart, i+1, n, str);
			currPart.pop_back();
		}
	}
}

void allPalPartitions(string str)
{
	int n = str.length();
	vector<vector<string> > allPart;
	vector<string> currPart;
	allPalPartUtil(allPart, currPart, 0, n, str);
	for (int i=0; i< allPart.size(); i++ )
	{
		for (int j=0; j<allPart[i].size(); j++)
			cout << allPart[i][j] << " ";
		cout << "\n";
	}
}

void q2()
{
	string str;
	cout << "Enter the string : ";
	cin >> str;
	cout << "All the possible partitions are : \n";
	allPalPartitions(str);
}

void q3()
{
    Stack<char> S;
    string s;
    cout << "Enter the string : ";
    cin >> s;
    for (int i=0;i<s.length();i++)
    {
        S.push(s[i]);
    }
    for (int i=0;i<s.length();i++)
    {
        s[i]=S.top();
        S.pop();
    }
    cout << "Reversed string : " << s;
}

int transfer_disk(Stack<int>& a,Stack<int>& b){
    if(b.isEmpty()==true){
        b.push(a.top());
        a.pop();
        return 1;
    }
    else if(a.isEmpty()==true){
        a.push(b.top());
        b.pop();
        return 2;
    }
    else{
        if(b.top()>a.top()){
            b.push(a.top());
            a.pop();
            return 1;
        }
        else{
            a.push(b.top());
            b.pop();
            return 2;
        }
    }
}

void q4()
{
    Stack<int> s,a,d;
    int n=0;
    cout << "Enter the no. of disks : ";
    cin>>n;
    for(int i=n;i>=1;i--)
    {
        s.push(i);
    }
    int x=pow(2,n)-1;
    int i=1;
    cout << "Operations : \n";
    if(n%2==0)
    {
        while(i<=x)
        {
            if(i%3==1)
            {
                int y=transfer_disk(s,a);
                if(y==1)
                {
                    cout<<"Move the disk "<<a.top()<<" from source to auxiliary"<<endl;
                }
                else
                    cout<<"Move the disk "<<s.top()<<" from auxiliary to source"<<endl;
            }
            else if(i%3==2)
            {
                int y=transfer_disk(s,d);
                if(y==1)
                {
                    cout<<"Move the disk "<<d.top()<<" from source to destination"<<endl;
                }
                else
                    cout<<"Move the disk "<<s.top()<<" from destination to source"<<endl;
            }
            else
            {
                int y=transfer_disk(a,d);
                if(y==1)
                {
                    cout<<"Move the disk "<<d.top()<<" from auxiliary to destination"<<endl;
                }
                else
                    cout<<"Move the disk "<<a.top()<<" from destination to auxiliary"<<endl;
            }
            i++;
        }
    }
    else
    {
        while(i<=x)
        {
            if(i%3==1)
            {
                int y=transfer_disk(s,d);
                if(y==1)
                {
                    cout<<"Move the disk "<<d.top()<<" from source to destination"<<endl;
                }
                else
                    cout<<"Move the disk "<<s.top()<<" from destination to source"<<endl;
            }
            else if(i%3==2)
            {
                int y=transfer_disk(s,a);
                if(y==1)
                {
                    cout<<"Move the disk "<<a.top()<<" from source to auxiliary"<<endl;
                }
                else
                    cout<<"Move the disk "<<s.top()<<" from auxiliary to source"<<endl;
            }
            else
            {
                int y=transfer_disk(a,d);
                if(y==1)
                {
                    cout<<"Move the disk "<<d.top()<<" from auxiliary to destination"<<endl;
                }
                else
                    cout<<"Move the disk "<<a.top()<<" from destination to auxiliary"<<endl;
            }
            i++;
        }
    }
    cout << "Position after all the operations : \n";
    while(d.isEmpty()!=true)
    {
        cout<<d.top()<<endl;
        d.pop();
    }
}

void hailstone(int num,int st, int *c)
{
    *c=*c+1;
    cout << num << " ";
    if (num==st)
    {
        return;
    }
    if (num%2==1)
    {
        hailstone(num*3+1,st,c);
    }
    else
    {
        hailstone(num/2,st,c);
    }
}

void q5()
{
    int num;
    st :
    cout << "Enter the number : ";
    cin >> num;
    if (num<=0)
    {
        cout << "Enter valid input!!!\n";
        goto st;
    }
    int c=0;
    hailstone(num,1,&c);
    cout << "\nThe length of the sequence is : " << c;
}

int main()
{
    int n;
    st:
    cout << endl;
    cout << "1. Sorting the element in the stack" << endl;
    cout << "2. Printing all the possible palindromic partitions of a string" << endl;
    cout << "3. Reversing a string using stack" << endl;
    cout << "4. Implementing Tower of Hanoi using stack" << endl;
    cout << "5. Finding the Hailstone Sequence of a given number up to 1" << endl;
    cout << "6. Quit" << endl;
    cout << "Enter your choice : ";
    cin >> n;
    switch (n)
    {
        case 1: q1();
                goto st;
        case 2: q2();
                goto st;
        case 3: q3();
                goto st;
        case 4: q4();
                goto st;
        case 5: q5();
                goto st;
        case 6: cout << "Thanks to join!!!\n";
                return 0;
        default:cout << "Please enter a valid choice!!\n";
                goto st;
    }
    return 0;
}

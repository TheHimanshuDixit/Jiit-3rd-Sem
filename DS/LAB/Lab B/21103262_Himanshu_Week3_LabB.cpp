#include<iostream>
#include<string>
#include<locale>

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
};

template<class X>
class Queue
{
public:
    struct Node
    {
        char data;
        Node* next=NULL;
    };
    Node* head=NULL;
    Node* rear=NULL;

    void enQueue(X value)
    {
        Node* new_node=new Node;
        new_node->data=value;
        if (head==NULL)
        {
            head=new_node;
            rear=new_node;
            return;
        }
        else
        {
            rear->next=new_node;
            rear=rear->next;
        }
    }
    void deQueue()
    {
        if (head==NULL)
        {
            cout << "Empty Queue!!\n";
            return;
        }
        else if (head==rear)
        {
            Node* temp=head;
            head=NULL;
            rear=NULL;
            delete temp;
            return;
        }
        else
        {
            Node* temp1=head;
            head=head->next;
            delete temp1;
        }
    }
    char fr()
    {
        return head->data;
    }
    char ba()
    {
        return rear->data;
    }
    void display()
    {
        Node* temp=head;
        if (head==NULL)
        {
            cout << "Empty Queue!!\n";
            return;
        }
        while (temp!=NULL)
        {
            cout << temp->data;
            temp=temp->next;
        }
        cout << endl;
    }
    bool isEmpty()
    {
        if (head==NULL)
            return true;
        else
            return false;
    }
    X front()
    {
        return head->data;
    }
    X back()
    {
        return rear->data;
    }

};

Queue<int> moveNthFront(Queue<int> Q,int n)
{
    Queue<int> temp1,temp2;
    for (int i=0;i<n-1;i++)
    {
        temp1.enQueue(Q.front());
        Q.deQueue();
    }
    temp2.enQueue(Q.front());
    Q.deQueue();
    for (int i=0;i<n-1;i++)
    {
        temp2.enQueue(temp1.front());
        temp1.deQueue();
    }
    while (!Q.isEmpty())
    {
        temp2.enQueue(Q.front());
        Q.deQueue();
    }
    return temp2;
}

Queue<char> upperToLower(Queue<char> Q)
{
    Queue<char> temp;
    while (!Q.isEmpty())
    {
        if (Q.front()>64 && Q.front()<91)
        {
            temp.enQueue(Q.front()+32);
        }
        else
        {
            temp.enQueue(Q.front());
        }
        Q.deQueue();
    }
    return temp;
}

Queue<char> stringToQueue(string s)
{
    Queue<char> temp;
    for (int i=0;i<s.length();i++)
    {
        temp.enQueue(s[i]);
    }
    return temp;
}

bool isPrime(int n)
{
    bool prime=false;
    for (int i=2;i<=n/2;i++)
    {
        if (n%i==0)
            return false;
    }
    return true;
}

bool isOperator(char x)
{
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	}
	return false;
}

int preced(char ch)
{
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    else
        return 0;
}

string postToPre(string exp)
{
    Stack<string> s;
    int l=exp.length();
    for (int i=0;i<l;i++)
    {
        if (isOperator(exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = exp[i] + op2 + op1;
            s.push(temp);
        }
        else
        {
            s.push(string(1,exp[i]));
        }
    }
    string ans = "";
    while (!s.isEmpty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}

string preToPost(string exp)
{
    Stack<string> s;
    int l=exp.length();
    for (int i=l-1;i>=0;i--)
    {
        if (isOperator(exp[i]))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + exp[i];
            s.push(temp);
        }
        else
        {
            s.push(string(1,exp[i]));
        }
    }
    string ans = "";
    while (!s.isEmpty())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}

string infToPost(string exp)
{
    Stack<char> stk;
    stk.push('#');
    string postfix = "";
    string::iterator it;

    for(it = exp.begin(); it!=exp.end(); it++)
    {
        if(isalnum(char(*it)))
            postfix += *it;
        else if(*it == '(')
            stk.push('(');
        else if(*it == '^')
            stk.push('^');
        else if(*it == ')')
        {
            while(stk.top() != '#' && stk.top() != '(')
            {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else
        {
            if(preced(*it) > preced(stk.top()))
                stk.push(*it);
            else
            {
                while(stk.top() != '#' && preced(*it) <= preced(stk.top()))
                {
                    postfix += stk.top();
                    stk.pop();
                }
                stk.push(*it);
            }
        }
    }
    while(stk.top() != '#')
    {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

int precedence(char op)
{
	if(op == '+'||op == '-')
        return 1;
	if(op == '*'||op == '/')
        return 2;
	return 0;
}

int applyOp(int a, int b, char op)
{
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

int evaluate(string tokens)
{
	int i;
    Stack <int> values;
    Stack <char> ops;
	for(i = 0; i < tokens.length(); i++)
    {
		if(tokens[i] == ' ')
			continue;
        else if(tokens[i] == '(')
			ops.push(tokens[i]);
		else if(isdigit(tokens[i]))
        {
			int val = 0;
			while(i < tokens.length() && isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			values.push(val);
			i--;
		}
		else if(tokens[i] == ')')
		{
			while(!ops.isEmpty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(applyOp(val1, val2, op));
			}
            if(!ops.isEmpty())
                ops.pop();
		}
		else
		{
			while(!ops.isEmpty() && precedence(ops.top()) >= precedence(tokens[i]))
            {
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(applyOp(val1, val2, op));
			}
            ops.push(tokens[i]);
		}
	}
	while(!ops.isEmpty())
    {
		int val2 = values.top();
		values.pop();

		int val1 = values.top();
		values.pop();

		char op = ops.top();
		ops.pop();

		values.push(applyOp(val1, val2, op));
	}
    return values.top();
}

void parta ()
{
   string post;
    cout << "Enter the postfix expression : ";
    cin >> post;
    string pre=postToPre(post);
    cout << "Prefix Expression : " << pre;
}

void partb ()
{
    string pre;
    cout << "Enter the prefix expression : ";
    cin >> pre;
    string post=preToPost(pre);
    cout << "Postfix Expression : " << post;
}

void partc ()
{
    string inf;
    cout << "Enter the Infix expression : ";
    cin >> inf;
    cout << "Postfix Expression : " << infToPost(inf) << endl;
    cout << inf << " = " << evaluate(inf);
}

char readNextSymbol(int *i,string s)
{
    char a;
    for (*i;*i<s.length();*i=*i+1)
    {
        if (s[*i]=='/' && s[*i+1]=='*')
        {
            a = '/*';
            *i=*i+2;
            return a;
        }
        else if (s[*i]=='*' && s[*i+1]=='/')
        {
            a = '*/';
            *i=*i+2;
            return a;
        }
        else if (s[*i]=='(' || s[*i]==')' || s[*i]=='{' || s[*i]=='}' || s[*i]=='[' || s[*i]==']' || s[*i]=='/*' || s[*i]=='*/')
        {
            a=s[*i];
            *i=*i+1;
            return a;
        }
    }
    return NULL;
}

bool Check_Balance(string s)
{
    Stack<char> S ;
    int i=0;
    char sym = readNextSymbol(&i,s);
    while (sym!=NULL)
    {
        switch(sym)
        {
            case '/*':
            case '(':
            case '[':
            case '{':
                    S.push(sym);
                    break;
            case '*/':
                    if (S.top()=='/*')
                        S.pop();
                    else
                        return false;
                    break;
            case ')':
                    if (S.top()=='(')
                        S.pop();
                    else
                        return false;
                    break;
            case ']':
                    if (S.top()=='[')
                        S.pop();
                    else
                        return false;
                    break;
            case '}':
                    if (S.top()=='(')
                        S.pop();
                    else
                        return false;
                    break;
        }
        sym = readNextSymbol(&i,s);
    }
    if ( S.isEmpty() )
        return true;
    else
        return false;
}

Queue<char> removeSpaces(Queue<char> Q)
{
    Queue<char> temp;
    while (!Q.isEmpty())
    {
        if (Q.fr()!=' ')
            temp.enQueue(Q.fr());
        Q.deQueue();
    }
    return temp;
}


Queue<char> ques(Queue<char> Q)
{
    Queue<char> temp;
    while (!Q.isEmpty())
    {
        temp.enQueue(Q.fr());
        Q.deQueue();
        int count=1;
        while (!Q.isEmpty() && (Q.fr()==temp.ba()))
        {
            count++;
            Q.deQueue();
        }
        if (count>1)
        {
            char ch=count+48;
            temp.enQueue(ch);
        }
    }
    return temp;
}

string Reverse(string s)
{
    string temp;
    Stack<char> S;
    for (int i=0;i<s.length();i++)
    {
        S.push(s[i]);
    }
    while (!S.isEmpty())
    {
        temp+=S.top();
        S.pop();
    }
    return temp;
}

bool searchChar(string s,char c,int i, int f)
{
    bool found=false;
    for (int st=i;st<f;st++)
    {
        if (s[st]==c)
        {
            found=true;
            break;
        }
    }
    return found;
}

string common(string s1, string s2)
{
    bool found=false;
    string s3;
    for (int i=0;i<s1.length();i++)
    {
        for (int j=0;j<s2.length();j++)
        {
            if (s1[i]==s2[j])
            {
                i++;
                j++;
                while (s1[i]==s2[j] && i<s1.length()-1 && j<s2.length()-1)
                {
                    found=true;
                    s3+=s1[i];
                    i++;
                    j++;
                }
            }
        }
        if (found==true)
            break;
    }
    return s3;
}

void q2()
{
    int n;
    Stack<int> factor;
    st :
    cout << "Enter the number : ";
    cin >> n;
    if (n<=1)
    {
        cout << "Enter valid input !!\n";
        goto st;
    }
    for (int i=2;i<=n;i++)
    {
        if (n%i==0 && isPrime(i))
            factor.push(i);
    }
    cout << "Prime Factors in descending order : ";
    while (!factor.isEmpty())
    {
        cout << factor.top() << " ";
        factor.pop();
    }
}

void q3()
{
    Stack<int> stack1,stack2,stack3;
    int n,data;
    st:
    cout << "Enter the no. of elements in stack : ";
    cin >> n;
    if (n<=0)
    {
        cout << "Enter valid input!!!\n";
        goto st;
    }
    for (int i=1;i<=n;i++)
    {
        cout << "Enter element " << i << " : ";
        cin >> data;
        stack1.push(data);
    }
    for (int i=1;i<=n/2;i++)
    {
        stack3.push(stack1.top());
        stack1.pop();
    }
    while (!stack1.isEmpty())
    {
        stack2.push(stack1.top());
        stack1.pop();
    }

    for (int i=1;i<=n/2;i++)
    {
        stack2.push(stack3.top());
        stack3.pop();
    }
    while (!stack2.isEmpty())
    {
        cout << stack2.top() << " ";
        stack2.pop();
    }

}

void q4()
{
    Stack<int> conv;
    int n, no;
    cout << "Enter the number in decimal notation : ";
    cin >> n;
    st:
    cout << "Enter the notation to convert the number (2-9): ";
    cin >> no;
    if (no<2 && no>9)
    {
        cout << "Enter the valid input!!!\n";
        goto st;
    }
    int temp=n;
    while (temp!=0)
    {
        conv.push(temp%no);
        temp=temp/no;
    }
    cout << n << " on conversion from decimal to number system with base " << no << " : ";
    while (!conv.isEmpty())
    {
        cout << conv.top();
        conv.pop();
    }
}

void q5()
{
    int ch;
    cout << "(a). Postfix to Prefix\n (b). Prefix to Postfix\n (c). Infix to Postfix and evaluation of the expression\n";
    st:
    cout << "Enter your choice : ";
    cin >> ch;
    switch (ch)
    {
        case 1: parta();
                break;
        case 2: partb();
                break;
        case 3: partc();
                break;
        default:cout << "Enter valid input!!!\n";
                goto st;
    }

}

void q6()
{
    string s="/*(())*/";
    if (Check_Balance(s))
        cout << "Balanced";
    else
        cout << "Unbalanced";

}

void q7()
{
    Queue <char> Q,temp;
    string s;
    cout << "Enter the string : ";
    cin >> s;
    for (int i=0;i<s.length();i++)
    {
        Q.enQueue(s[i]);
    }
    Q=removeSpaces(Q);
    Q=ques(Q);
    cout << "Required string : ";
    Q.display();
}

void q8()
{
    int n,temp;
    Queue<int> Q;
    cout << "Enter the no. of elements in the queue : ";
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cout << "Enter element " << i << " : ";
        cin >> temp;
        Q.enQueue(temp);
    }
    cout << "Enter the position to move to the front : ";
    cin >> temp;
    Q=moveNthFront(Q,temp);
    cout << "After moving, the elements in the Queue : ";
    Q.display();
}

void q9()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;
    Queue<char> part_a=stringToQueue(s);
    part_a=upperToLower(part_a);
    Queue<char> part_b=stringToQueue(Reverse(s));
    part_b=upperToLower(part_b);
    bool palin=true;
    while (!part_a.isEmpty() && !part_b.isEmpty())
    {
        if (part_a.front()!=part_b.front())
        {
            palin=false;
            break;
        }
        part_a.deQueue();
        part_b.deQueue();
    }
    if (palin)
    {
        cout << s << " is a palindrome." << endl;
    }
    else
        cout << s << " is not a palindrome." << endl;
}

void q10()
{
    int i;
    string s,s1,s2,s3;
    cout << "Enter the string : ";
    cin >> s;
    for (i=0;i<s.length();i++)
    {
        if (s[i]=='X')
            break;
    }
    if (i!=s.length())
    {
        for (i;i<s.length();i++)
        {
            s1+=s[i];
            if (s[i]=='Y' && !searchChar(s,'Y',i+1,s.length()))
            {
                break;
            }
        }
    }
    s1=Reverse(s1);
    cout << "Required string : " << s1 << endl;
    for (i=0;i<s.length();i++)
    {
        if (s[i]=='Y')
            break;
    }
    if (i!=s.length())
    {
        for (i;i<s.length();i++)
        {
            s2+=s[i];
            if (s[i]=='X' && !searchChar(s,'X',i+1,s.length()))
            {
                break;
            }
        }
    }
    s2=Reverse(s2);
    cout << "Required string : " << s2 << endl;
    s3=common(s1,s2);
    cout << "Required string : " << s3;
}

void q1()
{
    cout << "x = 3\n y = 9\n 7\n 13\n 4\n 7\n";
}

int main()
{
    int ch;
    cout << "##########################Week 3 LAB A##########################################\n";
    st :
    cout << "\n\n";
    cout << "1. output of the q1\n";
    cout << "2. prime factors of a positive integer in descending order\n";
    cout << "3. split a stack into two stacks with one containing the bottom half elements and the second the remaining elements; and to combine two stacks into one by placing all elements of the second stack on top of those of the first stack\n";
    cout << "4. convert a number from decimal notation to a number expressed in a number system whose base (or radix) is a number between 2 and 9\n";
    cout << "5. to convert (a) given postfix to prefix (b) given prefix to postfix (c) given infix to postfix and further evaluate it to obtain the computed value.\n";
    cout << "6. check for balancing symbols in the following languages\n";
    cout << "7. compress a given text by removing whitespaces and replacing continuously repeated character by character followed by no. of time, it is repeated.\n";
    cout << "8. definition of the function moveNthFront that takes as a parameter a positive integer, n. The function moves the nth element of the queue to the front. The order of the remaining elements remains unchanged.\n";
    cout << "9. reads a line of text, changes each uppercase letter to lowercase, and places each letter both in a queue and onto a stack. The program should then verify whether the line of text is a palindrome\n";
    cout << "10. A String of characters is given. A scientist is interested in a very typical pattern. He wishes to reverse all the characters which lies inside 2 substrings namely S1, and S2. S1 is the string of any length but starts from X and ends with Y. S2, starts from Y and ends with X.\n";
    cout << "11. Quit\n";
    cout << "Enter your choice : ";
    cin >> ch;
    switch (ch)
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
        case 6: q6();
                goto st;
        case 7: q7();
                goto st;
        case 8: q8();
                goto st;
        case 9: q9();
                goto st;
        case 10: q10();
                goto st;
        case 11: cout << "Thanks to join\n";
                return 0;
        default:cout << "Invalid input!!\n";
                goto st;
    }
}


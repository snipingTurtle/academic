#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int n;

bool isEmpty(vector<int>& a)
{
    if(a.empty()) 
        return true;
    else 
        return false;
}

bool isFull(vector<int>& a)
{
    if(a.size() == n) 
        return true;
    else 
        return false;
}

void push(vector<int>& a, int i)
{
    if(a.size() < n) 
        a.push_back(i);
    else 
        cout << "Overflow\n";
}

void pop(vector<int>& a)
{
    if(a.size())
        a.pop_back();
    else   
        cout <<"Underflow\n";
}

int siz(vector<int>& a)
{
    return a.size();
}

int top(vector<int>&a)
{
    return a[a.size() - 1];
}

int main()
{
    int i, j, k, l, t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> a;
        for(i = 0; ; i++)
        {
            char c;
            cin >> c;
            if(c == '/') 
                break;
            if(c == '+')
                cin>>k;
            if(c == '-')
                pop(a);
            if(c == '+')
                push(a,k);
            cout << "size: " << siz(a);
            cout << "\nStack elements: ";
            for(j = 0; j < a.size(); j++) 
                cout << a[j] << " ";
            cout << "\n";
            cout << "top element: ";
            if(a.size()) 
                cout<<top(a);
            cout << "\n";
            cout << "isFull: ";
            if(isFull(a) == true) 
                cout << "True\n";
            else 
                cout << "False\n";
            cout << "isEmpty: ";
            if(isEmpty(a) == true) 
                cout << "True\n";
            else 
                cout << "False\n";
        }
    }
}


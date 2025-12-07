#include<iostream>

using namespace std;

int tp = -1;

void push(int stack[], int x, int n);
void pop(int stack[]);
int isEmpty();
int isFull(int n);
int size();
int top(int stack[]);
void print_stack(int stack[]);


int main()
{
    int n;
    cin>>n;

    int stack[n];

    while(1)
    {
        int id;
        cin>>id;

        if(id == -1) break;

        if(id == 1)
        {
            int x;
            cin>>x;

            push(stack, x, n);
        }

        else if(id == 2)
        {
            pop(stack);
        }
        else if(id == 3)
        {
            if(isEmpty()) cout<<"True\n";
            else cout<<"False\n";
        }
        else if(id == 4)
        {
            if(isFull(n)) cout<<"True\n";
            else cout<<"False\n";
        }
        else if(id == 5)
        {
            cout<<size()<<"\n";
        }
        else if(id == 6)
        {
            cout<<top(stack)<<"\n";
        }
    }
}

void print_stack(int stack[])
{
    for(int i = 0; i <= tp; i++) cout<<stack[i]<<" ";
    cout<<"\n";
}

void push(int stack[], int x, int n)
{
    if(isFull(n)) cout<<"Overflow\n";
    else
    {
        tp++;
        stack[tp] = x;
        print_stack(stack);
    }
}

void pop(int stack[])
{
    if(isEmpty()) cout<<"Underflow\n";
    else
    {
        tp--;
        print_stack(stack);
    }
}

int isEmpty()
{
    if(tp == -1) return 1;
    else return 0;
}

int isFull(int n)
{
    if((tp + 1) == n) return 1;
    else return 0;
}

int size()
{
    return tp + 1;
}

int top(int stack[])
{
    return stack[tp];
}
#include<iostream>

using namespace std;

float load_factor(int &cnt, int n)
{
    return ((cnt * 1.0) / (n * 1.0));
}

int hash1(int i, int table_size)
{
    return (i % table_size);
}

int hash2(int i)
{
    int r = 7;
    return (r - (i % r));
}

void linear_probing(int arr[], int val, int n, int &cnt)
{
    int i = hash1(val, n);
    // cout << i << " hash value" << endl;

    int check = 1;

    for(int j = 0; j < 6; j++)
    {
        if(arr[i] == -1)
        {
            check = 0;
            cnt++;
            arr[i] = val;
            cout << "Inserted : Index-" << i << " (L.F=" << load_factor(cnt, n) << ")\n";
            break;
        }
        cout << "Collision: Index-" << i << endl;

        i = hash1(i + 1, n);
    }

    if(check)
    {
        cout << "Input Abandoned" << endl;
    }
}

void quadratic_probing(int arr[], int val, int n, int &cnt)
{
    int i = hash1(val, n);
    int x = i;

    int check = 1;

    for(int j = 1; j <= 6; j++)
    {
        if(arr[i] == -1)
        {
            check = 0;
            cnt++;
            arr[i] = val;
            cout << "Inserted : Index-" << i << " (L.F=" << load_factor(cnt, n) << ")\n";
            break;
        }
        cout << "Collision: Index-" << i << endl;

        i = hash1(x + (j * j), n);
    }

    if(check)
    {
        cout << "Input Abandoned" << endl;
    }
}

void double_hashing(int arr[], int val, int n, int &cnt)
{
    int i = hash1(val, n);
    int x = i;

    int check = 1;

    for(int j = 1; j <= 6; j++)
    {
        if(arr[i] == -1)
        {
            check = 0;
            cnt++;
            arr[i] = val;
            cout << "Inserted : Index-" << i << " (L.F=" << load_factor(cnt, n) << ")\n";
            break;
        }
        cout << "Collision: Index-" << i << endl;

        i = hash1(x + (j * hash2(val)), n);
    }

    if(check)
    {
        cout << "Input Abandoned" << endl;
    }
}

int main()
{
    int choice, n, q;
    cin >> choice >> n >> q;

    int ht[n];

    for(int i = 0; i < n; i++) ht[i] = -1;

    int cnt = 0;

    while(q--)
    {
        int x;
        cin >> x;

        if(choice == 1)
        {
            linear_probing(ht, x, n, cnt);
        }
        else if(choice == 2)
        {
            quadratic_probing(ht, x, n, cnt);
        }
        else if(choice == 3)
        {
            double_hashing(ht, x, n, cnt);
        }
    }
}

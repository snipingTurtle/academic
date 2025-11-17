#include<iostream>

using namespace std;

int main()
{
    string a, b;
    cin>>a>>b;

    int bul = 0;
    int cow = 0;

    int freq[10] = {0};

    for(int i = 0; i < (int)a.size(); i++)
    {
        if(a[i] == b[i]) bul++;
        else
        {
            if(freq[a[i] - '0']) 
            {
                cow++;
                freq[a[i] - '0']--;
            }
            else freq[a[i] - '0']++;

            if(freq[b[i] - '0']) 
            {
                cow++;
                freq[b[i] - '0']--;
            }
            else freq[b[i] - '0']++;
        }
    }

    cout<<bul<<"B"<<cow<<"C"<<endl;
}
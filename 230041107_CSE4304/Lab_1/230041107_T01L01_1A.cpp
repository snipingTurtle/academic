#include<iostream>

using namespace std;

int main()
{
    int stor[10] = {0};
    int mx = 0;
    while(1)
    {
        int x;
        cin>>x;

        if(x <= 0) break;
        stor[x]++;
        if(stor[x] > mx)
        {
            mx = stor[x];
        }
    }

    while(1)
    {
        if(mx == 0) break;
        int temp = 0;
        if(mx == 1)
        {
            for(int i = 1; i <= 9; i++)
            {
                if(stor[i] == mx) cout<<i<<" occurs 1 time\n";
            }
            mx = 0;
            break;
        }
        else
        {
            for(int i = 1; i <= 9; i++)
            {
                if(stor[i] == mx) cout<<i<<" occurs "<<mx<<" times\n";
                else if((stor[i] > temp) && (stor[i] < mx)) temp = stor[i];
            }
            mx = temp;
        }
    }
}

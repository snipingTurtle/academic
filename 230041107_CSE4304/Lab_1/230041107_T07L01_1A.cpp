#include<iostream>

using namespace std;

int main()
{
    int freq[10] = {0};

    string s;
    cin>>s;

    string res = "";

    for(int i = 0; i < (int)s.size(); i += 2) freq[s[i] - '0']++;

    for(int i = 0; i < 10; i++)
    {
        while(freq[i]--) res = res + to_string(i) + "+";
    }
    for(int i = 0; i < (int)res.size() - 1; i++) cout<<res[i];
    cout<<"\n";
}
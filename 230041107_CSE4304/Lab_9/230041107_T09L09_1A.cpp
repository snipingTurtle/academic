#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{   
    string line;
    getline(cin, line);

    int sz;
    sz = line.size();

    unordered_map<string, int> um;

    string s = "";

    for(int i = 0; i < sz; i++)
    {
        if(isalpha(line[i]))
        {
            s.push_back(line[i]);
        }
        else
        {
            if((s != " ") && (s != ""))
            {
                um[s]++;
            }
            s = "";
        }
    }

    if((s != " ") && (s != ""))
    {
        um[s]++;
    }

    for(auto &x:um) 
    {
        if(x.second > 1) cout << x.first << " " << x.second << endl; 
    }
}
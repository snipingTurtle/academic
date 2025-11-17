#include<iostream>

using namespace std;

int main()
{
    string test = "dub";

    int n;
    cin>>n;

    string s;
    cin>>s;

    string res = "";
    string temp = "";

    for(int i = 0; i < n; i++)
    {
        if(s[i] == test[(int)temp.size()])
        {
            temp += s[i];
            if(temp == test)
            {
                temp = "";
                res += " ";
            }
        }
        else
        {
            res += temp;
            temp = "";
            if(s[i] == test[0])
            {
                temp += s[i];
            }
            else
            {
                res += s[i];
            }
        }
    }

    res += temp;
    bool sw = false;

    for(int i = 0; i < (int)res.size(); i++)
    {
        if(res[i] != ' ')
        {
            sw = true;
        }
        if(sw) cout<<res[i];
    }
    cout<<"\n";
}
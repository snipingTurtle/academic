#include<iostream> 
#include<stack> 

using namespace std;

int main()
{
    int n;
    cin >> n;

    cin.ignore();

    stack<char> s;
    int err = 0;

    for(int i = 1; i <= n; i++)
    {
        string line;
        getline(cin, line);

        if(err) continue;

        for(int j = 0; j < (int)line.size(); j++)
        {
            if((line[j] == '(') || (line[j] == '{') || (line[j] == '[')) s.push(line[j]);
            else if((line[j] == ')') || (line[j] == '}') || (line[j] == ']')) 
            {
                if(s.empty())
                {
                    cout << "Error" << endl;
                    err = 1;
                }
                else if(line[j] == ')')
                {
                    if(s.top() != '(') 
                    {
                        cout << "Error" << endl;
                        err = 1;
                    }
                }
                else if(line[j] == '}')
                {
                    if(s.top() != '{') 
                    {
                        cout << "Error" << endl;
                        err = 1;
                    }
                }
                else if(line[j] == ']')
                {
                    if(s.top() != '[') 
                    {
                        cout << "Error" << endl;
                        err = 1;
                    }
                }
                if(err) break;
                else s.pop();
            }
        }
    }

    if(!err) 
    {
        if(s.empty()) cout << "No Errors." << endl;
        else cout << "Error" << endl;
    }
}
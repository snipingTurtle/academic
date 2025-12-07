#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    stack<string> st;
    int err = 0;

    for (int i = 1; i <= n; i++) {
        string line;
        getline(cin, line);

        int sw = 0;
        string tag = "";
        if(err) continue;
        for(int j = 0; j < (int)line.size(); j++)
        {
            if(line[j] == '<') sw = 1;
            if(sw)
            {
                tag.push_back(line[j]);
            }
            if((line[j] == '>') && sw)
            {
                sw = 0;
                if(tag[1] == '/')
                {
                    tag = tag.substr(2, ((int)tag.size() - 3));
                    if(st.empty() || (st.top() != tag))
                    {
                        // if(st.empty()) cout << "Empty stack\n";
                        // else cout << "top of the stack " << st.top() << endl;
                        cout<<"Error at line "<< i << endl;
                        err = 1;
                        break;
                    }
                    else
                    {
                        tag = "";
                        st.pop();
                    }
                }
                else
                {
                    // cout << "Previous : " << tag << endl;
                    tag = tag.substr(1, ((int)tag.size() - 2));
                    // cout << "Modified : " << tag << endl;
                    st.push(tag);
                    tag = "";
                }
            }
        }
    }

    if(!st.empty() && !err) cout << "Error at line " << n << endl;
    else if(!err) cout << "No error" << endl;
    int dum;
    cin>>dum;
    if(dum == -1) return 0;
}
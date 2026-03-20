#include<iostream>
#include<unordered_map>

using namespace std;

string transformation(string s)
{
    string res = "";
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        switch (s[i])
        {
        case 'a':
            res = res + ".-";
            break;

        case 'b':
            res = res + "-...";
            break;

        case 'c':
            res = res + "-.-";
            break;

        case 'd':
            res = res + "-..";
            break;

        case 'e':
            res = res + ".";
            break;

        case 'f':
            res = res + "..-.";
            break;

        case 'g':
            res = res + "--.";
            break;

        case 'h':
            res = res + "....";
            break;

        case 'i':
            res = res + "..";
            break;

        case 'j':
            res = res + ".---";
            break;

        case 'k':
            res = res + "-.-";
            break;

        case 'l':
            res = res + ".-..";
            break;

        case 'm':
            res = res + "--";
            break;

        case 'n':
            res = res + "-.";
            break;

        case 'o':
            res = res + "---";
            break;

        case 'p':
            res = res + ".--.";
            break;

        case 'q':
            res = res + "--.-";
            break;

        case 'r':
            res = res + ".-.";
            break;

        case 's':
            res = res + "...";
            break;

        case 't':
            res = res + "-";
            break;

        case 'u':
            res = res + "..-";
            break;

        case 'v':
            res = res + "...-";
            break;

        case 'w':
            res = res + ".--";
            break;

        case 'x':
            res = res + "-..-";
            break;

        case 'y':
            res = res + "-.--";
            break;

        case 'z':
            res = res + "--..";
            break;
        
        default:
            break;
        }
    }

    return res;
}

int main()
{   
    int n;
    cin >> n;

    unordered_map<string, int> um;

    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        string temp = transformation(s);
        um[temp]++;
    }

    cout << um.size() << endl;
    for(auto &x:um) cout << x.first << endl;
}
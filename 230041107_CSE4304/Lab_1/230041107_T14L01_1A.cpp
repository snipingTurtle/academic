#include<iostream>

using namespace std; 

int main()
{
    int level, trial;

    cin>>level>>trial;

    int levels[level];
    string grades[101] = {""};

    for(int i = 0; i < level; i++)
    {
        cin>>levels[i];
        string temp;

        cin>>temp;
        grades[levels[i]] = temp;
    }

    int pos = 0;

    for(int i = 0; i < levels[0]; i++)
    {
        grades[i] = grades[levels[0]];
    }

    if(level < 2)
    {
        cout<<"Not Enough Levels"<<endl;
        return 0;
    }
    for(int i = levels[1] + 1; i <= 100; i++)
    {
        if(grades[i] == "")
        {
            grades[i] = grades[i - 1];
        }
    }

    while(trial--)
    {
        int x;
        cin>>x;

        cout<<grades[x]<<endl;
    }
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Meme
{
private:
    string memeName;
    int originYear, humorScore;
    bool isStillViral;

public:
    Meme() : memeName(""), originYear(2010), humorScore(50), isStillViral(false)
    {
    }

    Meme(const string &name, const int &origin, const int &score, const bool &viral) : memeName(name), originYear(2010), humorScore(50), isStillViral(viral)
    {
        set_originYear(origin);
        set_humorScore(score);
    }

    void set_memeName(const string &name)
    {
        memeName = name;
    }

    string get_memeName() const
    {
        return memeName;
    }

    void set_originYear(const int &origin)
    {
        if ((origin > 2025) || (origin < 2000))
        {
            originYear = 2010;
        }
        else
            originYear = origin;
    }

    int get_originYear() const
    {
        return originYear;
    }

    void set_humorScore(const int &score)
    {
        if ((score < 1) || (score > 100))
        {
            humorScore = 50;
        }
        else
            humorScore = score;
    }

    int get_humorScore() const
    {
        return humorScore;
    }

    void set_Viral(const bool &viral)
    {
        isStillViral = viral;
    }

    bool get_Viral() const
    {
        return isStillViral;
    }

    void set_meme(const string &name, const int &origin, const int &score, const bool &viral)
    {
        set_memeName(name);
        set_originYear(origin);
        set_humorScore(score);
        set_Viral(viral);
    }
};

void archiveMemes(Meme collection[], const int &sz)
{
    string name;
    int origin, score;
    bool viral;

    for (int i = 0; i < 5; i++)
    {
        cin >> name >> origin >> score >> viral;
        collection[i].set_meme(name, origin, score, viral);
    }

    int org = 2005 + (rand() % 11);
    int hum = 1 + (rand() % 100);

    for (int i = 5; i < sz; i++)
    {
        collection[i].set_meme("Lost Meme", org, hum, false);
    }
}

int main()
{
    srand(time(NULL));

    Meme collection[40];
    archiveMemes(collection, 40);

    for (int i = 0; i < 40; i++)
    {
        if ((collection[i].get_originYear() < 2010) && (collection[i].get_humorScore() > 70))
        {
            cout << collection[i].get_memeName() << endl;
        }
    }
}
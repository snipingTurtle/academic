#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class MenuItem
{
private:
    int id;
    string name;
    double price;

public:
    MenuItem() : id(0), name("NULL"), price(0)
    {
    }

    MenuItem(const int &i, const string &s, const double &p) : id(i), name(s), price(p)
    {
    }

    void setID(const int &i)
    {
        id = i;
    }

    void setName(const string &s)
    {
        name = s;
    }

    void setPrice(const double &p)
    {
        price = p;
    }

    int getID() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    string serialize() const
    {
        return getID() + "|" + getName() + "|" + to_string(getPrice());
        ;
    }

    static bool deserialize(const string &line, MenuItem &out)
    {
        string s = "";
        int sw = 0;
        for (int i = 0; i < (int)line.size(); i++)
        {
            if (line[i] == '|')
            {
                sw++;
                if (sw == 1)
                {
                    int idx = stoi(s);
                    out.setID(idx);
                    s = "";
                }
                else if (sw == 2)
                {
                    out.setName(s);
                    s = "";
                }
                else
                {
                    cout << "Error in deserialize" << endl;
                    return false;
                }
            }
            else
            {
                s.push_back(line[i]);
            }
        }
        out.setPrice(stod(s));
        return true;
    }

    void printRow(ostream &os) const
    {
        os << setw(7) << left << getID();
        os << "| ";
        os << setw(17) << left << getName();
        os << "| ";
        os << setw(6) << right << getPrice();
        os << " |";
    }

    static void printHeader(ostream &os)
    {
        os << setw(43) << setfill('-') << endl;
        os << "| MenuID | Item              |     Price |" << endl;
        os << setw(43) << setfill('-') << endl;
    }

    static void printFooter(ostream &os)
    {
        os << setw(43) << setfill('-') << endl;
    }

    ~MenuItem()
    {
    }
};

bool recordSale(const string &salesFile, int saleId, const MenuItem &mn, int units)
{
}

int loadMenu(const string &menuFile, MenuItem arr[], int maxCount)
{
}

int main()
{
    cout << setw(42) << setfill('-') << "" << endl;
    cout << "| MenuID | Item              |     Price |" << endl;
    cout << setw(42) << setfill('-') << "" << endl;
}
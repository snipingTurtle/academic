#include <iostream>
#include <cmath>

using namespace std;

class StockPortfolio

{
private:
    string ownerName;
    double totalValue;
    int riskVolatility, stockCount;

public:
    StockPortfolio() : ownerName("None"), totalValue(0), riskVolatility(1), stockCount(0)
    {
    }

    StockPortfolio(const string &name, const double &value, const int &risk, const int &cnt) : ownerName(name), totalValue(value), riskVolatility(1), stockCount(cnt)
    {
        set_risk(risk);
    }

    void set_name(const string &name)
    {
        ownerName = name;
    }

    string get_name() const
    {
        return ownerName;
    }

    void set_value(const double &value)
    {
        totalValue = value;
    }

    double get_value() const
    {
        return totalValue;
    }

    void set_risk(const int &risk)
    {
        riskVolatility = max(risk, 0);
        riskVolatility = min(risk, 10);
    }

    int get_risk() const
    {
        return riskVolatility;
    }

    void set_count(const int &cnt)
    {
        stockCount = cnt;
    }

    int get_count() const
    {
        return stockCount;
    }

    void set_stock(const string &name, const double &value, const int &risk, const int &cnt)
    {
        set_name(name);
        set_value(value);
        set_risk(risk);
        set_count(cnt);
    }

    double calculate() const
    {
        double num = (((riskVolatility * riskVolatility) * 1.0) * totalValue);
        double denom = log(stockCount + 1);
        double term1 = pow((num / denom), 0.6);

        num = (riskVolatility * 1.0) * sqrt(totalValue);
        denom = pow(stockCount, 0.3);
        double term2 = (num / denom);

        num = riskVolatility;
        denom = 1 + exp((-1 * totalValue) / (1e5));
        double term3 = 0.4 * (num / denom);

        return (term1 + term2 + term3);
    }

    StockPortfolio compareSafety(const StockPortfolio &st) const
    {
        double score1 = calculate();
        double score2 = st.calculate();

        if (score2 < score1)
            return st;
        else
            return *this;
    }

    void display_status() const
    {
        cout << "Owner: " << ownerName << "\nTotal Value: " << totalValue << "\nRisk Volatility: " << riskVolatility << "\nStock Count: " << stockCount << endl;
        cout << endl;
    }
};

int main()
{
    StockPortfolio arr[5];

    arr[0].set_stock("hello", 43.1, 3, 123);
    arr[1].set_stock("help", 54.21, 8, 12);
    arr[2].set_stock("hello", 34.65, 9, 643);
    arr[3].set_stock("ello", 13.1, 1, 13);
    arr[4].set_stock("whello", 47.1, 5, 23);

    StockPortfolio safer = arr[0];

    for (int i = 1; i < 5; i++)
    {
        safer = safer.compareSafety(arr[i]);
    }

    safer.display_status();
}
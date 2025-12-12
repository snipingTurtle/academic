#include <iostream>

using namespace std;

class CyberImplant
{
private:
    string modelName, bodyPart;
    int powerConsumption;
    double firmwareVersion;

public:
    CyberImplant() : modelName("None"), bodyPart("Auxiliary"), powerConsumption(1000), firmwareVersion(1.0)
    {
    }

    CyberImplant(const string &name, const string &part, const int &power, const double &version) : modelName(name), bodyPart("Auxiliary"), powerConsumption(1000), firmwareVersion(version)
    {
        set_bodyPart(part);
        set_powerConsumption(power);
    }

    void set_modelName(const string &name)
    {
        modelName = name;
    }

    string get_modelName() const
    {
        return modelName;
    }

    void set_bodyPart(const string &part)
    {
        if ((part != "Arm") && (part != "Leg") && (part != "Eye") && (part != "Heart"))
        {
            bodyPart = "Auxiliary";
        }
        else
            bodyPart = part;
    }

    string get_bodyPart() const
    {
        return bodyPart;
    }

    void set_powerConsumption(const int &power)
    {
        if (power <= 0)
            cout << "Power Consumption Must be Positive" << endl;
        else
        {
            powerConsumption = min(power, 1000);
        }
    }

    int get_powerConsumption() const
    {
        return powerConsumption;
    }

    void set_firmwareVersion(const double &version)
    {
        firmwareVersion = version;
    }

    double get_firmwareVersion() const

    {
        return firmwareVersion;
    }

    void set_cyberImplant(const string &name, const string &part, const int &power, const double &version)
    {
        set_modelName(name);
        set_bodyPart(part);
        set_powerConsumption(power);
        set_firmwareVersion(version);
    }

    void display_status() const
    {
        cout << "Name: " << modelName << "\nBody Part: " << bodyPart
             << "\nPower Consumption: " << powerConsumption << "\nFirmware Version: " << firmwareVersion << endl;
        cout << endl;
    }
};

void upgradeFirmware(CyberImplant &implant)
{
    implant.set_firmwareVersion(implant.get_firmwareVersion() + 0.1);
    implant.set_powerConsumption(implant.get_powerConsumption() - 5);
}

int main()
{
    CyberImplant coll[5];
    coll[0].set_cyberImplant("hell", "Arm", 345, 3.9);
    coll[1].set_cyberImplant("whell", "Leg", 945, 0.9);
    coll[2].set_cyberImplant("fhell", "Heart", 35, 13.9);
    coll[3].set_cyberImplant("hdwell", "Eye", 341, 3.29);
    coll[4].set_cyberImplant("bhell", "Army", 45, 3);

    for (int i = 0; i < 5; i++)
    {
        coll[i].display_status();
    }

    for (int i = 0; i < 5; i++)
    {
        upgradeFirmware(coll[i]);
        coll[i].display_status();
    }
}
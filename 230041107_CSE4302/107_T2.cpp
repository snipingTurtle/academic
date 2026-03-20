#include <iostream>

using namespace std;

class VehicleUnit
{
private:
    int maxSpeed;
    float fuelLevel;

public:
    VehicleUnit() : maxSpeed(20), fuelLevel(30)
    {
    }

    VehicleUnit(const int &speed, const float &fuel) : maxSpeed(speed), fuelLevel(fuel)
    {
    }

    int get_maxSpeed() const
    {
        return maxSpeed;
    }

    float get_fuelLevel() const
    {
        return fuelLevel;
    }

    void set_maxSpeed(const int &speed)
    {
        maxSpeed = speed;
    }

    void set_fuelLevel(const float &fuel)
    {
        fuelLevel = fuel;
    }

    void move()
    {
        set_fuelLevel(fuelLevel - 1);
        displayStatus();
    }

    void displayStatus() const
    {
        cout << "Moving at speed " << maxSpeed << ". Fuel remaining: " << fuelLevel << "." << endl;
    }

    ~VehicleUnit()
    {
        cout << "Vehicle going dark." << endl;
    }
};

class CameraUnit
{
private:
    bool nightVisionMode;
    int storageCapacity;

public:
    CameraUnit() : nightVisionMode(false), storageCapacity(100)
    {
    }

    CameraUnit(const bool &v, const int &s) : nightVisionMode(v), storageCapacity(s)
    {
    }

    bool get_nightVisionMode() const
    {
        return nightVisionMode;
    }

    int get_storageCapacity() const
    {
        return storageCapacity;
    }

    void set_nightVisionMode(const bool &b)
    {
        nightVisionMode = b;
    }

    void set_storageCapacity(const int &storage)
    {
        storageCapacity = storage;
    }

    void recordFootage()
    {
        storageCapacity--;
        displayStatus();
    }

    void displayStatus() const
    {
        cout << "Recording… Night vision is ";
        if (nightVisionMode)
            cout << "ON";
        else
            cout << "OFF";
        cout << ". Storage remaining: " << storageCapacity << " GB." << endl;
    }

    ~CameraUnit()
    {
        cout << "Camera going dark." << endl;
    }
};

class WeaponArm
{
private:
    int ammoCount, damage;

public:
    WeaponArm() : ammoCount(0), damage(0)
    {
    }

    WeaponArm(const int &ammo, const int &dam) : ammoCount(ammo), damage(dam)
    {
    }

    int get_ammoCount() const
    {
        return ammoCount;
    }

    void set_ammoCount(const int &ammo)
    {
        ammoCount = ammo;
    }

    int get_damage() const
    {
        return damage;
    }

    void set_damage(const int &dam)
    {
        damage = dam;
    }

    void fire()
    {
        if (ammoCount > 0)
        {
            ammoCount--;
            cout << "Bang! Dealt " << damage << " damage." << endl;
        }
        else
        {
            cout << "Click… Out of ammo." << endl;
        }
    }

    void reload(const int &amount)
    {
        ammoCount += amount;
    }

    void displayStatus() const
    {
        cout << "Ammo Count: " << ammoCount << ". Damage: " << damage << "." << endl;
    }

    ~WeaponArm()
    {
        cout << "Weapon going dark." << endl;
    }
};

class PatrolBot : public VehicleUnit, public CameraUnit
{
private:
    string modelNumber;
    WeaponArm weapon;

public:
    PatrolBot() : VehicleUnit(), CameraUnit(), modelNumber("000"), weapon(0, 0)
    {
    }

    PatrolBot(const int &speed, const float &fuel, const bool &v, const int &s, const string &model, const int &ammo, const int &dam) : VehicleUnit(speed, fuel), CameraUnit(v, s), modelNumber(model), weapon(ammo, dam)
    {
    }

    void patrolArea()
    {
        move();
        recordFootage();
    }

    void engageTarget()
    {
        weapon.fire();
    }

    void statusReport()
    {
        VehicleUnit::displayStatus();
        CameraUnit::displayStatus();
        weapon.displayStatus();
    }

    int get_ammo() const
    {
        return weapon.get_ammoCount();
    }

    void reload()
    {
        weapon.reload(10);
    }

    ~PatrolBot()
    {
        cout << modelNumber << " going dark." << endl;
    }
};

int main()
{
    PatrolBot p(100, 30, true, 10, "003", 10, 40);
    p.patrolArea();
    while (p.get_ammo() > 0)
    {
        p.engageTarget();
    }
    p.reload();
}

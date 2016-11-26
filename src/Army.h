#include <string>
#include <memory>


struct STATS 
{
	int health;
	int armour;
};

class Army
{
public:
    Army(std::string const& armyName, int armySize);
    Army(std::string const& armyName);
    ~Army();


public:
    inline void setArmySize(int armySize) { m_armySize = armySize;};
    inline bool isArmyDead() const { return m_armySize <= 0;};

private:
    std::string m_armyName;
    int m_armySize;

    STATS m_armyStats;
};
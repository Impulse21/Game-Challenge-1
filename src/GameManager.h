#include "Army.h"

class GameManager
{
public:
    GameManager(Army const& armyOne, Army const& armyTwo);
    ~GameManager();

    void Run();

private:
    Army m_armyOne;
    Army m_armyTwo;
};
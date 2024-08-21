#include "CPlayer.h"
#include "CStory.h"

//EQUIP FUNCTION IS NOT COMPLETED

int CPlayer::getSanity() const
{
    return sanity;
}

void CPlayer::setSanity(int s)
{
    sanity = s;
}

int CPlayer::getAttack() const
{
    return attack;
}

void CPlayer::setAttack(int a)
{
    attack = a;
}

void CPlayer::updateAttack(int a)
{
    attack += a;
}

bool CPlayer::playerAttacking(CGameObject* target)
{
    int targetPos = target->getObjPos();
    if (targetPos == getObjPos())
    {
        std::cout << "player hits enemy" << std::endl;
        return true;
    }
    return false;

}

void CPlayer::depleteSanity()
{
    setSanity(getSanity() - 20);
}

void CPlayer::moveToLiving()
{
    setObjPos(1);
}

void CPlayer::moveToKitchen()
{
    setObjPos(2);
}

void CPlayer::moveToMB()
{
    setObjPos(3);
}

void CPlayer::moveToBase()
{
    setObjPos(0);
}

void CPlayer::moveToExit()
{
    setObjPos(4);
}

void CPlayer::unequip()
{
    delete weaponInHand;
    weaponInHand = nullptr;
    std::cout << "equip pointer for weapon deleted" << std::endl;

    delete keyInHand;
    keyInHand = nullptr;
    std::cout << "equip pointer for key deleted" << std::endl;
}

void CPlayer::equip(CWeapon* weaponEquipped)
{
    if (weaponEquipped->getObjPos() == getObjPos())
    {
        if (!(weaponInHand == nullptr))
        {
            delete weaponInHand;
        }
        weaponInHand = weaponEquipped;
    }
    else
    {
        std::cout << "There is no weapon here." << std::endl;
    }
    
}

bool CPlayer::isEquipped()
{
    if (!(weaponInHand == nullptr))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void CPlayer::useWeapon(CEnemy* badGuy)
{
    if (badGuy->getObjPos() == getObjPos())
    {
        if (!(weaponInHand == nullptr))
        {
            badGuy->setENHP(badGuy->getENHP() - weaponInHand->getWeaponATK());
        }
        else
        {
            std::cout << "I have no weapon right now." << std::endl;
        }
    }
    else
    {
        if (!(weaponInHand == nullptr))
        {
            std::cout << "No enemies nearby." << std::endl;
        }
        else
        {
            std::cout << "No enemies nearby." << std::endl;
            std::cout << "I have no weapon right now." << std::endl;
        }

    }

}

void CPlayer::equip2(CKey* keyEquipped)
{
    if (keyEquipped->getObjPos() == getObjPos())
    {
        if (!(keyInHand == nullptr))
        {
            delete keyInHand;
        }
        keyInHand = keyEquipped;
    }
    else
    {
        std::cout << "There is no key here." << std::endl;
    }
}

bool CPlayer::isEquipped2()
{
    if (!(keyInHand == nullptr))
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}

void CPlayer::useKey(CKey* keyEquipped)
{
    keyInHand = nullptr;
    delete keyEquipped;
    keyEquipped = nullptr;
}


void CPlayer::StartStealth(CStory* storyEvent)
{
    using namespace std::chrono;
    bool timeExpired = false;
    bool held = false;
    float timeheld = 0.0;
    std::chrono::steady_clock::time_point pressStart;
    bool spacePressed = false;

    while (true) {
        // Check if the spacebar is pressed
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            if (!spacePressed)
            {
                // Spacebar was just pressed
                spacePressed = true;
                held = true;
                pressStart = steady_clock::now();
            }

            auto now = steady_clock::now();
            auto elapsed = duration_cast<seconds>(now - pressStart).count();
            timeheld = static_cast<int>(elapsed);

            if (elapsed >= 2) 
            {
                storyEvent->hideSuccess();
                
                held = false; // reset after successful avoidance
                break; // Exit the loop after handling the event
            }
        }
        else {
            // Spacebar is not pressed
            if (spacePressed) {
                // Spacebar was released
                spacePressed = false;
                // Handle case where spacebar was released too early
                held = false;
                
                storyEvent->hideFailure();

                break; // Exit the loop after handling the event
            }
        }

        std::this_thread::sleep_for(milliseconds(100));
    }
}









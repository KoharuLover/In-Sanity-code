#include "HuiEnIT.h"

int HuiEnIT::potion()
{
    return potioncount++;
}

int HuiEnIT::key()
{
    return keycount++;
}

bool HuiEnIT::keystate()
{
    return !keyfound;
}

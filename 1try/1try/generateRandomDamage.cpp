#include "generateRandomDamage.h"
#include <cstdlib>

int generateRandomDamage(int minDamage, int maxDamage) {
    return minDamage + rand() % (maxDamage - minDamage + 1);
}

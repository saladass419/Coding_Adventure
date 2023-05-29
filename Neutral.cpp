#include "memtrace.h"
#include "Neutral.h"

bool Neutral::isAlwaysAdjacent = false;

bool Neutral::isNeighbour(int a, int b){
    if (a == b) return false;
    if(Neutral::isAlwaysAdjacent) return true;

    int xa = a / 5;
    int ya = a % 5;
    int xb = b / 5;
    int yb = b % 5;

    if (xa < 0 || xa>4 || ya < 0 || ya>4 || xb < 0 || xb>4 || yb < 0 || yb>4) return false;
    if (ya == yb) {
        if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
    }
    if (ya == yb+1) {
        if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
    }
    if (ya == yb-1) {
        if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
    }
    return false;
}
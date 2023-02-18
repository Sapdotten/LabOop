#include <character/character.h>

int pow_stub(int num, int pow) {
    int answ = num;
    for (int i = 1; i < pow; i++) {
        answ *= num;
    }
    return answ;
}

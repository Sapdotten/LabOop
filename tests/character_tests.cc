#include <gtest/gtest.h>
#include <character/character.h>
#include <character/container.h>
#include <iostream>
using namespace std;

//TEST(CharacterTests, characterTest0) {
//    Character Pers1(CharacterType::berserk);
//    Character Pers2(CharacterType::assasin);
//    Character Pers3(CharacterType::knight);
//    Pers1.SetChance(0);
//    Pers2.SetChance(0);
//    Pers3.SetChance(0);
//    int r1 = Pers1.Action(2, Pers2);
//    int r2 = Pers2.Action(2, Pers3);
//    int r3 = Pers1.Action(2, Pers1);
//    EXPECT_EQ(r1, -1);
//    EXPECT_EQ(r2, -1);
//    EXPECT_EQ(r3, -1);
//}


TEST(CharacterTests, characterTest2) {//berserk vs everybody
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::assasin);
    Character Assasin(CharacterType::assasin);
    Berserk.SetChance(0);
    Knight.SetChance(0);
    int bk = Berserk.Action(1, Knight);
    int ba = Berserk.Action(1, Assasin);
    Knight.SetChance(1);
    int bK = Berserk.Action(1, Knight);
    Berserk.SetChance(1);
    int BK = Berserk.Action(1, Knight);
    int Ba = Berserk.Action(1, Assasin);
    EXPECT_EQ(bk, -1);
    EXPECT_EQ(ba, -1);
    EXPECT_EQ(bK, -1);
    EXPECT_EQ(BK, -1);
    EXPECT_EQ(Ba, -1);
}




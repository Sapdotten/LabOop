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

TEST(CharacterTests, characterTest1) {//berserk vs assain
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Berserk.SetChance(1);
    Assasin.SetChance(0);
    int r1 = Berserk.Action(1, Assasin);
    int r2 = Berserk.Action(2, Assasin);
    int r3 = Assasin.Action(1, Berserk);
    EXPECT_EQ(r1, 400);
    EXPECT_EQ(Assasin.GetHP(), 800);
    EXPECT_EQ(r2, -1);
    EXPECT_EQ(r3, 90);
}

TEST(CharacterTests, characterTest2) {//berserk vs knight
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::assasin);
    Berserk.SetChance(1);
    Knight.SetChance(0);
    int r1 = Berserk.Action(2, Knight);
    int r2 = Knight.Action(2, Berserk);
    EXPECT_EQ(r1, -1);
    EXPECT_EQ(r2, -1);
}



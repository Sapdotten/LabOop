#include <gtest/gtest.h>
#include <character/character.h>

TEST(CharacterTests, characterTest0) {
    Character Pers1(CharacterType::berserk);
    Character Pers2(CharacterType::assasin);
    Character Pers3(CharacterType::knight);
    Pers1.SetChance(0);
    Pers2.SetChance(0);
    Pers3.SetChance(0);
    int r1 = Pers1.Action(2, Pers2);
    int r2 = Pers2.Action(2, Pers3);
    int r3 = Pers1.Action(2, Pers1);
    EXPECT_EQ(r1, -1);
    EXPECT_EQ(r2, -1);
    EXPECT_EQ(r3, -1);
}

TEST(CharacterTests, characterTest1) {
    Character Pers1(CharacterType::berserk);
    Character Pers2(CharacterType::assasin);
    Character Pers3(CharacterType::knight);
    Pers1.SetChance(1);
    Pers2.SetChance(1);
    Pers3.SetChance(1);
    int r1 = Pers1.Action(1, Pers2);
    int r2 = Pers2.Action(1, Pers3);
    int r3 = Pers3.Action(1, Pers1);
    EXPECT_EQ(r1, 250);
    EXPECT_EQ(r2, 50);
    EXPECT_EQ(r3, 50);
}

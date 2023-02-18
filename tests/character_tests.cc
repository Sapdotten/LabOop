#include <gtest/gtest.h>

#include <character/character.h>

TEST(CharacterTests, characterTest0) {
    Character Pers1(CharacterType::berserk);
    Character Pers2(CharacterType::assasin);
    int act1 = Pers1.Action(2, Pers2);
    EXPECT_EQ(act1, -1);
}


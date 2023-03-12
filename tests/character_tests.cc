#include <gtest/gtest.h>
#include <character/character.h>
#include <character/container.h>
#include <iostream>
using namespace std;


TEST(CharacterTests, characterTest11) {//berserk without skill vs everybody(0) without skill
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin(CharacterType::assasin);
    Character Berserk2(CharacterType::berserk);
    Knight.SetChance(0);
    Assasin.SetChance(0);
    Berserk2.SetChance(0);

    Berserk.SetChance(0);

    int bk = Berserk.Attack(Knight);
    int ba = Berserk.Attack(Assasin);
    int bb = Berserk.Attack(Berserk2);

    Berserk.SetChance(1);

    int Bk = Berserk.Attack(Knight);
    int Ba = Berserk.Attack(Assasin);
    int Bb = Berserk.Attack(Berserk2);

    int HPK = Knight.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(bk, 70);
    EXPECT_EQ(ba, 95);
    EXPECT_EQ(Bb, 335);
    EXPECT_EQ(Bk, 310);
    EXPECT_EQ(Ba, 335);
    EXPECT_EQ(Bb, 335);
}

TEST(CharacterTests, characterTest12) {//berserk without skill vs everybody(1) without skill
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin(CharacterType::assasin);
    Character Berserk2(CharacterType::berserk);
    Knight.SetChance(1);
    Assasin.SetChance(1);
    Berserk2.SetChance(1);

    Berserk.SetChance(0);

    int bk = Berserk.Attack(Knight);
    int ba = Berserk.Attack(Assasin);
    int bb = Berserk.Attack(Berserk2);

    Berserk.SetChance(1);

    int Bk = Berserk.Attack(Knight);
    int Ba = Berserk.Attack(Assasin);
    int Bb = Berserk.Attack(Berserk2);

    int HPK = Knight.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(bk, 35);
    EXPECT_EQ(ba, 95);
    EXPECT_EQ(Bb, 335);
    EXPECT_EQ(Bk, 155);
    EXPECT_EQ(Ba, 335);
    EXPECT_EQ(Bb, 335);
}

TEST(CharacterTests, characterTest13) {//berserk without skill vs everybody(0) with skill
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin(CharacterType::assasin);
    Character Berserk2(CharacterType::berserk);
    Knight.SetChance(0);
    Assasin.SetChance(0);
    Berserk2.SetChance(0);

    Knight.UseSkill();
    Assasin.UseSkill();
    Berserk2.UseSkill();

    Berserk.SetChance(0);

    int bk = Berserk.Attack(Knight);
    int ba = Berserk.Attack(Assasin);
    int bb = Berserk.Attack(Berserk2);

    Berserk.SetChance(1);

    int Bk = Berserk.Attack(Knight);
    int Ba = Berserk.Attack(Assasin);
    int Bb = Berserk.Attack(Berserk2);

    int HPK = Knight.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(bk, 40);
    EXPECT_EQ(ba, 0);
    EXPECT_EQ(Bb, 440);
    EXPECT_EQ(Bk, 340);
    EXPECT_EQ(Ba, 0);
    EXPECT_EQ(Bb, 440);
}

TEST(CharacterTests, characterTest14) {//berserk without skill vs everybody(1) with skill
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin(CharacterType::assasin);
    Character Berserk2(CharacterType::berserk);
    Knight.SetChance(1);
    Assasin.SetChance(1);
    Berserk2.SetChance(1);

    Knight.UseSkill();
    Assasin.UseSkill();
    Berserk2.UseSkill();

    Berserk.SetChance(0);

    int bk = Berserk.Attack(Knight);
    int ba = Berserk.Attack(Assasin);
    int bb = Berserk.Attack(Berserk2);

    Berserk.SetChance(1);

    int Bk = Berserk.Attack(Knight);
    int Ba = Berserk.Attack(Assasin);
    int Bb = Berserk.Attack(Berserk2);

    int HPK = Knight.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(bk, 20);
    EXPECT_EQ(ba, 0);
    EXPECT_EQ(Bb, 440);
    EXPECT_EQ(Bk, 170);
    EXPECT_EQ(Ba, 0);
    EXPECT_EQ(Bb, 440);
}

TEST(CharacterTests, characterTest15) {//berserk with skill vs everybody(0) without skill
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin(CharacterType::assasin);
    Character Berserk2(CharacterType::berserk);
    Knight.SetChance(0);
    Assasin.SetChance(0);
    Berserk2.SetChance(0);

    Berserk.SetChance(-1);

    Berserk.UseSkill();
    int bk = Berserk.Attack(Knight);
    Berserk.UseSkill();
    int ba = Berserk.Attack(Assasin);
    Berserk.UseSkill();
    int bb = Berserk.Attack(Berserk2);

    Berserk.SetChance(1);

    Berserk.UseSkill();
    int Bk = Berserk.Attack(Knight);
    Berserk.UseSkill();
    int Ba = Berserk.Attack(Assasin);
    Berserk.UseSkill();
    int Bb = Berserk.Attack(Berserk2);

    int HPK = Knight.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(bk, 110);
    EXPECT_EQ(ba, 130);
    EXPECT_EQ(Bb, 490);
    EXPECT_EQ(Bk, 470);
    EXPECT_EQ(Ba, 490);
    EXPECT_EQ(Bb, 490);
}

TEST(CharacterTests, characterTest16) {//berserk with skill vs everybody(1) without skill
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin(CharacterType::assasin);
    Character Berserk2(CharacterType::berserk);
    Knight.SetChance(1);
    Assasin.SetChance(1);
    Berserk2.SetChance(1);

    Berserk.SetChance(-1);

    Berserk.UseSkill();
    int bk = Berserk.Attack(Knight);
    Berserk.UseSkill();
    int ba = Berserk.Attack(Assasin);
    Berserk.UseSkill();
    int bb = Berserk.Attack(Berserk2);

    Berserk.SetChance(1);

    Berserk.UseSkill();
    int Bk = Berserk.Attack(Knight);
    Berserk.UseSkill();
    int Ba = Berserk.Attack(Assasin);
    Berserk.UseSkill();
    int Bb = Berserk.Attack(Berserk2);

    int HPK = Knight.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(bk, 55);
    EXPECT_EQ(ba, 130);
    EXPECT_EQ(Bb, 490);
    EXPECT_EQ(Bk, 235);
    EXPECT_EQ(Ba, 490);
    EXPECT_EQ(Bb, 490);
}

TEST(CharacterTests, characterTest17) {//berserk with skill vs everybody(0) with skill
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin(CharacterType::assasin);
    Character Berserk2(CharacterType::berserk);
    Knight.SetChance(0);
    Assasin.SetChance(0);
    Berserk2.SetChance(0);

    Knight.UseSkill();
    Assasin.UseSkill();
    Berserk2.UseSkill();

    Berserk.SetChance(-1);

    Berserk.UseSkill();
    int bk = Berserk.Attack(Knight);
    Berserk.UseSkill();
    int ba = Berserk.Attack(Assasin);
    Berserk.UseSkill();
    int bb = Berserk.Attack(Berserk2);

    Berserk.SetChance(1);

    Berserk.UseSkill();
    int Bk = Berserk.Attack(Knight);
    Berserk.UseSkill();
    int Ba = Berserk.Attack(Assasin);
    Berserk.UseSkill();
    int Bb = Berserk.Attack(Berserk2);

    int HPK = Knight.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(bk, 70);
    EXPECT_EQ(ba, 0);
    EXPECT_EQ(Bb, 530);
    EXPECT_EQ(Bk, 430);
    EXPECT_EQ(Ba, 0);
    EXPECT_EQ(Bb, 530);
}

TEST(CharacterTests, characterTest18) {//berserk with skill vs everybody(1) with skill
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin(CharacterType::assasin);
    Character Berserk2(CharacterType::berserk);
    Knight.SetChance(1);
    Assasin.SetChance(1);
    Berserk2.SetChance(1);

    Knight.UseSkill();
    Assasin.UseSkill();
    Berserk2.UseSkill();

    Berserk.SetChance(-1);

    Berserk.UseSkill();
    int bk = Berserk.Attack(Knight);
    Berserk.UseSkill();
    int ba = Berserk.Attack(Assasin);
    Berserk.UseSkill();
    int bb = Berserk.Attack(Berserk2);

    Berserk.SetChance(1);

    Berserk.UseSkill();
    int Bk = Berserk.Attack(Knight);
    Berserk.UseSkill();
    int Ba = Berserk.Attack(Assasin);
    Berserk.UseSkill();
    int Bb = Berserk.Attack(Berserk2);

    int HPK = Knight.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(bk, 35);
    EXPECT_EQ(ba, 0);
    EXPECT_EQ(Bb, 530);
    EXPECT_EQ(Bk, 215);
    EXPECT_EQ(Ba, 0);
    EXPECT_EQ(Bb, 530);
}




TEST(CharacterTests, characterTest21) {//knight without skill vs everybody(0) without skill
    Character Knight(CharacterType::knight);
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Character Knight2(CharacterType::knight);
    Berserk.SetChance(0);
    Assasin.SetChance(0);
    Knight2.SetChance(0);

    Knight.SetChance(0);

    int kb = Knight.Attack(Berserk);
    int ka = Knight.Attack(Assasin);
    int kk = Knight.Attack(Knight2);

    Knight.SetChance(1);

    int Kb = Knight.Attack(Berserk);
    int Ka = Knight.Attack(Assasin);
    int Kk = Knight.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(kb, 50);
    EXPECT_EQ(ka, 50);
    EXPECT_EQ(kk, 30);
    EXPECT_EQ(Kb, 50);
    EXPECT_EQ(Ka, 50);
    EXPECT_EQ(Kk, 30);
}

TEST(CharacterTests, characterTest22) {//knight without skill vs everybody(1) without skill
    Character Knight(CharacterType::knight);
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Character Knight2(CharacterType::knight);
    Berserk.SetChance(1);
    Assasin.SetChance(1);
    Knight2.SetChance(1);

    Knight.SetChance(0);

    int kb = Knight.Attack(Berserk);
    int ka = Knight.Attack(Assasin);
    int kk = Knight.Attack(Knight2);

    Knight.SetChance(1);

    int Kb = Knight.Attack(Berserk);
    int Ka = Knight.Attack(Assasin);
    int Kk = Knight.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(kb, 50);
    EXPECT_EQ(ka, 50);
    EXPECT_EQ(kk, 15);
    EXPECT_EQ(Kb, 50);
    EXPECT_EQ(Ka, 50);
    EXPECT_EQ(Kk, 15);
}

TEST(CharacterTests, characterTest23) {//knight with skill vs everybody(0) without skill
    Character Knight(CharacterType::knight);
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Character Knight2(CharacterType::knight);
    Berserk.SetChance(0);
    Assasin.SetChance(0);
    Knight2.SetChance(0);

    Knight.SetChance(0);

    Knight.UseSkill();
    int kb = Knight.Attack(Berserk);
    Knight.UseSkill();
    int ka = Knight.Attack(Assasin);
    Knight.UseSkill();
    int kk = Knight.Attack(Knight2);

    Knight.SetChance(1);

    Knight.UseSkill();
    int Kb = Knight.Attack(Berserk);
    Knight.UseSkill();
    int Ka = Knight.Attack(Assasin);
    Knight.UseSkill();
    int Kk = Knight.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(kb, 20);
    EXPECT_EQ(ka, 20);
    EXPECT_EQ(kk, 0);
    EXPECT_EQ(Kb, 20);
    EXPECT_EQ(Ka, 20);
    EXPECT_EQ(Kk, 0);
}

TEST(CharacterTests, characterTest24) {//knight with skill vs everybody(1) without skill
    Character Knight(CharacterType::knight);
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Character Knight2(CharacterType::knight);
    Berserk.SetChance(1);
    Assasin.SetChance(1);
    Knight2.SetChance(1);

    Knight.SetChance(0);

    Knight.UseSkill();
    int kb = Knight.Attack(Berserk);
    Knight.UseSkill();
    int ka = Knight.Attack(Assasin);
    Knight.UseSkill();
    int kk = Knight.Attack(Knight2);

    Knight.SetChance(1);

    Knight.UseSkill();
    int Kb = Knight.Attack(Berserk);
    Knight.UseSkill();
    int Ka = Knight.Attack(Assasin);
    Knight.UseSkill();
    int Kk = Knight.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(kb, 20);
    EXPECT_EQ(ka, 20);
    EXPECT_EQ(kk, 0);
    EXPECT_EQ(Kb, 20);
    EXPECT_EQ(Ka, 20);
    EXPECT_EQ(Kk, 0);
}

TEST(CharacterTests, characterTest25) {//knight without skill vs everybody(0) with skill
    Character Knight(CharacterType::knight);
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Character Knight2(CharacterType::knight);
    Berserk.SetChance(0);
    Assasin.SetChance(0);
    Knight2.SetChance(0);

    Berserk.UseSkill();
    Assasin.UseSkill();
    Knight2.UseSkill();

    Knight.SetChance(0);

    int kb = Knight.Attack(Berserk);
    int ka = Knight.Attack(Assasin);
    int kk = Knight.Attack(Knight2);

    Knight.SetChance(1);

    int Kb = Knight.Attack(Berserk);
    int Ka = Knight.Attack(Assasin);
    int Kk = Knight.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(kb, 90);
    EXPECT_EQ(ka, 0);
    EXPECT_EQ(kk, 30);
    EXPECT_EQ(Kb, 90);
    EXPECT_EQ(Ka, 0);
    EXPECT_EQ(Kk, 30);
}

TEST(CharacterTests, characterTest26) {//knight without skill vs everybody(1) with skill
    Character Knight(CharacterType::knight);
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Character Knight2(CharacterType::knight);
    Berserk.SetChance(1);
    Assasin.SetChance(1);
    Knight2.SetChance(1);

    Berserk.UseSkill();
    Assasin.UseSkill();
    Knight2.UseSkill();

    Knight.SetChance(0);

    int kb = Knight.Attack(Berserk);
    int ka = Knight.Attack(Assasin);
    int kk = Knight.Attack(Knight2);

    Knight.SetChance(1);

    int Kb = Knight.Attack(Berserk);
    int Ka = Knight.Attack(Assasin);
    int Kk = Knight.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(kb, 50);
    EXPECT_EQ(ka, 50);
    EXPECT_EQ(kk, 30);
    EXPECT_EQ(Kb, 50);
    EXPECT_EQ(Ka, 50);
    EXPECT_EQ(Kk, 30);
}

TEST(CharacterTests, characterTest27) {//knight with skill vs everybody(0) with skill
    Character Knight(CharacterType::knight);
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Character Knight2(CharacterType::knight);
    Berserk.SetChance(0);
    Assasin.SetChance(0);
    Knight2.SetChance(0);

    Berserk.UseSkill();
    Assasin.UseSkill();
    Knight2.UseSkill();

    Knight.SetChance(0);

    Knight.UseSkill();
    int kb = Knight.Attack(Berserk);
    Knight.UseSkill();
    int ka = Knight.Attack(Assasin);
    Knight.UseSkill();
    int kk = Knight.Attack(Knight2);

    Knight.SetChance(1);

    Knight.UseSkill();
    int Kb = Knight.Attack(Berserk);
    Knight.UseSkill();
    int Ka = Knight.Attack(Assasin);
    Knight.UseSkill();
    int Kk = Knight.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(kb, 20);
    EXPECT_EQ(ka, 20);
    EXPECT_EQ(kk, 0);
    EXPECT_EQ(Kb, 20);
    EXPECT_EQ(Ka, 20);
    EXPECT_EQ(Kk, 0);
}

TEST(CharacterTests, characterTest28) {//knight with skill vs everybody(1) with skill
    Character Knight(CharacterType::knight);
    Character Berserk(CharacterType::berserk);
    Character Assasin(CharacterType::assasin);
    Character Knight2(CharacterType::knight);
    Berserk.SetChance(1);
    Assasin.SetChance(1);
    Knight2.SetChance(1);

    Berserk.UseSkill();
    Assasin.UseSkill();
    Knight2.UseSkill();

    Knight.SetChance(0);

    Knight.UseSkill();
    int kb = Knight.Attack(Berserk);
    Knight.UseSkill();
    int ka = Knight.Attack(Assasin);
    Knight.UseSkill();
    int kk = Knight.Attack(Knight2);

    Knight.SetChance(1);

    Knight.UseSkill();
    int Kb = Knight.Attack(Berserk);
    Knight.UseSkill();
    int Ka = Knight.Attack(Assasin);
    Knight.UseSkill();
    int Kk = Knight.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(kb, 20);
    EXPECT_EQ(ka, 20);
    EXPECT_EQ(kk, 0);
    EXPECT_EQ(Kb, 20);
    EXPECT_EQ(Ka, 20);
    EXPECT_EQ(Kk, 0);
}




TEST(CharacterTests, characterTest31) {//assasin without skill vs everybody(0) without skill
    Character Assasin(CharacterType::assasin);
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin2(CharacterType::assasin);
    Berserk.SetChance(0);
    Assasin2.SetChance(0);
    Knight.SetChance(0);

    Assasin.SetChance(0);

    int ab = Assasin.Attack(Berserk);
    int aa = Assasin.Attack(Assasin2);
    int ak = Assasin.Attack(Knight);

    Assasin.SetChance(1);

    int Ab = Assasin.Attack(Berserk);
    int Aa = Assasin.Attack(Assasin2);
    int Ak = Assasin.Attack(Knight);

    int HPK = Knight.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin2.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(ab, 50);
    EXPECT_EQ(aa, 50);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 50);
    EXPECT_EQ(Aa, 50);
    EXPECT_EQ(Ak, 30);
}

TEST(CharacterTests, characterTest32) {//assasin without skill vs everybody(1) without skill
    Character Assasin(CharacterType::assasin);
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin2(CharacterType::assasin);
    Berserk.SetChance(1);
    Assasin2.SetChance(1);
    Knight.SetChance(1);

    Assasin.SetChance(0);

    int ab = Assasin.Attack(Berserk);
    int aa = Assasin.Attack(Assasin2);
    int ak = Assasin.Attack(Knight);

    Assasin.SetChance(1);

    int Ab = Assasin.Attack(Berserk);
    int Aa = Assasin.Attack(Assasin2);
    int Ak = Assasin.Attack(Knight);

    int HPK = Knight.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin2.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(ab, 50);
    EXPECT_EQ(aa, 50);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 50);
    EXPECT_EQ(Aa, 50);
    EXPECT_EQ(Ak, 30);
}

TEST(CharacterTests, characterTest33) {//assasin with skill vs everybody(0) without skill
    Character Assasin(CharacterType::assasin);
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin2(CharacterType::assasin);
    Berserk.SetChance(0);
    Assasin2.SetChance(0);
    Knight.SetChance(0);

    Assasin.SetChance(0);
    Assasin.UseSkill();
    int ab = Assasin.Attack(Berserk);
    Assasin.UseSkill();
    int aa = Assasin.Attack(Assasin2);
    Assasin.UseSkill();
    int ak = Assasin.Attack(Knight);

    Assasin.SetChance(1);

    Assasin.UseSkill();
    int Ab = Assasin.Attack(Berserk);
    Assasin.UseSkill();
    int Aa = Assasin.Attack(Assasin2);
    Assasin.UseSkill();
    int Ak = Assasin.Attack(Knight);

    int HPK = Knight.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin2.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(ab, 50);
    EXPECT_EQ(aa, 50);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 50);
    EXPECT_EQ(Aa, 50);
    EXPECT_EQ(Ak, 30);
}

TEST(CharacterTests, characterTest34) {//assasin with skill vs everybody(0) without skill
    Character Assasin(CharacterType::assasin);
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin2(CharacterType::assasin);
    Berserk.SetChance(1);
    Assasin2.SetChance(1);
    Knight.SetChance(1);

    Assasin.SetChance(0);
    Assasin.UseSkill();
    int ab = Assasin.Attack(Berserk);
    Assasin.UseSkill();
    int aa = Assasin.Attack(Assasin2);
    Assasin.UseSkill();
    int ak = Assasin.Attack(Knight);

    Assasin.SetChance(1);

    Assasin.UseSkill();
    int Ab = Assasin.Attack(Berserk);
    Assasin.UseSkill();
    int Aa = Assasin.Attack(Assasin2);
    Assasin.UseSkill();
    int Ak = Assasin.Attack(Knight);

    int HPK = Knight.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin2.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(ab, 50);
    EXPECT_EQ(aa, 50);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 50);
    EXPECT_EQ(Aa, 50);
    EXPECT_EQ(Ak, 30);
}

TEST(CharacterTests, characterTest35) {//assasin without skill vs everybody(0) with skill
    Character Assasin(CharacterType::assasin);
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin2(CharacterType::assasin);
    Berserk.SetChance(0);
    Assasin2.SetChance(0);
    Knight.SetChance(0);

    Berserk.UseSkill();
    Assasin2.UseSkill();
    Knight.UseSkill();

    Assasin.SetChance(0);

    int ab = Assasin.Attack(Berserk);
    int aa = Assasin.Attack(Assasin2);
    int ak = Assasin.Attack(Knight);

    Assasin.SetChance(1);

    int Ab = Assasin.Attack(Berserk);
    int Aa = Assasin.Attack(Assasin2);
    int Ak = Assasin.Attack(Knight);

    int HPK = Knight.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin2.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(ab, 50);
    EXPECT_EQ(aa, 50);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 50);
    EXPECT_EQ(Aa, 50);
    EXPECT_EQ(Ak, 30);
}

TEST(CharacterTests, characterTest36) {//assasin without skill vs everybody(1) with skill
    Character Assasin(CharacterType::assasin);
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin2(CharacterType::assasin);
    Berserk.SetChance(1);
    Assasin2.SetChance(1);
    Knight.SetChance(1);

    Berserk.UseSkill();
    Assasin2.UseSkill();
    Knight.UseSkill();

    Assasin.SetChance(0);

    int ab = Assasin.Attack(Berserk);
    int aa = Assasin.Attack(Assasin2);
    int ak = Assasin.Attack(Knight);

    Assasin.SetChance(1);

    int Ab = Assasin.Attack(Berserk);
    int Aa = Assasin.Attack(Assasin2);
    int Ak = Assasin.Attack(Knight);

    int HPK = Knight.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin2.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(ab, 50);
    EXPECT_EQ(aa, 50);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 50);
    EXPECT_EQ(Aa, 50);
    EXPECT_EQ(Ak, 30);
}

TEST(CharacterTests, characterTest37) {//assasin with skill vs everybody(0) with skill
    Character Assasin(CharacterType::assasin);
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin2(CharacterType::assasin);
    Berserk.SetChance(0);
    Assasin2.SetChance(0);
    Knight.SetChance(0);

    Berserk.UseSkill();
    Assasin2.UseSkill();
    Knight.UseSkill();

    Assasin.SetChance(0);
    Assasin.UseSkill();
    int ab = Assasin.Attack(Berserk);
    Assasin.UseSkill();
    int aa = Assasin.Attack(Assasin2);
    Assasin.UseSkill();
    int ak = Assasin.Attack(Knight);

    Assasin.SetChance(1);

    Assasin.UseSkill();
    int Ab = Assasin.Attack(Berserk);
    Assasin.UseSkill();
    int Aa = Assasin.Attack(Assasin2);
    Assasin.UseSkill();
    int Ak = Assasin.Attack(Knight);

    int HPK = Knight.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin2.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(ab, 50);
    EXPECT_EQ(aa, 50);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 50);
    EXPECT_EQ(Aa, 50);
    EXPECT_EQ(Ak, 30);
}

TEST(CharacterTests, characterTest38) {//assasin with skill vs everybody(1) with skill
    Character Assasin(CharacterType::assasin);
    Character Berserk(CharacterType::berserk);
    Character Knight(CharacterType::knight);
    Character Assasin2(CharacterType::assasin);
    Berserk.SetChance(1);
    Assasin2.SetChance(1);
    Knight.SetChance(1);

    Berserk.UseSkill();
    Assasin2.UseSkill();
    Knight.UseSkill();

    Assasin.SetChance(0);
    Assasin.UseSkill();
    int ab = Assasin.Attack(Berserk);
    Assasin.UseSkill();
    int aa = Assasin.Attack(Assasin2);
    Assasin.UseSkill();
    int ak = Assasin.Attack(Knight);

    Assasin.SetChance(1);

    Assasin.UseSkill();
    int Ab = Assasin.Attack(Berserk);
    Assasin.UseSkill();
    int Aa = Assasin.Attack(Assasin2);
    Assasin.UseSkill();
    int Ak = Assasin.Attack(Knight);

    int HPK = Knight.GetHP();
    int HPB = Berserk.GetHP();
    int HPA = Assasin2.GetHP();

    EXPECT_EQ(HPK, 335);
    EXPECT_EQ(HPB, 335);
    EXPECT_EQ(HPA, 335);

    EXPECT_EQ(ab, 50);
    EXPECT_EQ(aa, 50);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 50);
    EXPECT_EQ(Aa, 50);
    EXPECT_EQ(Ak, 30);
}
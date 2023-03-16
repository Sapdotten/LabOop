#include <gtest/gtest.h>
#include <character/character.h>
#include <character/container.h>
#include <iostream>
using namespace std;
using namespace CharacterGame;

TEST(BerserkTests, BerserkTest1) {//berserk without skill vs everybody(0) without skill
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

    EXPECT_EQ(HPK, 620);
    EXPECT_EQ(HPB, 570);
    EXPECT_EQ(HPA, 770);

    EXPECT_EQ(bk, 70);
    EXPECT_EQ(ba, 95);
    EXPECT_EQ(bb, 95);
    EXPECT_EQ(Bk, 310);
    EXPECT_EQ(Ba, 335);
    EXPECT_EQ(Bb, 335);
}

TEST(BerserkTests, BerserkTest2) {//berserk without skill vs everybody(1) without skill
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

    EXPECT_EQ(HPK, 810);
    EXPECT_EQ(HPB, 570);
    EXPECT_EQ(HPA, 770);

    EXPECT_EQ(bk, 35);
    EXPECT_EQ(ba, 95);
    EXPECT_EQ(bb, 95);
    EXPECT_EQ(Bk, 155);
    EXPECT_EQ(Ba, 335);
    EXPECT_EQ(Bb, 335);
}

TEST(BerserkTests, BerserkTest3) {//berserk without skill vs everybody(0) with skill
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

    EXPECT_EQ(HPK, 660);
    EXPECT_EQ(HPB, 530);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(bk, 50);
    EXPECT_EQ(ba, 0);
    EXPECT_EQ(bb, 115);
    EXPECT_EQ(Bk, 290);
    EXPECT_EQ(Ba, 0);
    EXPECT_EQ(Bb, 355);
}

TEST(BerserkTests, BerserkTest4) {//berserk without skill vs everybody(1) with skill
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

    EXPECT_EQ(HPK, 830);
    EXPECT_EQ(HPB, 530);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(bk, 25);
    EXPECT_EQ(ba, 0);
    EXPECT_EQ(bb, 115);
    EXPECT_EQ(Bk, 145);
    EXPECT_EQ(Ba, 0);
    EXPECT_EQ(Bb, 355);
}

TEST(BerserkTests, BerserkTest5) {//berserk with skill vs everybody(0) without skill
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

    EXPECT_EQ(HPK, 540);
    EXPECT_EQ(HPB, 490);
    EXPECT_EQ(HPA, 690);

    EXPECT_EQ(bk, 90);
    EXPECT_EQ(ba, 115);
    EXPECT_EQ(bb, 115);
    EXPECT_EQ(Bk, 370);
    EXPECT_EQ(Ba, 395);
    EXPECT_EQ(Bb, 395);
}

TEST(BerserkTests, BerserkTest6) {//berserk with skill vs everybody(1) without skill
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

    EXPECT_EQ(HPK, 770);
    EXPECT_EQ(HPB, 490);
    EXPECT_EQ(HPA, 690);

    EXPECT_EQ(bk, 45);
    EXPECT_EQ(ba, 115);
    EXPECT_EQ(bb, 115);
    EXPECT_EQ(Bk, 185);
    EXPECT_EQ(Ba, 395);
    EXPECT_EQ(Bb, 395);
}

TEST(BerserkTests, BerserkTest7) {//berserk with skill vs everybody(0) with skill
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

    EXPECT_EQ(HPK, 580);
    EXPECT_EQ(HPB, 450);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(bk, 70);
    EXPECT_EQ(ba, 0);
    EXPECT_EQ(bb, 135);
    EXPECT_EQ(Bk, 350);
    EXPECT_EQ(Ba, 0);
    EXPECT_EQ(Bb, 415);
}

TEST(BerserkTests, BerserkTest8) {//berserk with skill vs everybody(1) with skill
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

    EXPECT_EQ(HPK, 790);
    EXPECT_EQ(HPB, 450);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(bk, 35);
    EXPECT_EQ(ba, 0);
    EXPECT_EQ(bb, 135);
    EXPECT_EQ(Bk, 175);
    EXPECT_EQ(Ba, 0);
    EXPECT_EQ(Bb, 415);
}




TEST(KnightTests, KnightTest1) {//knight without skill vs everybody(0) without skill
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

    EXPECT_EQ(HPK, 900);
    EXPECT_EQ(HPB, 850);
    EXPECT_EQ(HPA, 1050);

    EXPECT_EQ(kb, 75);
    EXPECT_EQ(ka, 75);
    EXPECT_EQ(kk, 50);
    EXPECT_EQ(Kb, 75);
    EXPECT_EQ(Ka, 75);
    EXPECT_EQ(Kk, 50);
}

TEST(KnightTests, KnightTest2) {//knight without skill vs everybody(1) without skill
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

    EXPECT_EQ(HPK, 950);
    EXPECT_EQ(HPB, 850);
    EXPECT_EQ(HPA, 1050);

    EXPECT_EQ(kb, 75);
    EXPECT_EQ(ka, 75);
    EXPECT_EQ(kk, 25);
    EXPECT_EQ(Kb, 75);
    EXPECT_EQ(Ka, 75);
    EXPECT_EQ(Kk, 25);
}

TEST(KnightTests, KnightTest3) {//knight with skill vs everybody(0) without skill
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

    EXPECT_EQ(HPK, 940);
    EXPECT_EQ(HPB, 890);
    EXPECT_EQ(HPA, 1090);

    EXPECT_EQ(kb, 55);
    EXPECT_EQ(ka, 55);
    EXPECT_EQ(kk, 30);
    EXPECT_EQ(Kb, 55);
    EXPECT_EQ(Ka, 55);
    EXPECT_EQ(Kk, 30);
}

TEST(KnightTests, KnightTest4) {//knight with skill vs everybody(1) without skill
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

    EXPECT_EQ(HPK, 970);
    EXPECT_EQ(HPB, 890);
    EXPECT_EQ(HPA, 1090);

    EXPECT_EQ(kb, 55);
    EXPECT_EQ(ka, 55);
    EXPECT_EQ(kk, 15);
    EXPECT_EQ(Kb, 55);
    EXPECT_EQ(Ka, 55);
    EXPECT_EQ(Kk, 15);
}

TEST(KnightTests, KnightTest5) {//knight without skill vs everybody(0) with skill
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

    EXPECT_EQ(HPK, 940);
    EXPECT_EQ(HPB, 810);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(kb, 95);
    EXPECT_EQ(ka, 0);
    EXPECT_EQ(kk, 30);
    EXPECT_EQ(Kb, 95);
    EXPECT_EQ(Ka, 0);
    EXPECT_EQ(Kk, 30);
}

TEST(KnightTests, KnightTest6) {//knight without skill vs everybody(1) with skill
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

    EXPECT_EQ(HPK, 970);
    EXPECT_EQ(HPB, 810);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(kb, 95);
    EXPECT_EQ(ka, 0);
    EXPECT_EQ(kk, 15);
    EXPECT_EQ(Kb, 95);
    EXPECT_EQ(Ka, 0);
    EXPECT_EQ(Kk, 15);
}

TEST(KnightTests, KnightTest7) {//knight with skill vs everybody(0) with skill
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

    EXPECT_EQ(HPK, 980);
    EXPECT_EQ(HPB, 850);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(kb, 75);
    EXPECT_EQ(ka, 0);
    EXPECT_EQ(kk, 10);
    EXPECT_EQ(Kb, 75);
    EXPECT_EQ(Ka, 0);
    EXPECT_EQ(Kk, 10);
}

TEST(KnightTests, KnightTest8) {//knight with skill vs everybody(1) with skill
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

    EXPECT_EQ(HPK, 990);
    EXPECT_EQ(HPB, 850);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(kb, 75);
    EXPECT_EQ(ka, 0);
    EXPECT_EQ(kk, 5);
    EXPECT_EQ(Kb, 75);
    EXPECT_EQ(Ka, 0);
    EXPECT_EQ(Kk, 5);
}




TEST(AssasinTests, AssasinTest1) {//assasin without skill vs everybody(0) without skill
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

    EXPECT_EQ(HPK, 850);
    EXPECT_EQ(HPB, 775);
    EXPECT_EQ(HPA, 975);

    EXPECT_EQ(ab, 75);
    EXPECT_EQ(aa, 75);
    EXPECT_EQ(ak, 50);
    EXPECT_EQ(Ab, 150);
    EXPECT_EQ(Aa, 150);
    EXPECT_EQ(Ak, 100);
}

TEST(AssasinTests, AssasinTest2) {//assasin without skill vs everybody(1) without skill
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

    EXPECT_EQ(HPK, 925);
    EXPECT_EQ(HPB, 775);
    EXPECT_EQ(HPA, 975);

    EXPECT_EQ(ab, 75);
    EXPECT_EQ(aa, 75);
    EXPECT_EQ(ak, 25);
    EXPECT_EQ(Ab, 150);
    EXPECT_EQ(Aa, 150);
    EXPECT_EQ(Ak, 50);
}

TEST(AssasinTests, AssasinTest3) {//assasin with skill vs everybody(0) without skill
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

    EXPECT_EQ(HPK, 850);
    EXPECT_EQ(HPB, 775);
    EXPECT_EQ(HPA, 975);

    EXPECT_EQ(ab, 75);
    EXPECT_EQ(aa, 75);
    EXPECT_EQ(ak, 50);
    EXPECT_EQ(Ab, 150);
    EXPECT_EQ(Aa, 150);
    EXPECT_EQ(Ak, 100);
}

TEST(AssasinTests, AssasinTest4) {//assasin with skill vs everybody(0) without skill
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

    EXPECT_EQ(HPK, 925);
    EXPECT_EQ(HPB, 775);
    EXPECT_EQ(HPA, 975);

    EXPECT_EQ(ab, 75);
    EXPECT_EQ(aa, 75);
    EXPECT_EQ(ak, 25);
    EXPECT_EQ(Ab, 150);
    EXPECT_EQ(Aa, 150);
    EXPECT_EQ(Ak, 50);
}

TEST(AssasinTests, AssasinTest5) {//assasin without skill vs everybody(0) with skill
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

    EXPECT_EQ(HPK, 910);
    EXPECT_EQ(HPB, 715);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(ab, 95);
    EXPECT_EQ(aa, 0);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 190);
    EXPECT_EQ(Aa, 0);
    EXPECT_EQ(Ak, 60);
}

TEST(AssasinTests, AssasinTest6) {//assasin without skill vs everybody(1) with skill
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

    EXPECT_EQ(HPK, 955);
    EXPECT_EQ(HPB, 715);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(ab, 95);
    EXPECT_EQ(aa, 0);
    EXPECT_EQ(ak, 15);
    EXPECT_EQ(Ab, 190);
    EXPECT_EQ(Aa, 0);
    EXPECT_EQ(Ak, 30);
}

TEST(AssasinTests, AssasinTest7) {//assasin with skill vs everybody(0) with skill
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

    EXPECT_EQ(HPK, 910);
    EXPECT_EQ(HPB, 715);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(ab, 95);
    EXPECT_EQ(aa, 0);
    EXPECT_EQ(ak, 30);
    EXPECT_EQ(Ab, 190);
    EXPECT_EQ(Aa, 0);
    EXPECT_EQ(Ak, 60);
}

TEST(AssasinTests, AssasinTest8) {//assasin with skill vs everybody(1) with skill
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

    EXPECT_EQ(HPK, 955);
    EXPECT_EQ(HPB, 715);
    EXPECT_EQ(HPA, 1200);

    EXPECT_EQ(ab, 95);
    EXPECT_EQ(aa, 0);
    EXPECT_EQ(ak, 15);
    EXPECT_EQ(Ab, 190);
    EXPECT_EQ(Aa, 0);
    EXPECT_EQ(Ak, 30);
}




TEST(ContainerTests, ContainerTest1) {
    Container Array(5);
    Array[0] = Character(assasin);
    Array[2] = Character(berserk);
    Array[1] = Character(knight);
    int maxDamage = Array.GetMaxDamage().GetDamage();
    int minDamage = Array.GetMinDamage().GetDamage();


    EXPECT_EQ(maxDamage, 120);
    EXPECT_EQ(minDamage, 100);
}
TEST(ContainerTests, ContainerTest2) {
    Container Array(5);
    Array[0] = Character(assasin);
    Array[1] = Character(berserk);
    Array[2] = Character(knight);
    Array[3] = Character(assasin);
    Array[4] = Character(knight);
    Array.DeleteElem(3);

    EXPECT_EQ(Array[3].GetType(), knight);
    EXPECT_EQ(Array.GetSize(), 4);
}
TEST(ContainerTests, ContainerTest3) {
    Container Array = { Character(assasin), Character(berserk)};
    EXPECT_EQ(Array.GetSize(), 2);
    EXPECT_EQ(Array.GetMaxDamage().GetDamage(), 120);
    EXPECT_EQ(Array.GetMinDamage().GetDamage(), 100);
}




TEST(ContainerExceptionsTest, ContExceptionTest1) {
    Container Array;
    EXPECT_THROW(Array.GetMaxDamage(), logic_error);
}
TEST(ContainerExceptionsTest, ContExceptionTest2) {
    EXPECT_THROW(Container Array(11), logic_error);
    EXPECT_THROW(Container Array(-1), logic_error);
}
TEST(ContainerExceptionsTest, ContExceptionTest3) {
    Container Array(6);
    Container fullArray(10);
    Character player(assasin);
    EXPECT_THROW(Array.DeleteElem(7), out_of_range);
    EXPECT_THROW(Array.DeleteElem(-1), out_of_range);
    EXPECT_THROW(Array[6], out_of_range);
    EXPECT_THROW(Array[-1], out_of_range);
    EXPECT_THROW(fullArray.AddElem(player, 8), out_of_range);
}



TEST(CharacterExceptionsTest, CharExceptionTest1) {
    Character player1(assasin);
    Character player0;
    EXPECT_THROW({
        try {
        player1.Attack(player0);
    }
    catch (logic_error er) {
        EXPECT_STREQ("You can't use \"nobody\" character", er.what());
        throw;
    }
        }, logic_error);
    EXPECT_THROW(player1.Attack(player1), logic_error);
}

TEST(CharacterExceptionTest, CharExceptionTest2) {
    EXPECT_THROW(Character player(nobody), invalid_argument);
}

TEST(CharacterExceptionTest, CharExceptionTest3) {
    Character player;
    EXPECT_THROW(player.SetChance(0.7), logic_error);
    EXPECT_THROW(player.Attack(player), logic_error);
    EXPECT_THROW(player.UseSkill(), logic_error);
    EXPECT_THROW(player.TakeDamage(12), logic_error);
}
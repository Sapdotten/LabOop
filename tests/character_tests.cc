#include <gtest/gtest.h>
#include <character/character.h>
#include <character/container.h>
#include <iostream>
#include <memory>
using namespace std;
using namespace CharacterGame;

TEST(BerserkTests, BerserkTest1) {//berserk without skill vs everybody(0) without skill
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Berserk Berserk2;
    Knight1.SetChance(0);
    Assasin1.SetChance(0);
    Berserk2.SetChance(0);

    Berserk1.SetChance(0);

    int bk = Berserk1.Attack(Knight1);
    int ba = Berserk1.Attack(Assasin1);
    int bb = Berserk1.Attack(Berserk2);

    Berserk1.SetChance(1);

    int Bk = Berserk1.Attack(Knight1);
    int Ba = Berserk1.Attack(Assasin1);
    int Bb = Berserk1.Attack(Berserk2);

    int HPK = Knight1.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Berserk Berserk2;
    Knight1.SetChance(1);
    Assasin1.SetChance(1);
    Berserk2.SetChance(1);

    Berserk1.SetChance(0);

    int bk = Berserk1.Attack(Knight1);
    int ba = Berserk1.Attack(Assasin1);
    int bb = Berserk1.Attack(Berserk2);

    Berserk1.SetChance(1);

    int Bk = Berserk1.Attack(Knight1);
    int Ba = Berserk1.Attack(Assasin1);
    int Bb = Berserk1.Attack(Berserk2);

    int HPK = Knight1.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Berserk Berserk2;
    Knight1.SetChance(0);
    Assasin1.SetChance(0);
    Berserk2.SetChance(0);

    Knight1.UseSkill();
    Assasin1.UseSkill();
    Berserk2.UseSkill();

    Berserk1.SetChance(0);

    int bk = Berserk1.Attack(Knight1);
    int ba = Berserk1.Attack(Assasin1);
    int bb = Berserk1.Attack(Berserk2);

    Berserk1.SetChance(1);

    int Bk = Berserk1.Attack(Knight1);
    int Ba = Berserk1.Attack(Assasin1);
    int Bb = Berserk1.Attack(Berserk2);

    int HPK = Knight1.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Berserk Berserk2;
    Knight1.SetChance(1);
    Assasin1.SetChance(1);
    Berserk2.SetChance(1);

    Knight1.UseSkill();
    Assasin1.UseSkill();
    Berserk2.UseSkill();

    Berserk1.SetChance(0);

    int bk = Berserk1.Attack(Knight1);
    int ba = Berserk1.Attack(Assasin1);
    int bb = Berserk1.Attack(Berserk2);

    Berserk1.SetChance(1);

    int Bk = Berserk1.Attack(Knight1);
    int Ba = Berserk1.Attack(Assasin1);
    int Bb = Berserk1.Attack(Berserk2);

    int HPK = Knight1.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Berserk Berserk2;
    Knight1.SetChance(0);
    Assasin1.SetChance(0);
    Berserk2.SetChance(0);

    Berserk1.SetChance(-1);

    Berserk1.UseSkill();
    int bk = Berserk1.Attack(Knight1);
    Berserk1.UseSkill();
    int ba = Berserk1.Attack(Assasin1);
    Berserk1.UseSkill();
    int bb = Berserk1.Attack(Berserk2);

    Berserk1.SetChance(1);

    Berserk1.UseSkill();
    int Bk = Berserk1.Attack(Knight1);
    Berserk1.UseSkill();
    int Ba = Berserk1.Attack(Assasin1);
    Berserk1.UseSkill();
    int Bb = Berserk1.Attack(Berserk2);

    int HPK = Knight1.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Berserk Berserk2;
    Knight1.SetChance(1);
    Assasin1.SetChance(1);
    Berserk2.SetChance(1);

    Berserk1.SetChance(-1);

    Berserk1.UseSkill();
    int bk = Berserk1.Attack(Knight1);
    Berserk1.UseSkill();
    int ba = Berserk1.Attack(Assasin1);
    Berserk1.UseSkill();
    int bb = Berserk1.Attack(Berserk2);

    Berserk1.SetChance(1);

    Berserk1.UseSkill();
    int Bk = Berserk1.Attack(Knight1);
    Berserk1.UseSkill();
    int Ba = Berserk1.Attack(Assasin1);
    Berserk1.UseSkill();
    int Bb = Berserk1.Attack(Berserk2);

    int HPK = Knight1.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Berserk Berserk2;
    Knight1.SetChance(0);
    Assasin1.SetChance(0);
    Berserk2.SetChance(0);

    Knight1.UseSkill();
    Assasin1.UseSkill();
    Berserk2.UseSkill();

    Berserk1.SetChance(-1);

    Berserk1.UseSkill();
    int bk = Berserk1.Attack(Knight1);
    Berserk1.UseSkill();
    int ba = Berserk1.Attack(Assasin1);
    Berserk1.UseSkill();
    int bb = Berserk1.Attack(Berserk2);

    Berserk1.SetChance(1);

    Berserk1.UseSkill();
    int Bk = Berserk1.Attack(Knight1);
    Berserk1.UseSkill();
    int Ba = Berserk1.Attack(Assasin1);
    Berserk1.UseSkill();
    int Bb = Berserk1.Attack(Berserk2);

    int HPK = Knight1.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Berserk Berserk2;
    Knight1.SetChance(1);
    Assasin1.SetChance(1);
    Berserk2.SetChance(1);

    Knight1.UseSkill();
    Assasin1.UseSkill();
    Berserk2.UseSkill();

    Berserk1.SetChance(-1);

    Berserk1.UseSkill();
    int bk = Berserk1.Attack(Knight1);
    Berserk1.UseSkill();
    int ba = Berserk1.Attack(Assasin1);
    Berserk1.UseSkill();
    int bb = Berserk1.Attack(Berserk2);

    Berserk1.SetChance(1);

    Berserk1.UseSkill();
    int Bk = Berserk1.Attack(Knight1);
    Berserk1.UseSkill();
    int Ba = Berserk1.Attack(Assasin1);
    Berserk1.UseSkill();
    int Bb = Berserk1.Attack(Berserk2);

    int HPK = Knight1.GetHP();
    int HPB = Berserk2.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Knight Knight2;
    Berserk1.SetChance(0);
    Assasin1.SetChance(0);
    Knight2.SetChance(0);

    Knight1.SetChance(0);

    int kb = Knight1.Attack(Berserk1);
    int ka = Knight1.Attack(Assasin1);
    int kk = Knight1.Attack(Knight2);

    Knight1.SetChance(1);

    int Kb = Knight1.Attack(Berserk1);
    int Ka = Knight1.Attack(Assasin1);
    int Kk = Knight1.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk1.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Knight Knight2;
    Berserk1.SetChance(1);
    Assasin1.SetChance(1);
    Knight2.SetChance(1);

    Knight1.SetChance(0);

    int kb = Knight1.Attack(Berserk1);
    int ka = Knight1.Attack(Assasin1);
    int kk = Knight1.Attack(Knight2);

    Knight1.SetChance(1);

    int Kb = Knight1.Attack(Berserk1);
    int Ka = Knight1.Attack(Assasin1);
    int Kk = Knight1.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk1.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Knight Knight2;
    Berserk1.SetChance(0);
    Assasin1.SetChance(0);
    Knight2.SetChance(0);

    Knight1.SetChance(0);

    Knight1.UseSkill();
    int kb = Knight1.Attack(Berserk1);
    Knight1.UseSkill();
    int ka = Knight1.Attack(Assasin1);
    Knight1.UseSkill();
    int kk = Knight1.Attack(Knight2);

    Knight1.SetChance(1);

    Knight1.UseSkill();
    int Kb = Knight1.Attack(Berserk1);
    Knight1.UseSkill();
    int Ka = Knight1.Attack(Assasin1);
    Knight1.UseSkill();
    int Kk = Knight1.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk1.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Knight Knight2;
    Berserk1.SetChance(1);
    Assasin1.SetChance(1);
    Knight2.SetChance(1);

    Knight1.SetChance(0);

    Knight1.UseSkill();
    int kb = Knight1.Attack(Berserk1);
    Knight1.UseSkill();
    int ka = Knight1.Attack(Assasin1);
    Knight1.UseSkill();
    int kk = Knight1.Attack(Knight2);

    Knight1.SetChance(1);

    Knight1.UseSkill();
    int Kb = Knight1.Attack(Berserk1);
    Knight1.UseSkill();
    int Ka = Knight1.Attack(Assasin1);
    Knight1.UseSkill();
    int Kk = Knight1.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk1.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Knight Knight2;
    Berserk1.SetChance(0);
    Assasin1.SetChance(0);
    Knight2.SetChance(0);

    Berserk1.UseSkill();
    Assasin1.UseSkill();
    Knight2.UseSkill();

    Knight1.SetChance(0);

    int kb = Knight1.Attack(Berserk1);
    int ka = Knight1.Attack(Assasin1);
    int kk = Knight1.Attack(Knight2);

    Knight1.SetChance(1);

    int Kb = Knight1.Attack(Berserk1);
    int Ka = Knight1.Attack(Assasin1);
    int Kk = Knight1.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk1.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Knight Knight2;
    Berserk1.SetChance(1);
    Assasin1.SetChance(1);
    Knight2.SetChance(1);

    Berserk1.UseSkill();
    Assasin1.UseSkill();
    Knight2.UseSkill();

    Knight1.SetChance(0);

    int kb = Knight1.Attack(Berserk1);
    int ka = Knight1.Attack(Assasin1);
    int kk = Knight1.Attack(Knight2);

    Knight1.SetChance(1);

    int Kb = Knight1.Attack(Berserk1);
    int Ka = Knight1.Attack(Assasin1);
    int Kk = Knight1.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk1.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Knight Knight2;
    Berserk1.SetChance(0);
    Assasin1.SetChance(0);
    Knight2.SetChance(0);

    Berserk1.UseSkill();
    Assasin1.UseSkill();
    Knight2.UseSkill();

    Knight1.SetChance(0);

    Knight1.UseSkill();
    int kb = Knight1.Attack(Berserk1);
    Knight1.UseSkill();
    int ka = Knight1.Attack(Assasin1);
    Knight1.UseSkill();
    int kk = Knight1.Attack(Knight2);

    Knight1.SetChance(1);

    Knight1.UseSkill();
    int Kb = Knight1.Attack(Berserk1);
    Knight1.UseSkill();
    int Ka = Knight1.Attack(Assasin1);
    Knight1.UseSkill();
    int Kk = Knight1.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk1.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Knight Knight2;
    Berserk1.SetChance(1);
    Assasin1.SetChance(1);
    Knight2.SetChance(1);

    Berserk1.UseSkill();
    Assasin1.UseSkill();
    Knight2.UseSkill();

    Knight1.SetChance(0);

    Knight1.UseSkill();
    int kb = Knight1.Attack(Berserk1);
    Knight1.UseSkill();
    int ka = Knight1.Attack(Assasin1);
    Knight1.UseSkill();
    int kk = Knight1.Attack(Knight2);

    Knight1.SetChance(1);

    Knight1.UseSkill();
    int Kb = Knight1.Attack(Berserk1);
    Knight1.UseSkill();
    int Ka = Knight1.Attack(Assasin1);
    Knight1.UseSkill();
    int Kk = Knight1.Attack(Knight2);

    int HPK = Knight2.GetHP();
    int HPB = Berserk1.GetHP();
    int HPA = Assasin1.GetHP();

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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Assasin Assasin2;
    Berserk1.SetChance(0);
    Assasin2.SetChance(0);
    Knight1.SetChance(0);

    Assasin1.SetChance(0);

    int ab = Assasin1.Attack(Berserk1);
    int aa = Assasin1.Attack(Assasin2);
    int ak = Assasin1.Attack(Knight1);

    Assasin1.SetChance(1);

    int Ab = Assasin1.Attack(Berserk1);
    int Aa = Assasin1.Attack(Assasin2);
    int Ak = Assasin1.Attack(Knight1);

    int HPK = Knight1.GetHP();
    int HPB = Berserk1.GetHP();
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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Assasin Assasin2;
    Berserk1.SetChance(1);
    Assasin2.SetChance(1);
    Knight1.SetChance(1);

    Assasin1.SetChance(0);

    int ab = Assasin1.Attack(Berserk1);
    int aa = Assasin1.Attack(Assasin2);
    int ak = Assasin1.Attack(Knight1);

    Assasin1.SetChance(1);

    int Ab = Assasin1.Attack(Berserk1);
    int Aa = Assasin1.Attack(Assasin2);
    int Ak = Assasin1.Attack(Knight1);

    int HPK = Knight1.GetHP();
    int HPB = Berserk1.GetHP();
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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Assasin Assasin2;
    Berserk1.SetChance(0);
    Assasin2.SetChance(0);
    Knight1.SetChance(0);

    Assasin1.SetChance(0);
    Assasin1.UseSkill();
    int ab = Assasin1.Attack(Berserk1);
    Assasin1.UseSkill();
    int aa = Assasin1.Attack(Assasin2);
    Assasin1.UseSkill();
    int ak = Assasin1.Attack(Knight1);

    Assasin1.SetChance(1);

    Assasin1.UseSkill();
    int Ab = Assasin1.Attack(Berserk1);
    Assasin1.UseSkill();
    int Aa = Assasin1.Attack(Assasin2);
    Assasin1.UseSkill();
    int Ak = Assasin1.Attack(Knight1);

    int HPK = Knight1.GetHP();
    int HPB = Berserk1.GetHP();
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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Assasin Assasin2;
    Berserk1.SetChance(1);
    Assasin2.SetChance(1);
    Knight1.SetChance(1);

    Assasin1.SetChance(0);
    Assasin1.UseSkill();
    int ab = Assasin1.Attack(Berserk1);
    Assasin1.UseSkill();
    int aa = Assasin1.Attack(Assasin2);
    Assasin1.UseSkill();
    int ak = Assasin1.Attack(Knight1);

    Assasin1.SetChance(1);

    Assasin1.UseSkill();
    int Ab = Assasin1.Attack(Berserk1);
    Assasin1.UseSkill();
    int Aa = Assasin1.Attack(Assasin2);
    Assasin1.UseSkill();
    int Ak = Assasin1.Attack(Knight1);

    int HPK = Knight1.GetHP();
    int HPB = Berserk1.GetHP();
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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Assasin Assasin2;
    Berserk1.SetChance(0);
    Assasin2.SetChance(0);
    Knight1.SetChance(0);

    Berserk1.UseSkill();
    Assasin2.UseSkill();
    Knight1.UseSkill();

    Assasin1.SetChance(0);

    int ab = Assasin1.Attack(Berserk1);
    int aa = Assasin1.Attack(Assasin2);
    int ak = Assasin1.Attack(Knight1);

    Assasin1.SetChance(1);

    int Ab = Assasin1.Attack(Berserk1);
    int Aa = Assasin1.Attack(Assasin2);
    int Ak = Assasin1.Attack(Knight1);

    int HPK = Knight1.GetHP();
    int HPB = Berserk1.GetHP();
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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Assasin Assasin2;
    Berserk1.SetChance(1);
    Assasin2.SetChance(1);
    Knight1.SetChance(1);

    Berserk1.UseSkill();
    Assasin2.UseSkill();
    Knight1.UseSkill();

    Assasin1.SetChance(0);

    int ab = Assasin1.Attack(Berserk1);
    int aa = Assasin1.Attack(Assasin2);
    int ak = Assasin1.Attack(Knight1);

    Assasin1.SetChance(1);

    int Ab = Assasin1.Attack(Berserk1);
    int Aa = Assasin1.Attack(Assasin2);
    int Ak = Assasin1.Attack(Knight1);

    int HPK = Knight1.GetHP();
    int HPB = Berserk1.GetHP();
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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Assasin Assasin2;
    Berserk1.SetChance(0);
    Assasin2.SetChance(0);
    Knight1.SetChance(0);

    Berserk1.UseSkill();
    Assasin2.UseSkill();
    Knight1.UseSkill();

    Assasin1.SetChance(0);
    Assasin1.UseSkill();
    int ab = Assasin1.Attack(Berserk1);
    Assasin1.UseSkill();
    int aa = Assasin1.Attack(Assasin2);
    Assasin1.UseSkill();
    int ak = Assasin1.Attack(Knight1);

    Assasin1.SetChance(1);

    Assasin1.UseSkill();
    int Ab = Assasin1.Attack(Berserk1);
    Assasin1.UseSkill();
    int Aa = Assasin1.Attack(Assasin2);
    Assasin1.UseSkill();
    int Ak = Assasin1.Attack(Knight1);

    int HPK = Knight1.GetHP();
    int HPB = Berserk1.GetHP();
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
    Berserk Berserk1;
    Knight Knight1;
    Assasin Assasin1;
    Assasin Assasin2;
    Berserk1.SetChance(1);
    Assasin2.SetChance(1);
    Knight1.SetChance(1);

    Berserk1.UseSkill();
    Assasin2.UseSkill();
    Knight1.UseSkill();

    Assasin1.SetChance(0);
    Assasin1.UseSkill();
    int ab = Assasin1.Attack(Berserk1);
    Assasin1.UseSkill();
    int aa = Assasin1.Attack(Assasin2);
    Assasin1.UseSkill();
    int ak = Assasin1.Attack(Knight1);

    Assasin1.SetChance(1);

    Assasin1.UseSkill();
    int Ab = Assasin1.Attack(Berserk1);
    Assasin1.UseSkill();
    int Aa = Assasin1.Attack(Assasin2);
    Assasin1.UseSkill();
    int Ak = Assasin1.Attack(Knight1);

    int HPK = Knight1.GetHP();
    int HPB = Berserk1.GetHP();
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
    vector<shared_ptr<Character>> arr;
    arr.push_back(make_shared<Assasin>());
    arr.push_back(make_shared<Berserk>());
    arr.push_back(make_shared<Knight>());
    Container Array(arr);
    int minDamage = Array.GetMinDamage();

    EXPECT_EQ(minDamage, 0);
}
TEST(ContainerTests, ContainerTest2) {
    vector<shared_ptr<Character>> arr;
    arr.push_back(make_shared<Assasin>());
    arr.push_back(make_shared<Berserk>());
    arr.push_back(make_shared<Knight>());
    arr.push_back(make_shared<Knight>());
    Container Array(arr);
    Array.DeleteElem(3);

    EXPECT_EQ(Array[2].GetType(), "Knight");
    EXPECT_EQ(Array.GetSize(), 3);
}
TEST(ContainerTests, ContainerTest3) {
    vector<shared_ptr<Character>> arr;
    arr.push_back(make_shared<Assasin>());
    arr.push_back(make_shared<Berserk>());
    Container Array(arr);
    EXPECT_EQ(Array.GetSize(), 2);
    EXPECT_EQ(Array[Array.GetMinDamage()].GetDamage(), 100);
}




TEST(ContainerExceptionsTest, ContExceptionTest1) {
    Container Array;
    EXPECT_THROW(Array.GetMaxDamage(), logic_error);
}







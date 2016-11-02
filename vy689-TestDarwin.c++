// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

// ----
// test
// ----

TEST(DarwinFixture, addc_test1) {
  Species t('T');
  Creature t1(&t, 0);
  Darwin x(1, 1);
  x.addCreature(&t1, 0, 0);
  ASSERT_EQ(&t1, x.board[0][0]);
}

TEST(DarwinFixture, read_test1) {
  Species t('T');
  t.addInstruction("hop");
  ASSERT_EQ(1, t.readInstruction(0));
}

TEST(DarwinFixture, read_test2) {
  Species t('T');
  t.addInstruction("left");
  ASSERT_EQ(2, t.readInstruction(0));
}

TEST(DarwinFixture, read_test3) {
  Species t('T');
  t.addInstruction("right");
  ASSERT_EQ(3, t.readInstruction(0));
}

TEST(DarwinFixture, read_test4) {
  Species t('T');
  t.addInstruction("infect");
  ASSERT_EQ(4, t.readInstruction(0));
}

TEST(DarwinFixture, read_test5) {
  Species t('T');
  t.addInstruction("if_empty 0");
  ASSERT_EQ(5, t.readInstruction(0));
}

TEST(DarwinFixture, read_test6) {
  Species t('T');
  t.addInstruction("if_wall 0");
  ASSERT_EQ(6, t.readInstruction(0));
}

TEST(DarwinFixture, read_test7) {
  Species t('T');
  t.addInstruction("if_random 0");
  ASSERT_EQ(7, t.readInstruction(0));
}

TEST(DarwinFixture, read_test8) {
  Species t('T');
  t.addInstruction("if_enemy 0");
  ASSERT_EQ(8, t.readInstruction(0));
}

TEST(DarwinFixture, read_test9) {
  Species t('T');
  t.addInstruction("go 0");
  ASSERT_EQ(9, t.readInstruction(0));
}

TEST(DarwinFixture, read_go_test1) {
  Species t('T');
  t.addInstruction("go 1");
  ASSERT_EQ(19, t.readInstruction(0));
}

TEST(DarwinFixture, read_go_test2) {
  Species t('T');
  t.addInstruction("go 11");
  ASSERT_EQ(119, t.readInstruction(0));
}

TEST(DarwinFixture, read_go_test3) {
  Species t('T');
  t.addInstruction("go 111");
  ASSERT_EQ(1119, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifwall_test1) {
  Species t('T');
  t.addInstruction("if_wall 1");
  ASSERT_EQ(16, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifwall_test2) {
  Species t('T');
  t.addInstruction("if_wall 11");
  ASSERT_EQ(116, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifwall_test3) {
  Species t('T');
  t.addInstruction("if_wall 111");
  ASSERT_EQ(1116, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifenemy_test1) {
  Species t('T');
  t.addInstruction("if_enemy 1");
  ASSERT_EQ(18, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifenemy_test2) {
  Species t('T');
  t.addInstruction("if_enemy 11");
  ASSERT_EQ(118, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifenemy_test3) {
  Species t('T');
  t.addInstruction("if_enemy 111");
  ASSERT_EQ(1118, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifempty_test1) {
  Species t('T');
  t.addInstruction("if_empty 1");
  ASSERT_EQ(15, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifempty_test2) {
  Species t('T');
  t.addInstruction("if_empty 11");
  ASSERT_EQ(115, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifempty_test3) {
  Species t('T');
  t.addInstruction("if_empty 111");
  ASSERT_EQ(1115, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifrandom_test1) {
  Species t('T');
  t.addInstruction("if_random 1");
  ASSERT_EQ(17, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifrandom_test2) {
  Species t('T');
  t.addInstruction("if_random 11");
  ASSERT_EQ(117, t.readInstruction(0));
}

TEST(DarwinFixture, read_ifrandom_test3) {
  Species t('T');
  t.addInstruction("if_random 111");
  ASSERT_EQ(1117, t.readInstruction(0));
}

TEST(DarwinFixture, read_invalid_test) {
  Species t('T');
  t.addInstruction("Dummy");
  ASSERT_EQ(0, t.readInstruction(0));
}

TEST(DarwinFixture, icon_test) {
  Species t('T');
  ASSERT_EQ('T', t._icon);
}

TEST(DarwinFixture, icon_test2) {
  Species t;
  ASSERT_EQ('-', t._icon);
}

TEST(DarwinFixture, run_test) {
  Species t('T');
  t.addInstruction("left");
  Darwin x(1, 1);
  Creature t1(&t, 0);
  x.addCreature(&t1, 0, 0);
  x.turn();
  ASSERT_EQ(3, x.board[0][0]->_dir);
}

TEST(DarwinFixture, run_test2) {
  Species t('T');
  t.addInstruction("right");
  Darwin x(1, 1);
  Creature t1(&t, 0);
  x.addCreature(&t1, 0, 0);
  x.turn();
  ASSERT_EQ(1, x.board[0][0]->_dir);
}

TEST(DarwinFixture, run_test3) {
  Species t('T');
  t.addInstruction("go 2");
  t.addInstruction("left");
  t.addInstruction("right");
  Darwin x(1, 1);
  Creature t1(&t, 0);
  x.addCreature(&t1, 0, 0);
  x.turn();
  ASSERT_EQ(1, x.board[0][0]->_dir);
}

TEST(DarwinFixture, run_test4) {
  Species t('T');
  t.addInstruction("hop");
  Darwin x(2, 2);
  Creature t1(&t, 2);
  x.addCreature(&t1, 0, 0);
  x.turn();
  ASSERT_EQ(&t1, x.board[1][0]);
}

TEST(DarwinFixture, run_test5) {
  Species t('T');
  Species e('E');
  t.addInstruction("infect");
  Darwin x(2, 2);
  Creature t1(&t, 2);
  Creature e1(&e, 0);
  x.addCreature(&t1, 0, 0);
  x.addCreature(&e1, 1, 0);
  x.turn();
  ASSERT_EQ(&t, e1._s);
}

TEST(DarwinFixture, run_test6) {
  Species t('T');
  Species e('E');
  t.addInstruction("infect");
  Darwin x(2, 2);
  Creature t1(&t, 3);
  Creature e1(&e, 0);
  x.addCreature(&t1, 0, 0);
  x.addCreature(&e1, 1, 0);
  x.turn();
  ASSERT_EQ(&e, e1._s);
}

TEST(DarwinFixture, run_test7) {
  Species t('T');
  t.addInstruction("if_wall 2");
  t.addInstruction("hop");
  t.addInstruction("right");
  Darwin x(1, 1);
  Creature t1(&t, 0);
  x.addCreature(&t1, 0, 0);
  x.turn();
  ASSERT_EQ(1, t1._dir);
}

TEST(DarwinFixture, run_test8) {
  Species t('T');
  t.addInstruction("if_empty 2");
  t.addInstruction("right");
  t.addInstruction("hop");
  Darwin x(1, 1);
  Creature t1(&t, 0);
  x.addCreature(&t1, 0, 0);
  x.turn();
  ASSERT_EQ(1, t1._dir);
}

TEST(DarwinFixture, run_test9) {
  Species t('T');
  t.addInstruction("if_enemy 2");
  t.addInstruction("right");
  t.addInstruction("hop");
  Darwin x(1, 1);
  Creature t1(&t, 0);
  x.addCreature(&t1, 0, 0);
  x.turn();
  ASSERT_EQ(1, t1._dir);
}

TEST(DarwinFixture, run_test10) {
  Species t('T');
  t.addInstruction("right");
  t.addInstruction("if_empty 0");
  t.addInstruction("left");
  t.addInstruction("go 0");
  Darwin x(3, 3);
  Creature t1(&t, 0);
  x.addCreature(&t1, 1, 1);
  x.turn();
  ASSERT_EQ(1, t1._dir);
  x.turn();
  ASSERT_EQ(2, t1._dir);
  x.turn();
  ASSERT_EQ(3, t1._dir);
  x.turn();
  ASSERT_EQ(0, t1._dir);
}

TEST(DarwinFixture, run_test11) {
  Species t('T');
  t.addInstruction("right");
  t.addInstruction("if_wall 0");
  t.addInstruction("left");
  t.addInstruction("go 0");
  Darwin x(1, 1);
  Creature t1(&t, 0);
  x.addCreature(&t1, 0, 0);
  x.turn();
  ASSERT_EQ(1, t1._dir);
  x.turn();
  ASSERT_EQ(2, t1._dir);
  x.turn();
  ASSERT_EQ(3, t1._dir);
  x.turn();
  ASSERT_EQ(0, t1._dir);
}

TEST(DarwinFixture, run_test12) {
  Species t('T');
  t.addInstruction("hop");
  t.addInstruction("left");
  t.addInstruction("hop");
  t.addInstruction("left");
  t.addInstruction("hop");
  t.addInstruction("left");
  t.addInstruction("hop");
  Darwin x(2, 2);
  Creature t1(&t, 2);
  x.addCreature(&t1, 0, 0);
  x.turn();
  x.turn();
  x.turn();
  x.turn();
  x.turn();
  x.turn();
  x.turn();
  ASSERT_EQ(&t1, x.board[0][0]);
}

TEST(DarwinFixture, run_test13) {
  Species t('T');
  Species e('E');
  t.addInstruction("infect");
  t.addInstruction("left");
  t.addInstruction("infect");
  t.addInstruction("left");
  t.addInstruction("infect");
  t.addInstruction("left");
  t.addInstruction("infect");
  Darwin x(3, 3);
  Creature t1(&t, 0);
  Creature e1(&e, 0);
  Creature e2(&e, 0);
  Creature e3(&e, 0);
  Creature t2(&t, 0);
  x.addCreature(&t1, 1, 1);
  x.addCreature(&e1, 0, 1);
  x.addCreature(&e2, 2, 1);
  x.addCreature(&e3, 1, 0);
  x.addCreature(&t2, 1, 2);
  x.turn();
  x.turn();
  x.turn();
  x.turn();
  x.turn();
  x.turn();
  x.turn();
  ASSERT_EQ(&t, t2._s);
  ASSERT_EQ(&t, e1._s);
  ASSERT_EQ(&t, e2._s);
  ASSERT_EQ(&t, e3._s);
}

TEST(DarwinFixture, darwin_con_test) {
  Darwin x(1, 1);
  ASSERT_EQ(1, x.board.size());
  ASSERT_EQ(1, x.board[0].size());
}

TEST(DarwinFixture, darwin_con_test2) {
  Darwin x(2, 2);
  ASSERT_EQ(2, x.board.size());
  ASSERT_EQ(2, x.board[0].size());
}

TEST(DarwinFixture, darwin_con_test3) {
  Darwin x(1, 100);
  ASSERT_EQ(1, x.board.size());
  ASSERT_EQ(100, x.board[0].size());
}

TEST(DarwinFixture, c_con_test) {
  Species t('T');
  Creature t1(&t, 0);
  ASSERT_EQ(&t, t1._s);
  ASSERT_EQ(0, t1._dir);
}

TEST(DarwinFixture, c_con_test2) {
  Species t('T');
  Creature t1(&t, 1);
  ASSERT_EQ(&t, t1._s);
  ASSERT_EQ(1, t1._dir);
}

TEST(DarwinFixture, s_con_test) {
  Species t('T');
  ASSERT_EQ('T', t._icon);
  ASSERT_EQ(0, t.inList.size());
}

TEST(DarwinFixture, s_con_test2) {
  Species t('H');
  ASSERT_EQ('H', t._icon);
  ASSERT_EQ(0, t.inList.size());
}

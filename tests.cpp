//test file
/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 11

this is the test file for this lab

*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

#include <iostream>
#include <string>

TEST_CASE("Teting Part A functions: making a profile and getting the username, full name and display"){
  Profile p1 = {"marco", "Marco"};
  Profile p2 ={"mario", "Mario"};
  CHECK(p1.getUsername() == "marco");
  CHECK(p1.getDisplayname() == "Marco");
  CHECK(p1.getFullName() == "Marco (@marco)");
  p1.setDisplayName("Marco Rossi");
  CHECK(p1.getDisplayname() == "Marco Rossi");
  CHECK(p2.getUsername() == "mario");
  CHECK(p2.getDisplayname() == "Mario");
  CHECK(p2.getFullName() == "Mario (@mario)");
  p2.setDisplayName("Mario Mario");
  CHECK(p2.getDisplayname() == "Mario Mario");


  p2 = {"luigi", "Luigi"};
  p1 ={"yoshi", "Yoshi"};
  CHECK(p1.getUsername() == "yoshi");
  CHECK(p1.getDisplayname() == "Yoshi");
  CHECK(p1.getFullName() == "Yoshi (@yoshi)");
  p1.setDisplayName("Yoshi the Dino");
  CHECK(p1.getDisplayname() == "Yoshi the Dino");
  CHECK(p2.getUsername() == "luigi");
  CHECK(p2.getDisplayname() == "Luigi");
  CHECK(p2.getFullName() == "Luigi (@luigi)");
  p2.setDisplayName("Luigi Mario");
  CHECK(p2.getDisplayname() == "Luigi Mario");
}

TEST_CASE("Task B"){
  Network nw;
  CHECK(nw.addUser("mario", "Mario") == true);
  CHECK(nw.addUser("mario2", "Mario2") == true);
  CHECK(nw.addUser("mario3", "Mario3") == true);
  CHECK(nw.addUser("mario4", "Mario4") == true);
  CHECK(nw.addUser("mario 1", "Mario") == false);
  CHECK(nw.addUser("mario-2", "Mario") == false);
  CHECK(nw.addUser("M ario-2", "Mario") == false);
}

TEST_CASE("Task C"){
  Network nw;
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");

  CHECK(nw.follow("mario","luigi") == true); // mario luigi true
  CHECK(nw.follow("luigi","yoshi") == true); //luigi yoshi true
  CHECK(nw.follow("wario","mario") == false); //warior mario false
}

TEST_CASE("Task D"){
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");

  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  CHECK(nw.writePost("mario", "It's a-me, Mario!") == true);
  CHECK(nw.writePost("luigi", "Hey hey!") == true);
  CHECK(nw.writePost("mario", "Hi Luigi!") == true);
  CHECK(nw.writePost("yoshi", "Test 1") == true);
  CHECK(nw.writePost("wario", "Test 1") == false);
  
}

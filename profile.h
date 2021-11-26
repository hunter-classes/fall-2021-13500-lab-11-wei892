/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab11

this is the header file for the profile functions
it contains the profile class
*/


#pragma once
#include <string>

class Profile {
 private:
  std::string username;
  std::string displayname;

public:
  // Profile constructor for a user (initializing
  // private variables username=usrn, displayname=dspn)
  Profile(std::string usrn, std::string dspn);

  // Default Profile constructor (username="", displayname="")
  Profile();

  // Return username
  std::string getUsername();

  //Return the displayname
  std::string getDisplayname();
  
  // Return name in the format: "displayname (@username)"
  std::string getFullName();

  // Change display name
  void setDisplayName(std::string dspn);
};

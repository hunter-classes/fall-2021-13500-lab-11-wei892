/*
Name: Wei Lin Li
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 11

this is the cpp file for the functions of the profile class

*/

#include "profile.h"
#include <string>

/*
  basic constructor for profile which contains username and displayname
 */
Profile::Profile(){
  username = "";
  displayname = "";
}

/*
  constructor for profile
  @param std::string username which will set the variable username
  @param std::string dspn will set the value for the variable display name 
 */
Profile::Profile(std::string usrn, std::string dspn){
  username = usrn;
  displayname = dspn;
}

/*
  function for getting the username of the profile
  used as profile_name.getUsername();
  no parameters needed

  @returns the username of the profile
 */
std::string Profile::getUsername(){
  return username;
}

/*
  used as profile_name.getDisplayname();
  no parameters needed

  @returns the displayname of the profile
 */
std::string Profile::getDisplayname(){
  return displayname;
}

/*
  used as profile_name.getFullName();
  no parameters needed

  @returns the full name with the desired format
 */
std::string Profile::getFullName(){
  std::string output = displayname + " (@" + username + ")";
  return output;
}

/*
  sets the display to the new value passed in
  @param string displayname
 */
void Profile::setDisplayName(std::string dspn){
  displayname = dspn;
}

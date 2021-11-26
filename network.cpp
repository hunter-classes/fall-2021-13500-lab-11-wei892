#include "profile.h"
#include "network.h"

#include <iostream>
#include <string>
#include <cctype>

int Network::findID(std::string usern){
  bool foundID = false;
  int location;
  for (int i = 0; i < MAX_USERS; i++){
    if (profiles[i].getUsername() == usern){
      return i;
    }
  }
  
  return -1;
}

Network::Network(){
  numUsers = 0;

  for (int i = 0; i < MAX_USERS; i++){
    for (int j = 0; j < MAX_USERS; j++){
      following[i][j] = false;
    }
  }

  numPosts = 0;
}

bool Network::addUser(std::string usern, std::string dspn){
  //check if 20 users
  if (numUsers == 20){
    return false;
  }
  /*
  for (int i = 0; i < MAX_USERS; i++){
    //if there is matching usernames
    if (usern == profiles[i].getUsername()){
      return false;
    }
  }
  */
  if (findID(usern) != -1){
    return false;
  }

  //checks if alphanum
  for (int i = 0; i < usern.length(); i++){
    char c = usern[i];
    if (!isalnum(c)){
      return false;
    }
  }
  

  //if all conditions are passed,
  numUsers++;
  profiles[numUsers - 1] = {usern, dspn};
  return true;
}

std::string isTrue(bool b){
  if (b == true){
    return "True";
  }
  else {
    return "False";
  }
}

bool Network::follow(std::string usrn1, std::string usrn2){
  if (findID(usrn1) == -1 || findID(usrn2) == -1){
    return false;
  }
  //std::cout << "user1: " << usrn1 << std::endl;
  //std::cout << "user2: " << usrn2 << std::endl;
  following[findID(usrn1)][findID(usrn2)] = true;
  //std::cout << usrn1 << " is following " << usrn2 << std::endl;
  return true;
}

void Network::printDot(){
  std::cout << "disgraph {\n";
  for (int i = 0; i < numUsers; i++){
    std::cout << "\t\"@" << profiles[i].getUsername() << "\"" << std::endl;
  }

  std::cout << "\n" << std::endl;
 
  for (int i = 0; i < numUsers; i++){
    for (int j = 0; j < numUsers; j++){
      if (following[i][j] == true){
	std::cout << "\t\"@" << profiles[i].getUsername() << "\" -> " << "\"@" << profiles[j].getUsername() << "\""<< std::endl;
	//std::cout << "i: " << std::to_string(i) << " " << profiles[i].getUsername() << std::endl;
	//std::cout << "j: " << std::to_string(j) << " " << profiles[j].getUsername() << "\n" << std::endl;
      }
    }
  }  

  std::cout << "}" << std::endl;
}



bool Network::writePost(std::string usrn, std::string msg){
  if (numPosts == 100){
    return false;
  }
  
  if (findID(usrn) == -1){
    return false;
  }

  Post newPost = {usrn, msg}; 
  posts[numPosts] = newPost;
  numPosts++;
  return true;
}


bool Network::printTimeline(std::string usrn){
  //for (int i = numPosts-1; i >= 0; i--){
  //std::cout << std::to_string(i) << std::endl;
  //}
  //return true;
  if (findID(usrn) == -1){
    return false;
  }

  int x = findID(usrn);
  
  for (int i = numPosts-1; i >= 0; i--){
    int y = findID(posts[i].username);

    if (following[x][y] == true || posts[i].username == usrn){
      //print out their own posts
      //print the person they follow posts
      std::string m = posts[i].message;
      std::cout << profiles[findID(posts[i].username)].getFullName() << ": " << m << std::endl;
    }
    
    
    
    //std::string m = posts[i].message;
    //std::cout << profiles[findID(posts[i].username)].getFullName() << ": " << m << std::endl;
  }
  
  return true;
}

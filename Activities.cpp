#include "Activities.h"
#include <iostream> 
#include <stdlib.h>

using namespace std; 

void Activities :: exploreRoom()
{
    //add 20% chance for each outcome of explore room and implement each outcome
}

int Activities :: display()
{
    //display the players current stats and what the options they have once they enter the room 
    cout << "WOULD YOU LIKE TO" << endl <<  "(1) FIGHT A MONSTER" << endl << "(2) SPEAK TO NPC" << endl << "(3) COOK & EAT" << endl << "(4) EXPLORE THE ROOM" << endl << "(5) OPEN THE DOOR" << endl << "(6) QUIT?" << endl;
    bool test = false; 
    while(test == false)
    {
         string choice;
        cin >> choice; 
        if(choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6")
        {
            cout << "Invalid Input. Try Again." << endl;
        }
        if(choice == "2")
        {
          return 2;
        }
        if(choice == "3")
        {
            return 3;
        }
        if(choice == "4")
        {
            return 4;
        }
        if(choice == "5")
        {
            return 5;
        }
        if(choice == "6")
        {
            return 6; 
        }
        if(choice == "1")
        {
            return 1; 
        }

    }
    return -1;
} 
void Activities :: setKey(bool k)
{
    key = k; 
}
bool Activities :: getKey()
{
   return key; 
}
void Activities :: setTreasure(bool t)
{
    treasure = t; 
}
bool Activities :: getTreasure()
{
    return treasure; 
}
void Activities :: setRoom(int r,string s)
{
    rooms[r] = s; 
}
string Activities :: getRoom(int i)
{
    if(i < 5)
    {
    return rooms[i]; 
    }
    return "done"; 
}       
void Activities :: setTreasure(int i, int a, string t)
{
    treasures[i][a] = t;
}
string Activities :: getTreasure(int i, int a)
{
    string t = treasures[i][a];
    return t;
}
void Activities :: setAngerLevel(int a)
{
    angerLevel = a; 
}
int Activities :: getAngerLevel()
{
    return angerLevel; 
}
int Activities :: getR()
{
    return room; 
}
void Activities :: setR(int r)
{
    room = r;
}

int Activities :: cook()
{
    // call this function if the player wants to cook their food
      cout << "What would you like to cook with?" << endl 
      << "Remember you must have the cookware if you want to cook with it." << endl
      << "1. Cauldron" << endl
      << "2. Cast Iron" << endl
      << "3. Ceramic Pot" << endl; 
      string cook;
      cin >> cook; 
      if(cook != "3" && cook != "2" && cook != "1")
      {
        cout << "Invalid Input. Try Again." << endl; 
      }
      if(cook == "3")
      {
          return 3; 
      }
      if(cook == "2")
      {
          return 2;
      }
      if(cook == "1")
      {
          return 1; 
      }
      return 0; 
} 







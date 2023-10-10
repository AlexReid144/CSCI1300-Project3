  #include "Misfortunes.h"
  #include <string>
  #include <iostream> 

  void Misfortunes :: robbed()
  {
      //Your team is robbed of food or cookware or armor chosen randomly. Print a message announcing the misfortune:
      cout << endl << "OH NO! Your team was robbed by dungeon bandits! You have no food/cookware/armor left!" <<endl; 
  }
    void Misfortunes :: breaks()
    {
        //One of the weapons/armor breaks. Print a message announcing the misfortune
        cout << endl <<  "OH NO! One of your weapons/armor broke!" << endl; 
    }
    void Misfortunes :: hunger()
    {
        //Death by Hunger: If any of your team members' fullness levels reaches 0 at the end of a turn, they effectively die by hunger. 
        //If the party does not have enough members to complete the journey, the game ends.
        cout << endl << "OH NO! one of your teammates has died of hunger! Your party size has reduced to "; 
    }
    void Misfortunes :: locked()
    {
        //Team member locked in the previous room - This misfortune can only happen if a player tries to open the door with the key. 
        //One player at random (never the team leader) gets chosen to be locked behind in the previous room
        cout << endl << "OH NO! Your teammate John is trapped in the previous room, and is unable to get through. You must continue without him. Your party size has reduced to ";
    }
    int Misfortunes :: random()
    {
        //returns a random number 1 -10 
        int ran = (rand() % 10) + 1;
        return ran; 
    }

#include "Player.h"

#include <iostream>

using namespace std; 


    void Player :: setName(string n)
    {
        name = n; 
    }
    string Player :: getName()
    {
        return name; 
    }
    void Player :: setGold(int g)
    {
        gold = g;
    }
    int Player :: getGold()
    {
        return gold; 
    }
    void Player :: setingredients(int i)
    {
        //each ingredient purchased by the player costs 1 gold piece per kilgram; subtract that from the gold total of the player 
        ingredients = i;
    }
    int Player :: getingredients()
    {
        return ingredients; 
    }
    void Player :: setweapons(string w)
    {
        //depending on the weapon he chose subtract the cost of that from the players gold
        weapons = w; 
    }
    string Player :: getweapons()
    {
        return weapons; 
    }
    void Player :: setarmor(bool a)
    {//if player adds armor subtract 5 gold from player
        armor = a; 
    }
    bool Player :: getarmor()
    {
        return armor;
    }
    void Player :: setcookware(string c)
    {
        //depending on the cookware chosen subtract certain amount of gold from players gold total
        cookware = c; 
    }
    string Player :: getcookware()
    {
        return cookware; 
    }
    void Player :: setfullnesspoints(int f)
    {
        fullnesspoints = f; 
    }
    int Player :: getfullnesspoints()
    {
        return fullnesspoints; 
    }
    bool Player :: ifLeader()
    {
        return leader;
    }
    void Player :: setAlive(bool alive1)
    {
        alive = alive1;
    }
    bool Player :: getAlive()
    {
        return alive; 
    } 


#include "Monsters.h"
#include <string> 
#include <iostream> 
#include <cmath>

using namespace std; 

    bool Monsters :: getBattle()
    {
        return battle; 
    }
    void Monsters :: setBattle(bool b)
    {
        battle = b; 
    }
    int Monsters :: getRoom()
    {
        return room; 
    }
    void Monsters :: setRoom(int r)
    {
        room = r; 
    }
    void Monsters :: roomOne()
    {
        //load file with room one monsters and call either attack or surrender
    }
    void Monsters :: roomTwo()
    {
        //load file with room two monsters and call either attack or surrender
    }
    void Monsters :: roomThree()
    {
        //load file with room three monsters and call either attack or surrender       
    }
    void Monsters :: roomFour()
    {
        //load file with room four monsters and call either attack or surrender
    } 
    void Monsters :: roomFive()
    {
        //load file with room five monsters and call either attack or surrender
    } 
    bool Monsters :: attack(int weap, int a, int d)
    {
        //part of the battle method(gets called in the battle method)
        //implement algorithm to see whether or not they players will defeat the monsters and act accordingly
        int ran = (rand() % 6) + 1;
        int ran2 = (rand() % 6) + 1;
        double battle = (double)((ran * weap) + d);
        int rom = getRoom();
        double battle2 = ran2 * rom; 
        battle2 = battle2 / a;
        battle = battle - battle2; 
        if(battle > 0)
        {
            return true; 
        }
        else
        {
            return false; 
        }
    } 
    void Monsters :: surrender()
    {
        // if players choose to surrender pick one player to get captured by the monster randomly and let the others move on
        cout << "You have surrendered to the monster, Now you lose one Player. Lets see if you can make it out." <<endl; 
    }
    string Monsters :: getMonster1()
    {
        bool mon = false;
        while(mon == false)
        {
             int ran = (rand() % 4); 
             if(monster1[ran] != "")
             {
                 string m = monster1[ran]; 
                 monster1[ran] = ""; 
                 mon = true;
                 return m; 
             }
        }
       return ""; 
    }
    string Monsters :: getMonster2()
    {
        bool mon = false;
        while(mon == false)
        {
             int ran = (rand() % 4); 
             if(monster2[ran] != "")
             {
                 string m = monster2[ran]; 
                 monster2[ran] = ""; 
                 mon = true;
                 return m; 
             }
        }
        return ""; 
    }
    string Monsters :: getMonster3()
    {
        bool mon = false;
        while(mon == false)
        {
             int ran = (rand() % 4); 
             if(monster3[ran] != "")
             {
                 string m = monster3[ran]; 
                 monster3[ran] = ""; 
                 mon = true;
                 return m; 
             }
        }
        return ""; 
    }
    string Monsters :: getMonster4()
    {
        bool mon = false;
        while(mon == false)
        {
             int ran = (rand() % 4); 
             if(monster4[ran] != "")
             {
                 string m = monster4[ran]; 
                 monster4[ran] = ""; 
                 mon = true;
                 return m; 
             }
        }
        return "";
    }
    string Monsters :: getMonster5()
    {
        bool mon = false;
        while(mon == false)
        {
             int ran = (rand() % 4); 
             if(monster5[ran] != "")
             {
                 string m = monster5[ran]; 
                 monster5[ran] = ""; 
                 mon = true;
                 return m; 
             }
        }
       return "";
        return ""; 
    }
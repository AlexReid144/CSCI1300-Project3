#include <string> 
#include <vector> 

using namespace std;
class Player
{
    public:
    Player()
    {
        name = ""; 
        gold = 100; 
        ingredients = 0; 
        weapons = ""; 
        armor = false; 
        cookware = ""; 

    }
    Player(string n, bool lead)
    {
        name = n;
        if(lead == true)
        {
            gold = 100; 
        }
        else
        {
            gold = 0; 
        }
        leader = lead; 
        cookware = "";
        alive = true; 
        fullnesspoints = 10; 
        ingredients = 0; 
       // ingredients = ingredients1;
        //weapons = weapons1; 
        //armor = armor1;  
       // cookware = cookware1; 
    }
    void setName(string n); 
    string getName(); 
    void setGold(int g); 
    int getGold();
    void setingredients(int i);
    int getingredients();
    void setweapons(string w);
    string getweapons();
    void setarmor(bool a);
    bool getarmor();
    void setcookware(string c);
    string getcookware(); 
    void setfullnesspoints(int f);
    int getfullnesspoints(); 
    bool ifLeader(); 
    void setAlive(bool alive1);
    bool getAlive(); 


    private:
    string name; 
    int gold;
    int ingredients; 
    string weapons; 
    bool armor; 
    string cookware; 
    int fullnesspoints;  
    bool leader; 
    bool alive; 
    
};

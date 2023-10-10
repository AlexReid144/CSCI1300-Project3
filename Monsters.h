#include <fstream> 
#include <vector> 
#include <string> 
class Monsters
{
    public:
    Monsters()
    {
        room = 1; 
        monster1.push_back("Animated armor");
        monster1.push_back("Bugbear");
        monster1.push_back("Harpy");
        monster1.push_back("Scarecrow");
        monster2.push_back("Minotaur");
        monster2.push_back("Owlbear");
        monster2.push_back("Banshee");
        monster2.push_back("Wereboar");
        monster3.push_back("Giant crocodile");
        monster3.push_back("Troll");
        monster3.push_back("Hobgoblin warlord");
        monster3.push_back("Mammoth");
        monster4.push_back("Stone giant");
        monster4.push_back("Night hag");
        monster4.push_back("Assassin");
        monster4.push_back("Hydra");
        monster5.push_back("Cloud giant");
        monster5.push_back("Silver dragon");
        monster5.push_back("Vampire");
        monster5.push_back("Lich");

    }
    Monsters(int r)
    {
        room = r; 
    }
    bool getBattle();
    void setBattle(bool b);
    int getRoom();
    void setRoom(int r);
    void roomOne();
    void roomTwo(); 
    void roomThree(); 
    void roomFour(); 
    void roomFive(); 
    bool attack(int weap, int a, int d); 
    void surrender(); 
    string getMonster1();
    string getMonster2();
    string getMonster3();
    string getMonster4();
    string getMonster5(); 

    private:
    int room; 
    bool battle; 
    vector<string> monster1;
    vector<string> monster2;
    vector<string> monster3;
    vector<string> monster4; 
    vector<string> monster5; 

};
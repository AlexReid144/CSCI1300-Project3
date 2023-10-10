#include <string> 
#include <fstream>
#include <iostream>
using namespace std; 
class Puzzles
{
    public: 
    Puzzles()
    { 
        int raz = 0;
        riddles[0] = "I’m tall when I’m young, and I’m short when I’m old. What am I?";
        riddles[1] = "What is full of holes but still holds water?";
        riddles[2] = "What is always in front of you but can’t be seen?";
        riddles[3] = "What goes up but never comes down?";
        riddles[4] = "What gets wet while drying?";
        riddles[5] = "What can’t talk but will reply when spoken to?";
        riddles[6] = "The more of this there is, the less you see. What is it?";
        riddles[7] = "What has many keys but can’t open a single lock?";
        riddles[8] = "What gets bigger when more is taken away?";
        riddles[9] = "Where does today come before yesterday?";
        answers[0] = "Candle";
        answers[1] = "Sponge";
        answers[2] = "Future";
        answers[3] = "Age";
        answers[4] = "Towel";
        answers[5] = "Echo";
        answers[6] = "Darkness";
        answers[7] = "Piano";
        answers[8] = "Hole";
        answers[9] = "Dictionary";

    }
 
    string getRiddleAt(int i);
    void setRiddleAt(int i, string rid); 
    void Riddle();
    bool GoodNPC(); 
    void BadNPC(); 
    void NeutralNPC(); 
    string getAnswersAt(int i);
    void setR(int r1);
    int getR();
    bool door(int num);


    private: 
    string riddles[10]; 
    string answers[10]; 
    int raz; 
}; 
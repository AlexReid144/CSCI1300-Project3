
class Misfortunes
{
    public:
    Misfortunes()
    {
        result = 0; 
    }
    Misfortunes(int r)
    {
        result = r; 
    }
    void robbed(); 
    void breaks();
    void hunger(); 
    void locked(); 
    int random(); 
    private: 
    int result; //what misfortune occurs 
};
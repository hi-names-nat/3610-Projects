/*******************************
 * 
 * Name: marked.h
 * 
 * desc: simple class to make showPrimes program simpler.
 * 
 **/

class markedInt
{
private:
    int value;
    bool marked;

public:
    markedInt(int newVal, int newMar)
    {
        value = newVal;
        marked = newMar;
    }

    markedInt()
    {
        value = 0;
        marked = false;
    }

    int getValue()
    {
        return value;
    }
    bool getMarked()
    {
        return marked;
    }

    void setMarked(bool newmarked)
    {
        marked = newmarked;
    }

    void setVal(int newVal)
    {
        value = newVal;
    }
};

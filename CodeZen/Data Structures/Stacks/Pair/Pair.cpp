template <typename T>
class Pair
{
private:
    T x;
    T y;

public:
    void setX(T x)
    {
        this->x = x;
    }
    T getX()
    {
        return x;
    }
    void setY(T y)
    {
        this->y = y;
    }
    T getY()
    {
        return y;
    }

    // Pair(/* args */);
    // ~Pair();
};

// Pair::Pair(/* args */)
// {
// }

// Pair::~Pair()
// {
// }

#include <iostream>
#include <string>

using namespace std;


class Rect{

    private:
        float width;
        float height;


    public:
    //constructor
        Rect(float width = 0, float height = 0)
        {
            this->width = width;
            this->height = height;

        }

        virtual float getArea() const 
        {
            return (width * height);
        }

        void  updateWidth(float newwidth) //update function
        {
            width = newwidth;//update width
        } 

        void updateHeight(float newheight) //update function with new parameter 
        {
            height = newheight;
        }
};

class Square: public Rect
{
    private:
        float side;

    public:

        Square(float side):Rect(0,0)// height, widht is also 0 initially
        {
            this->side= side;

        }
        virtual float getArea() const
        {
            return (side * side);
        }


};


int main(){

    Rect r1(4,6);
    cout << "Area is: " << r1.getArea() << endl;

    r1.updateWidth(37);
    cout << "Area is: " << r1.getArea() << endl;

    r1.updateHeight(45);
    cout << "Area is: " << r1.getArea() << endl;

    Square s1(7);
    cout << "Area of square is: " << s1.getArea() << endl;
    cout << "Area of square is: " << s1.Rect::getArea() << endl;

    return 0;
}
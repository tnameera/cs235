#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>


class Rectangle	// This is the base class!
{
public:
        Rectangle();
        Rectangle(double width,double height);
        ~Rectangle(); //destructor
        double  getWidth() const;
        double  getHeight() const;
        void setWidth(double width);
        void setHeight(double height); 
        double getArea() const;
        double getPerimeter() const;
        virtual std::string to_string() const;


private:
        double width;
        double height;
    
        
};
#endif 

#include "Rectangle.hpp"
#include <iostream>

//setting values for default data memebers
//Recatangle::Recatangle()// constructor
//{
//width = 0; 
//height = 0;
//}

//setting values for default data memebers
/*
Rectangle::Rectangle()// constructor
{
    width = 0; 
    height = 0;
}
*/

Rectangle::Rectangle()// constructor
{
    setWidth(0); 
    setHeight(0);
}

//setting values for non- default data memebers here 
//add new parameter to refer them to the default such as w = width
/*
Rectangle::Rectangle(int w,int h)
{
    width = w;// 
    height = h;
}
*/

Rectangle::Rectangle(double w,double h)
{
    setWidth(w);// 
    setHeight(h);
}

//incase the new argments and existing arguments had the same name 
//use "this->width" to refer the exitign and "width" to new  

//Recatangle::Rectangle(int width,int height) //destructor
//{
//    this->width = width;// 
//    this->height = height;
        //setWidth(width);
        //setHeight(height);
//}

Rectangle::~Rectangle() //destructor
{

}

double Rectangle::getWidth() const
{
    return width;
}

double Rectangle::getHeight() const
{
    return height;
}

//make sure to right width =  newwidth not the other way
void Rectangle::setWidth(double newWidth)
{
    width = newWidth;
}

void Rectangle::setHeight(double newHeight)
{
    height = newHeight;
}

//set the are fouma and then return to get the return
double Rectangle::getArea() const
{
    //double area = (width * height);
    //return area;
    return (width * height);
    
}

//set the area formula for perimeter 
double Rectangle::getPerimeter() const
{
    return(width*width + height*height);
    
}

//std::string Rectangle::to_string() const
//{
//   std::string result;
//    result = "Rectangle widht: " + width + "Rectangle height: " + width
//    return result;
//   
//}

std::string Rectangle::to_string() const
{
    std::string result = "This is a Rectangle:  ";
    return result;
    

}
        
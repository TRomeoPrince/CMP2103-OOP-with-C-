#include <iostream>
using namespace std;
class Rectangle{
private: // variables go here
double length;
double width;

public:  
// functions go here  

 
double getLength(){
return length;
}
 
double getWidth(){
return width;
}

void setLength (double newLength){  
    length = newLength;  
}  
void setWidth (double newWidth){  
    width = newWidth;  
}  

double calculateArea(){  
double Area = width*length;  
return Area;  
}  

double calculatePerimeter(){  
    double Perimeter = 2(length + width);  
    return Perimeter;  
}
};
int main (){
    Rectangle r1; //Object in class
    r1.setLength(10);
    r1.setWidth(5); //sets dimensions
cout << "Length is: " << r1.getLength() << "\n";
cout << "width is: " << r1.getWidth() << "\n"; //outputs saved dimoneion
    cout << "The Area is: " << r1.calculateArea() << "\n";
    cout << "The Perimeter is: " << r1.calculatePerimeter() << "\n";

return 0;  

 
}
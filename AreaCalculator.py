#Analysis-Design and develop a program that computes the area of a triangle,
#a rectangle and a circle。Using input parameters, function definitions, return
#and print the result using round functions.

#Reference
#Triangle:
#area = ½ * base * height
#Rectangle:
#area = width * height
#Circle:
#area = PI * radius2

#Input-width,height,base,radius(Float,length)
#Output-area(Float)

#Import math library to use value of PI
import math

#Function definition for area of a rectangle
#input parameters: width, height
def areaRectangle(width,height):
    #return value: area
    return(width*height)

#Function definition for area of a triangle
#input parameters: base, height
def areaTriangle(base,height):
    #return value: area
    return(0.5 * base * height)

#Function definition for area of circle
#input parameter: radius
def areaCircle(radius):
    #return value: area
    return(math.pi*math.pow(radius,2))

#Program description
print("Design and develop a program that computes the area of a triangle,a rectangle,and a circle.For the triangle,prompt the user for both the base and the height.For the rectangle,prompt the user for both the width and the height.For the circle,prompt the user for the radius.")

# Main program
def main():
    
    #Triangle
    print("Triangle")
    #Prompt user for triangle base and height
    base=float(input("Enter base:"))
    height=float(input("Enter height:"))
    #Call function to compute area of triangle
    #-pass base and height as function parameters
    #-assign function result to a variable
    area=areaTriangle(base,height)
    # Print result to 2-digit precision
    print("Area of Triangle=",round(area,2))
    
    #Rectangle
    print("Rectangle")
    #Prompt user for rectangle width and height
    width=float(input("Enter width:"))
    height=float(input("Enter height:"))
    #Call function to compute area of rectangle
    #-pass width and height as function parameters
    #-assign function result to a variable
    area=areaRectangle(width,height)
    #Print result to 2-digit precision
    print("Area of Rectangle=",round(area,2))
    
    #Circle
    print("Circle")
    #Prompt user for circle radius
    radius=float(input("Enter radius:"))
    #Call function to compute area of triangle
    #-pass radius as function parameter
    #-assign function result to a variable
    area=areaCircle(radius)
    #Print result to 2-digit precision
    print("Area of Circle=",round(area,2))

#Call main program   
main()

   

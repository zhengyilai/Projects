#Analysis-The user can input the number of circle and found the circle they
#want that fit in the window.
#Design and develop a program to draw a specified number of 2D circles
#in alternating fill colors using for loops and decision structure. 
#Input=Number of circle(int)
#Output=Red and black circle

#Print the program description
print("Design and develop a program to draw a specified number of 2D circles")
print("in alternating fill colors.")

#Prompt user to input the number of circle.
numCircle=int(input("Enter number of circle:"))

#Import Graphic Library
import graphics
from graphics import*

#Naming the window and size
win=GraphWin("Circle",400,400)

#Set up coordinates
win.setCoords(0.0,0.0,100.0,100.0)

#Set up the background color
win.setBackground("Grey")

#Loop for circle
for i in range(numCircle):
#Print the remainder of the loop to find out loop index is odd or even.
       print(i%2)
#Radius
       radius1=50/numCircle
       
#Distance between the circle
       Distance=numCircle-i
      
#Loop index is even,so the remainder=0
#Remainder=0,fill the circle with black colour
       if i%2==0:
#Black circle
          c3=Circle(Point(50,50),Distance*radius1)
#Input colour
          c3.setFill("black")
#Input Width
          c3.setWidth(4)
#Draw it in the window
          c3.draw(win)
#Loop index is odd,so the remainder=1
#Remainder=1,fill the circle with red colour
#We use else instead of if
       else:
#Red circle
          c2=Circle(Point(50,50),Distance*radius1)
#Input colour
          c2.setFill("red")
#Input Width
          c2.setWidth(4)
#Draw it in the window
          c2.draw(win)

               
#This is the hardest lab I had so far, it takes me a lot of time to finish it.
#From this lab, I learned that a small mistakes will cause different output.


       
       

   

    


   

#Analysis-The user wants to find a hypotenuse we need to use the equation below.
#Equation:Hypotenuse=math.sqrt((sidea)**2+(sideb)**2)
#Input-sidea (Float)
#Input-sideb (Float)
#Calculation-Hypotenuse=math.sqrt((sidea)**2+(sideb)**2)
#Output-Hypotensus (Float)


#Print the program description
print("This program computes the hypotenuse for 3 different sized triangles specified by side lengths entered by the user.")
#Import the math library here (in order to use its square root function)
import math
#Define the main program
def main():
#Use a definite for loop to repeat instructions for 3 triangles
#Repeat for three triangles
#It is because the phyton loop start with zero, we need to plus 1 in the print section
     for i in range(3):
         print("Triangle",i+1)
#Prompt user for lengths of side a and side b
#Since we learned the definition of Float and interger,We use float instead of eval
         sidea=float(input("Enter length of side a:"))
         sideb=float(input("Enter length of side b:"))
#Compute the hypotenuse using the math.sqrt function
#Print the results with no more than 2 digits of precision after the decimal point
#Using the math.pow instead of **
         Hypotenuse= math.sqrt(math.pow(sidea,2)+math.pow(sideb,2))
         print("The hypotenuse is:",round(Hypotenuse,2))
#Execute the main program
main()




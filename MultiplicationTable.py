#Analysis-Using sentinel loop,nested loop,for loop,if-elif-else and prompt user
#to input interger to select option from the menu
#and output a multiplication table or quit the program.
#Design and develop a program to print a multiplication table.
#Prompt the user with the following menu:
#1)Create a multiplication table
#2)Quit the program
#If the user selects menu option 1, prompt the user to enter an integer between 1
#and 10
#and print a multiplication table showing the results of multiplying the integers 1
#through the input integer 
#If the user selects menu option 2, exit the program.
#If the user enters anything but 1 or 2 as the menu selection,
#output the message “Incorrect menu selection,
#please try again” and continue the program.
#Input-interger
#Output-interger


#Program Description
print("Design and develop a program to print a multiplication table.")
print()
print()
#True value of the sentinel loop
keepLooping=True
#Sentinel loop
while(keepLooping):
    #Present the menu
    print("=====================")
    print("Multiplication Tables")
    print("=====================")
    print("1) Create a multiplication table")
    print("2) Quit the program")
    #Prompt user to select option from menu
    option=int(input("Please select an option from the menu above:"))
    #If user input 1
    if option==1:
        #Prompt user to input an interger
        number=int(input("Enter an integer between 1 and 10:"))
        #Nested loops
        #Rows(number+1) because it start from zero
        for i in range(number+1):
            #Columms (number+1) because it start from zero
            for j in range(number+1):
                #i and j must greater than zero
                if i>0:
                    if j>0:
                        #Loop through i multiply j
                        print((i*j)," ",end='')
            #This blank is important because while loop finish in the row
            #It continue to next row
            print()
    #If user input 2        
    elif option==2:
          #Print when the value is 2
          print("Thank you for using Multiplication Tables")
          #Keep looping when the value is not 1 and 2
          keepLooping=False
    #Print  when the value is not 1 and 2
    else:
       print("Incorrect menu selection, please try again")




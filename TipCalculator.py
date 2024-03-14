#Function
#tipAmount = (tippercentage * 0.01) * monetaryamount

#We are computing the amount to give service for some total bill.
#Everyone get a share included cooks and employees in the kitchen

#totalAmount  - the total amount in dollars and cents (10.50, 21.30)(float)
#percentage   - the tip represented as a percentage (e.g. 15.0, 20.0)(float)
#tipAmount    - the amount of tip calculated in dollars and cents(float)

# Print the program description
print("This program calculates the tip of a monetary amount.")
print("The monetary amount entered by the user is represented in dollars and cents (e.g. 10.00, 21.50).")
print("The tip entered by the user is represented as a percentage (e.g. 17.0, 21.0).")
           
#First of all,you need to define what is inside the multiply bracket
#Next, You need to show the monetaryamount and tip percentage out
       #(Below the Definition!!!,otherwise it can't process)
#Use the equation given to get the amount of tip and show it out
#The person that using this calculator need to put the number inside the multiply bracket given following the information given.

#Define the multiply

def multiply ():
# Prompt user forn tip percentage and monetary amount

    Monetaryamount=eval(input("Enter the total monetary amount(e.g. 10.50, 12.30)："))
    Tippercentage=eval(input("Enter the tip as a percentage(e.g. 15.0, 20.0):"))
    
#Compute the tip using the function
# Print the result
#TipAmount
    Tipamount=(Tippercentage*0.01)*Monetaryamount
#TotalBill(tip+bill)
    Totalbill=Monetaryamount+Tipamount
    print("The amount of tip is:",round(Tipamount,2))
    print("The total bill is", round(Totalbill,2))
#Execute the main program
multiply()


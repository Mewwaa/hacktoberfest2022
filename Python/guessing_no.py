import random
random_number = random.randint(1,100) #computer select number 
win = False
Turns =0
while win==False:
    Your_guess = input("Enter a number between 1 and 100") #take user guess
    Turns +=1 #count number of turns
    if random_number==int(Your_guess): #check for win condition
        print("You won!")
        print("Number of turns you have used: ",Turns)
        win == True
        break
    else: #check for hints
     if random_number>int(Your_guess):
        print("Your Guess was low, Please enter a higher number")
     else:
        print("your guess was high, please enter a lower number")

"""
The computer will choose any random number between 1 to 100. Then the user will try to guess the right number.

If the user failed to enter the random number chosen by the computer then the user will get a hint.

The hints will be like these:

Your guess was low, please enter a higher number

Your guess was high, please enter a lower number

With the help of these hints, you have to find the random number choose by the computer.

When you will enter the right random number chosen by the computer you will get an output like this:

You won!
"""

"""
Name:knotsid
profile link:https://github.com/knotsid
"""
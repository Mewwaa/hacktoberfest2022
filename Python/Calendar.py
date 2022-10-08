# Import all functions from the tkinter module
from tkinter import *

# Import Calendar module
import calendar

def showCalculator():
    
    # Create New calendar window
    new_window = Tk()

    # Set the background color of GUI application
    new_window.config(background = 'white')

    # Set the title of the GUI application
    new_window.title("Calendar")

    # Set the geometry of the GUI application
    new_window.geometry('650x700')

    # Get method to get input 
    fetch_year = int(year_field.get()) 
  
    # calendar method of calendar module return the calendar of the given year . 
    cal_content = calendar.calendar(fetch_year) 
  
    # Create a label for showing the content of the calender 
    cal_year = Label(new_window, text = cal_content, font = "Consolas 10 bold") 
  
    # Grid method is used for placing  the widgets at respective positions in table like structure 
    cal_year.grid(row = 5, column = 1, padx = 20) 
      
    # Start the GUI  
    new_window.mainloop()


if __name__=='__main__':

    # Create the basic GUI window
    root = Tk()

    # Set the background color of GUI application
    root.config(background = 'white')

    # Set the title of the GUI application
    root.title("My Calender")

    # Set the geometry of the GUI application
    root.geometry('500x400')

    # Create a Calendar label with specified font and size 
    cal = Label(root, text = "Welcome to the Calendar Application", bg = "Light Blue", font = ("times", 20, 'bold')) 

    # Create a year label to ask the user for year
    year = Label(root, text = 'Please enter a year',bg = 'pink')

    # Create a year Entry : Entry
    year_field = Entry(root)

    # Create a Show Calendar Button and attached to showCalculator function 
    Show = Button(root, text = "Show Calendar", fg = "Black", bg = "Light Green", command = showCalculator)

    # Create a Exit Button and attached to exit function 
    Exit = Button(root, text = "Exit", fg = "Black", bg = "Light green", command = exit) 
      
    # Displays the heading
    cal.grid(row = 1, column = 1) 
    
    # Displays the label to enter year
    year.grid(row = 2, column = 1) 
  
    # Displays the field to enter year
    year_field.grid(row = 3, column = 1) 
  
    # Displays button to Show Calendar
    Show.grid(row = 4, column = 1) 
  
    # Displays Exit button to close the application
    Exit.grid(row = 6, column = 1) 
      
    # start the GUI  
    root.mainloop()
    
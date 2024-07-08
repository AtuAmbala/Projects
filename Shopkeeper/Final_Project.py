#Final Project
# Name: Atu Ambala

import csv

from tkinter import *
import tkinter as tk
class Stock:
    """ looking at the stock level of an individual item in the stock
    this section would be used by employees and managers.
    """
    def __init__(self, item_code, item, price, stock_level, reorder_level):
        """constructor class for the stock information for each item"""
        self.item_code= item_code
        self.item=item
        self.price= price
        self.stock_level= stock_level
        self.reorder_level= reorder_level
    
    def __repr__ (self):
        """string representation of Stock class objects"""
        return self.item_code+','+ self.item +','+ self.price +','+self.stock_level+','+ self.reorder_level 
    
    #I originally wanted to run to check for this but i turned my attention to only dealing with orders
    def reorder_check (self) :
        if self.stock_level <  self.reorder_level:
            return 'Stock level for', self.item_code, self.item, 'is BELOW the reorder level'
        else: return  'Stock level for', self.item_code, self.item, 'is NOT BELOW the reorder level' 
        
class Inventory:
    
    """creates and works with all the current inventory"""
    def __init__(self, filename):
        """ creates a list of the full inventory level """
        #opening and, reading and storing info from a file the closing it
        lines= open(filename)
        self.items=lines.read()
        self.split_= self.items.split('\n')
        self.filename= filename
        lines.close()
        
    def __repr__(self):
        """representing the entire inventory """
        return (self.items)
    
    def retrieve_row (self, item_code):
        """takes teh inventory and an item code to determine the row of the item code"""
        #create a loop that goes over the line
        for i in self.split_:
            #check if the item code is in the line
            if item_code in i:
                #Get the index of the item code
                row= self.split_.index(i)   
                #return teh row    
                return row
        else: 
            print ('Item code is incorrect')
            return False
    
    def item_info (self, item_code):
        """uses an item code to get teh information about a product"""

        #check that the item code is legit
        if self.retrieve_row ( item_code) != False:
            #get the row fo the code
            row= self.retrieve_row (item_code)
            #get the info associated with teh item code
            correct= self.split_[row]
            #split the file by commas
            fields= correct.split(',')
            
            return (fields)
   
   
class Order:
    """This class deals with every single individual order"""
    
    def __init__ (self, item_code, quantity, inventory):
        """constructor for the class"""
        self.item_code= item_code
        self.quantity = quantity
        self.invent= inventory

        retrieved= self.invent.item_info (self.item_code) 
        #Creating a stock item for the order
        stock=  Stock (retrieved [0], retrieved[1], retrieved[2], retrieved[3], retrieved[4])
        #assigning some obejcts based on teh stock objects
        self.price= stock.price
        self.item= stock.item
        self.s_level= stock.stock_level
        cost= float (self.price) * int (self.quantity)
        #ensuring cost is only 2 decimal places
        self.cost= "{:.2f}".format(cost)
    
    def __repr__ (self):
        """string representation of each order"""
        return self.item +','+str (self.price)+','+ str (self.quantity) +','+ str(self.cost)

class Mutiple:
    """this is a class that collects and deals with mutiple orders"""
    
    def __init__(self,orders):#, inventory):
        """constructor for the class"""
        #takes first order and adds it to a list of orders
        self.orders=[orders]
        #invent being used is the same as the first order
        self.invent= orders.invent
        
        
        
    def __repr__(self):
        #returns a string representation of all the orders
        return str (self.orders)

    def add_order(self):
        """method to add orders"""
        #ask the user to input item code and quantity
        val= input ("Please input the item_code and quantity seperated by a comma: \n")
        #split at the comma
        ans= val.split(',')
        
        item_code=  ans[0]
        quantity= int (ans[1])
        #if the item code is legit then proceed
        if  self.invent.retrieve_row ( item_code) != False:
            #Creating a new order
            new_order= Order (item_code, quantity, self.invent)
            self.orders += [new_order]
            
            self.stock_change(item_code, quantity)

        else: 
            return ('Incorrect Item_code')
        
    def stock_change(self, item_code, quantity):
        """Changes the stock value for each item after ordering in the inventory"""
        #get the row where the item code is
        row= self.invent.retrieve_row ( item_code)
        #retrieve the info about that item code
        item_info=self.invent.item_info(item_code)#

        #calculate the new stock level
        new_stock= int (item_info[3]) - quantity
        
        #create a stock variable with teh new infomation
        #convert to string 
        updated= Stock (item_info[0], item_info[1], item_info[2], str(new_stock), item_info[4])

        #update the place where teh invenotry is being stored
        self.invent.split_[row]= str (updated)
    
    
    def gather_prices (self):
        """Gathers the prices from all the orders"""
        #creates an empty lsit
        list1=[]
        #loops over all the orders
        for i in range(len(self.orders)):
            
            items=str(self.orders[i]).split(',')
            list1+= [items[-1]]
        return list1
    
    def calculate_Tprices(self, list2):
        """Calculates the total price
         tkaes a list of prices as an input"""
        #uses recursion to find the total price
        if len(list2)==0:
            return 0
        else:
            number=float(list2[0]) + float(self.calculate_Tprices(list2[1:]) )
            return "{:.2f}".format(number)
    

    def twoDlists(self,list_wannabe):
        """takes a split file thing and turns into a 2d list """  
        #start off with an empty list to add stuff too
        dimensional=[]
        #loops over all the items in the split file
        for i in list_wannabe:
            #Splits each index by teh cmoma and adds that to the list a
            splitted= [i.split(',')]
            
            dimensional +=splitted
         
            
        return dimensional

    def rewrite(self)    :
        """rewrites back to file where the inventory was gotten from"""        
        with open('shop_stockcopy.csv', "w", newline="") as f:
            #creating a 2d lsits of the current inventory
            two_dimensional= self.twoDlists (self.invent.split_)
            #Writing to a csv file
            writer = csv.writer(f)
            writer.writerows(two_dimensional)
             
    def print_receipt(self):
        """prints out the receipt for the customer"""
       #looping over all teh orders
        for i in self.orders:
            #prints a sting representation
            print (i.quantity, 'x', i.item , '      @', i.price, "........" , i.cost)
            
    def return_receipt(self):
        """prints out the receipt for the customer"""
        #similar ot print_receipt but RETURNS a string
        result=''
        for i in self.orders:
            result+= str(i.quantity)
            result += '  x  '
            result+= i.item
            result+='      @   '
            result += str(i.price)
            result+='.........'
            result+= str(i.cost)
            result+='\n'
            
        return result
            
    def user_receipt(self):
        """prints the user receipt in the GUI"""
        #returns string of orders
        stuff= self.return_receipt()
        #create GUI
        root = Tk()
  
        # specify size of window.
        root.geometry("1000x1000")
        root.title ('CUSTOMER RECEIPT')
        # Create text widget and specify size.
        T = Text(root, height = (len(self.orders)+7), width = 80)
  
        # Create label
        l = Label(root, text = "BELMA GROCERY STORE")
        l.config(font =("Courier", 24,))
  
        # Create an Exit button.
        b2 = Button(root, text = "Exit",
                        command = root.destroy) 

        #add elements to GUI
        l.pack()
        T.pack()
        b2.pack()
        
        #gather prices
        gathered= self.gather_prices()
        #calcualte total price
        t_price= self.calculate_Tprices(gathered)
        
        
        # Insert the receipt information.
        T.insert(tk.END, '\n')
        T.insert(tk.END, stuff)
        T.insert (tk.END, '\nTotal...................')
        T.insert (tk.END, t_price)
        T.insert(tk.END, '\n\n Thank you for Shoppng with us!\n')
        tk.mainloop()       


#what is displayed in the interactive window
def display():
    
        """ prints a menu of options
        """  
        print()
        print('(1) Place first order')
        print('(2) Add an Order')
        print('(3) Get the Total price')
        print('(4) View the receipt')
        print('(5) Print the receipt')
        print('(6) Cancel')
        print()

#this is the user interaction side  
def main():
    """ the main user-interaction loop
    """

    while True:
        print()
        #ask the user to input item code and quantity
        #creates inventory item form this file
        invented= Inventory('shop_stock.csv')

            #Creating a new order
            
      
        print ('Welcome to Belma Grocery Store')    
        display()
        print()

        choice = int(input('Enter your choice: '))
        
        #start an order    
        if choice == 1:
                
                val= input ("Please input the item_code and quantity seperated by a comma: \n")
                #split at the comma
                ans= val.split(',')
                        
                item_code=  ans[0]
                quantity= int (ans[1])
                
                #if the item code is legit then proceed
                if  invented.retrieve_row ( item_code) != False:
                    #create order item
                    new_order= Order (item_code, quantity, invented)
                    #create a new multiple order
                    placed=Mutiple(new_order)
                
                    placed.stock_change(item_code, quantity)
                    
        #if adding an new order      
        elif choice == 2:
                
                placed.add_order()
                
        #If getting total price       
        elif choice == 3:
                #gather prices
                gathered= placed.gather_prices()
                #calcualte total price
                t_price= placed.calculate_Tprices(gathered)
                print (t_price)

        #if viewing the recipt the receipt
        elif choice == 4:
                
                 placed.print_receipt()

        #print the receipt on a user interface
        elif choice==5:
            #write to a file
            placed.rewrite()
            placed.user_receipt()
            
            break
        
        
        elif choice==6:
            #exit the user inteface
            break
        
        else :
            print ('Incorrect choice, please try again')


        
                
            
if __name__== '__main__': 
         
    z=Inventory('shop_stock.csv')
    b= Order ('TM12', 11, z)
    d = Mutiple(b)
    main()
    print ()
 



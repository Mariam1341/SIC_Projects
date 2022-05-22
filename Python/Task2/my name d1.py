# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

for row in range(7):
    for col in range(65):
        if col == 0 or col == 6 or col == 23 or col == 39 or col == 58 or col == 64 :
           print("*", end="")
    #R
        elif col == 30:
            if row == 0 or row == 3:
                print( end=" ")
            else:
                print("*", end="")
    #A
        elif col == 11 or col == 19 or col == 46 or col == 54 :
            if row == 0:
                print( end=" ")
            else:
                 print("*", end="")

    #i
        elif (row == 0 or row == 6) and (col == 35 or col == 37 or col == 41 or col == 43 ):
            print("*", end="")
    #R
        elif (row == 0 or row == 3) and (col == 25 or col == 27 or col == 29 or col == 48 or col == 50 or col == 52 or col == 13 or col == 15 or col == 17):
            print("*", end="")
    #M

        elif (row == col) and (col>0 and col<4):
            print("*", end="")
        elif (row == 1 and (col == 5 or col == 59 or col == 63)):
            print("*", end="")
        elif (row ==2 and (col == 4 or col == 60 or col == 62)):
            print("*", end="")
        elif (row ==3 and col == 61):
            print("*", end="")
        else:
            print( end=" ")
    print()

"""for row in range(7):
    for col in range(69):
        if col == 0 or col == 8 or col == 25 or col == 41 or col == 60 or col == 68 :
           print("*", end="")
    #R
        elif col == 32:
            if row == 0 or row == 3:
                print( end=" ")
            else:
                print("*", end="")
    #A
        elif col == 13 or col == 21 or col == 48 or col == 56 :
            if row == 0:
                print( end=" ")
            else:
                 print("*", end="")

    #i
        elif (row == 0 or row == 6) and (col == 37 or col == 39 or col == 43 or col == 45 ):
            print("*", end="")
    #R
        elif (row == 0 or row == 3) and (col == 27 or col == 29 or col == 31 or col == 50 or col == 52 or col == 54 or col == 15 or col == 17 or col == 19):
            print("*", end="")
    #M

        elif (row == 1 and (col == 2 or col == 6 or col == 62 or col == 66)):
            print("*", end="")
        elif (row ==2 and (col == 3 or col == 5 or col == 63 or col == 65)):
            print("*", end="")
        elif (row ==3 and (col == 4 or col == 64)):
            print("*", end="")
        else:
            print( end=" ")
    print()
    
    
    ***         ***
    *** **   ** ***
    ***  ** **  ***
    ***    *    ***
    ***         *** 
    ***         ***
    ***         *** 
    
    
    
    
    
    
    
    
    """

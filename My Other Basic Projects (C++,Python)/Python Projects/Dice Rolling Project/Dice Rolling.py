# -*- coding: utf-8 -*-
"""
Created on Mon Jan  9 15:15:32 2023

@author: ozan

Dice Game
Level: A(0.0005)
"""

import random

# rolling one dice
"""
while 1:
        
    x = random.randint(1,6)
    print(x)
    ch = input("Do you want to keep on rolling?(y,n): ")
    if ch == 'n':
        break
"""

# rolling two dice

x = 'y' # default setting
while x == 'y':
    dice1 = random.randint(1, 6)
    dice2 = random.randint(1,6)    
    print("dice1:",dice1,"dice2:",dice2 )
    print("Sum of the dices: ",dice1+dice2 )
    x = input("Do you want to keep on rolling?(y,n): ")
# -*- coding: utf-8 -*-
"""
Created on Wed Jan 11 00:12:27 2023

@author: ozan
Contact Book Project
"""


name = ["Ozan","Ali","Özgür"]
address = ["Ankara","İzmir","Istanbul"]
number = [11,12,13]


while 1:
    i = 0
    flag = 0
    ch = input("Do you want to add (a),delete (d) or print all (p): " )
    
    if(ch == 'a'):
        na = input("Enter the name that you want to add: ")
        ad = input("Enter the address that you want to add: ")
        nu = int(input("Enter the number that you want to add: "))
        name.append(na)
        address.append(ad)
        number.append(nu)
    
    elif(ch == 'd'):
        
        delName = input("Enter the name that you want to delete: ")     
        for i in name:
            
            if(i == delName):
                
                name.pop(flag)
                address.pop(flag)
                number.pop(flag)
            flag += 1
            
            
    elif(ch == 'p'):
        for x in name:
            print(name[i],'\t',address[i] ,'\t',number[i])
            i = i+1
        #for i in name,address,number:
         #   print(name ,address , number)
    
    
    exit1 = input("Do you want to continue c or exit e: ")
    if(exit1 == 'e'):
        print("Program is successfully completed.")
        break



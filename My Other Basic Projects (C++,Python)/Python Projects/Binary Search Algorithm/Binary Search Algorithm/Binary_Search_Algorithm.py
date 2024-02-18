
numbers = [4,5,7,8,9,12,13,14,15,17]

i = 1
j = len(numbers) 
ww = int(input("Enter the number that you want to find: "))

while 1:
    if i < j:
        m = int((i+j)/2)
        if(ww > numbers[m-1]):
            i = m + 1
        else: 
            j = m 
           
         
    else:
        if(ww == numbers[i-1]):
            print(f"We find it,which is in index: {i-1} The number we find is: {ww} ")
            break
        else:
            print(f"There is no such value: {ww}") 
            break


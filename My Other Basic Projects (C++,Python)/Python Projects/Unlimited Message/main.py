import pyautogui as gui
import time


msg = input("Enter the message: ")
number = int(input("Loop number: "))

time.sleep(2)

for i in range(number):
    gui.typewrite(msg)
    gui.press('Enter')

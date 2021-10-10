This Project is a simple password check project using atmega32.

components:
1 atmega32
1 lcd 16*2
6 330 resistances
2 led "red and green"
1 keypad

The components should be connected according to the schematic 
attached to the project.

The lcd is used to display the status of the safe whether the 
password is correct or not correct and the current Status of the 
safe is indicated by the 2 leds red means closed and green means open.
The keypad used to enter the password, reset the safe using '*' key
and submit the password entered using '#' key.
If the password was correct then the green led blinks and the lcd 
displays "Password Accepted".
If the password was incorrect then the red led blinks and the lcd 
displays "Password Rejected".

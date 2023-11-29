### Safe implementation using avr
This project uses AVR drivers like Math.h, STD_types.h, DIO, LCD and Keypad I've written to implement a simple safe.

![AVR Safe](https://github.com/NohaAhmed01/ATMega32_Safe/assets/119630724/e84d658b-eb01-48e1-b10e-4ca847d90106)

**What the safe does?**

- it welcomes me first and then prompts the user for a password
- it displays the entered numbers on the LCD while storing these values
- it checks if the password entered is correct:
               1. if correct=> it prints "correct!!" on LCD and lights up an LED
               2. if wrong=> it prints "wrong :(" and waits for 100ms then prompts the user to enter password again
  
**Preview of the working**


https://github.com/NohaAhmed01/ATMega32_Safe/assets/119630724/e471dcb1-6d18-42ad-8c2a-ca52c2f53911


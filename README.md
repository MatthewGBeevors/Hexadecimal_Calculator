# Hexadecimal_Calculator

/*DESCRIPTION: 

Here was my first project I coded in C++, where a window asks the user for a number. This number is then converted into its corresponding Hexadecimal counterpart and printed to the user. 

/*PURPOSE: 

I wrote this code as I had been recently been relearning how to convert from decimal and hexadecimal out of pure interest. Then the idea occured to try and write a script that would automate this process for me. 

/*TOOLS / PACKAGES: 
1) iostream  - standard library
2) vector    - used an array to store the results of the hexadecimal letters/numbers
3) cmath     - provided useful mathmatical operations

/*APPROACH: 

My initial approach was to (1) perform the division by 16, 

  (2) Split the number into its integer and remainder parts,

  (3) Store the remainder, and take the integer part and divide by 16 again,

  (4) Iterating through this process as many times as needed until the division by 16 was less than 1, as this signifies the last iteration needed,
      
  (5) The arrays elements can then be converted from 10-15 -> A-F if neccesary and displayed to the user

However this got a lot more complicated, the first issue encountered being how to store these remainders? The issue lying with the fact that a normal array would need to have a predefined size, whereas the array could be any length, depending on the number input.
This was solved by using the standard vector class which creates a new larger array, copies the values accross and deletes the original array everytime its capacity is reached. This might sacrifice some performance due to the copying once a very large number is input but that is something I will look into in the future.
The next glaring issue, I needed to write a combination of for loops and if statements to iterate through the maths up until the remainder < 1. Through writing a very bulky initial version I made the code work, once the process exsisted I found it easier to find short-cuts and optimisations, leading to me only needing the one for loop containing an if statement which simply breaks the loop once the remainder which is then assigned to start_val < 1.
Floor() was a key tool used to seperate the division result. by flooring the result the integer part could be isolated, and then be used to isolate the remainder.
This brought another issue that if I wanted to identify my remainder I had to cast it from a float to an int. This could encounter data loss but the result will always be an integer so is safe in this case. 
It soon occured to me, writing a function purely for printing the results would benefit my code, making it more concise.
A particular problem was that the order of the vector array had to be flipped and there were a few ways of performing this but the simplest seemed to call std::reverse. I could look into the performance of this function is compared to a for loop flipping the order to optimise the code.
One of the less elegant parts of this script is the conversion from 10-15 -> A-F, for which I wrote a for loop to iterate through each element in the resulting array and performing the conversion, this method could suffer for very large arrays but that is for future improvement.

That is how I approached this task, I definitly think there are many optimisations that could be made as seen below. However, I am really proud that I was able to make this calculator without much help, as I tried a few weeks earlier and got immediatly stuck, showing how much and how quickly I have learned the content. Inspiring me to keep learning and try something more challenging soon.

/*FUTURE IMPROVEMENTS

	(1) - write safety net so even if a user enters an invalid value (4.5) the code wont break.
	(2) - fix the end result list to not contain an extra "," after the last value
	(3) - Write the end resulting list as just "xyz" not [x, y, z,]
	(4) - when using a huge number it puts the number into standard form losing the remainder

**Task 1 :**

1. **What do the .data, .word, .text directives mean (i.e. what do you use them for)? Hint: think about the 4 sections of memory.**

   ​    To tell the assembler which segment to store to.

   | Type  | Function                                                     |
   | ----- | ------------------------------------------------------------ |
   | .data | Store subsequent items in the static segment at the next available address. |
   | .text | Store subsequent instructions in the text segment at the next available address. |
   | .word | Store listed values as unaligned 32-bit words.               |

   

2. **Run the program to completion. What number did the program output? What does this number represent?**

   ​	Output: 34

   ​	Represent: 9th Fibonacci number

3. **At what address is n stored in memory? Hint: Look at the contents of the registers.**

   ​	0x10000010

4. **Without using the “Edit” tab, have the program calculate the 13th fib number (0-indexed) by manually modifying the value of a register. You may find it helpful to first step through the code. If you prefer to look at decimal values, change the “Display Settings” option at the bottom.**

   ​	Output: 233
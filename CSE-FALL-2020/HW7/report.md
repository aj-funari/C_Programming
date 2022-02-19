1) The first step to solve phase one was to look at the assembly code to tryand figure out what the code is doing. To analyze phase one I typed 's sym.phase_1', 'pdf', and then 'Vpp' to enter visual mode. From looking at the assembly code, I saw there is a function called 'sym.strings_not_equal' which makes me believe we are comparing two strings to each other. After the function 'sym.strings_not_equal' is called there is a line of assembly code that states 'jne' which means jump if not equal and the resulting action is a jumpto a bomb. From looking at this code, I have figured out the answer to phaseone is a string and it needs to be the same exact string as another string or the bomb will explode. After analyzing the assembly code for a longer period of time, I see the address of the string 'When a problem comes along, you must zip it!' is being loaded into register rsi, thus I realized that isthe answer to phase one.

2) The first step to solve phase two was to look at the assembly code to try and figure out what the code is doing.  To analyze phase two I typed 's sym.phase_2', 'pdf', and then 'Vpp' to enter visual mode. From looking at the assembly code, the first line that stands out to me is the function 'sym.read_six_numbers' that tells me the answer to this phase is 6 numbers. The next line of code folling the function 'sym.read_six_numbers' is 'cmp dword [rsp], 2' which is comparing the value in register rsp to the number 2. After the line 'cmp dword [rsp], 2' is a line that states 'je' that means jump if equal. This jump will jump over a bomb if the value in [rsp] is equal to 2. To test this therory, I set a breakpoint at sym.phase_2, entered six numbers (2 being the first number), and ran through the first part of the code. After working executing lines of the assembly code, I successfully jumped over the bomb meaning the first number to phase two is 2. I continued these steps to figure out the next 5 numbers. I was able to crack the code and find that the six numbers are 2,3,5,9,17,33. 

3) The first step to solve phase three was to look at the assembly code to try and figure out what the code is doing. To analyze phase three I typed 's sym.phase_3', 'pdf', and then 'Vpp' to enter visual mode. From looking at the assembly code, the first thing I notice is the function 'sym.string.length', so realize I need to figure out the length of the string. I see a line of assembly code that states 'cmp eax, 0xa', thus I figure out the length of the string is 10. Now the hard part is figuring out the correct 10 characters to crack the code. I notice there is a string that states 'B.Disraeli'. The length is 10, so I assume that is the answer. I test the string; however, the bomb explodes. After looking at the assembly code a little longer, I notice there is an xor. I decide to use the string 'B.Disraeli' as input to the function. Once I execute the code to the part where the xor exists, I see that it is a loop that runs through 10 times. Each time through the look, a character in the input string is xor with a value and that value is stored in 'edx'. I discover each value that is stored in 'edx' is the answer to the code. I use '? 0x(value)' to crack the code and get the correct characters. The answer to phase 3 is 'K+Nhupbljk'.  

4) The first step to solve phase four was to look at the assembly code to try and figure out what the code is doing. To analyze phase four I typed 's sym.phase_4', 'pdf', and then 'Vpp' to enter visual mode. From looking at the assembly code, the first thing I notice is the the function takes in two variables and from analyzing the assembly code the two variables are numbers. I know this becuase the address of '%d %d' is being loaded into register rsi. To figure out what numbers are needed to crack the code I set a break point and used two random numbers. After running through the assembly code line by line, I come to a point where rsp + 0xc (which is the first variable) is being compared to the value 5 and after that line is a jump, jg. The jump, jg, means jump if greater and jumps to a bomb, thus I figure out that the first number must be less than 5. After continuing through the assembly code, there comes a line where variable var_8h (the seconds variable) is being compared to 0 and will jump to a bomb if not equal to 0. After analyzing this sequence of lines, I figure out that the second number must be 0. After using the numbers 4 and 0 to test phase 4, the bomb does not explode and I crack phase 4.

5) The first step to solve phase five was to look at the assembly code to try and figure out what the code is doing. To analze phase five I typed 's sym.phase_5', 'pdf', and then 'Vpp' to enter visual mode. From looking at the assembly code the first thing I notice is the function takes in two variables and both variables are numbers. To run through the assembly code I tested two random numbers between 0 and 9. After running line by line, I came to a point where var_ch (the first varible) is subtracted by 8 and then compared to 6. A jump to a bomb will occur if the resulting number is 6 or greater than 6, thus the first variable must be less than 14. Continuing through the assembly code, I made it to a point where var_8h (second variable) is being compared to 0x17 (23). A jump to a bomb will occure if the second variable is not equal to 23, thus the second variable is 23. In conclusion, the first number must be less than 14 and the second variable is 23.  
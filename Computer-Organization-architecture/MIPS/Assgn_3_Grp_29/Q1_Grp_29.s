# HEADER #

# Assignment Number: 1
# Problem number : 1
# Semester: 5
# Group no. 29
# Bannuru Rohit Kumar Reddy - 21CS30011
# Dumpala Hashmitha - 21CS10023



# Entering the Data Elements :

.data

    arr: .space 400 # Space for the array of integers

    InputN: .asciiz "Input: N = "
    Inputeachelement: .asciiz "Enter element "
    Format: .asciiz ": "
    PrintArray: .asciiz "The elements of the array are : "
    newline: .asciiz "\n"
    space: .asciiz " "
    Values: .asciiz "Values found: "
    Maxsum: .asciiz "Maximum sum ( Non Circular ): "
    Minsum: .asciiz "Minimum sum: "
    Totalsum: .asciiz "Total sum: "

    Output: .asciiz "Output: "


# Main Function : 


.text
.globl main

main:

    # First take the number of elements of the array ( N ) Input : 
    li $v0, 4
    la $a0, InputN
    syscall
    
    # Read N
    li $v0, 5
    syscall
    move $s1, $v0  # Store N in $s1

    # Calling the take_input function to take N integers as Input and store them in an Array
    # Note: The name of the Array: arr 

    jal take_input

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 4
    la $a0, PrintArray
    syscall

    li $t0, 0

    loop_display:

        # Load array element
        la $t1, arr  # Load arr[t1] into $t3

        sll $t2, $t0, 2
        add $t3, $t1, $t2

        lw $t3, 0($t3)

        
        # Print array element
        move $a0, $t3
        li $v0, 1
        syscall

        li $v0, 4
        la $a0, space
        syscall

        
        # Increment index
        addi $t0, $t0, 1
        
        # Check if all elements are displayed
        bne $t0, $s1, loop_display

    jal Calcualte_max_min_sum

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 4
    la $a0, Values 
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 4
    la $a0, Maxsum 
    syscall

    # Print  element
    move $a0, $s3
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 4
    la $a0, Minsum 
    syscall

    # Print  element
    move $a0, $s5
    li $v0, 1
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 4
    la $a0, Totalsum 
    syscall

    # Print  element
    move $a0, $s6
    li $v0, 1
    syscall


    # The Circular Maximum Sum Will either be the Maximum [ Maximum Sum , (Total Sum - Min Sum )] 

    sub $t3, $s6, $s5               # Finding Total Sum - Min Sum 

    bgt $t3, $s3, final_output      # Storing the Final Answer in t3
    move $t3, $s3

    final_output:

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 4
    la $a0, newline
    syscall

    li $v0, 4
    la $a0, Output
    syscall

    # Print  the Final Circular Maximum Sum : 
    move $a0, $t3
    li $v0, 1
    syscall

    
    # Exit
    li $v0, 10
    syscall
    

take_input:

    li $s2, 0  # Initialize index for the array

    each_input:

        # Print prompt for element
        li $v0, 4
        la $a0, Inputeachelement
        syscall
        
        # Print index + 1
        addi $t5, $s2, 1
        move $a0, $t5
        li $v0, 1
        syscall

        # Format
        li $v0, 4
        la $a0, Format
        syscall
        
        # Read element
        li $v0, 5
        syscall
        move $t4, $v0

        # Loading the base Address, Calculating the given address and Storing the input in that Address 

        la $t2, arr         # Base addresss
        sll $t3, $s2, 2     # Multiply prev by 4 (shift left by 2 bits)
        add $t3, $t2, $t3   # The Address in that particular index
        
        # Store element in the array
        sw $t4, 0($t3)  # Store in arr[s1]
        
        # Increment index
        addi $s2, $s2, 1
        
        # Check if all elements are read
        bne $s2, $s1, each_input
            
    # Return to the calling function
    jr $ra 

Calcualte_max_min_sum:

    li $s2, 0               # Current Max sum 
    li $s3, -999999         # Max Sum 
    li $s4, 0               # Current Min sum 
    li $s5, 9999999         # Min sum 
    li $s6, 0               # Total sum 

    li $t1, 0               # Inital Index 

    Calculate_Values:

        la $t8, arr



        sll $t2, $t1, 2     # Multiply prev by 4 (shift left by 2 bits)
        add $t3, $t2, $t8   # The Address in that particular index
        
        # load element in the array
        lw $t4, 0($t3)  # Store arr[i] in t4


        # Update total sum 
        add $s6, $s6, $t4

        # Update Current Max sum 
        add $s2, $s2, $t4   # Curr_Max = Curr_Max + arr[i]

        # Update Max sum
        blt  $s2, $s3, b1
        move $s3, $s2

        # If Current Max is <0 
        b1:
        bgt $s2, $zero, b2
        li $s2, 0                   # Change s2 ( Curr_sum )  to 0 if it is less than 0 

        # Update Current Min sum 
        b2:
        add $s4, $s4, $t4

        # Update Min sum
        bgt $s4, $s5, b3
        move $s5, $s4

        # If Current Min is >0 
        b3:
        blt $s4, $zero, b4
        li $s4, 0 

        b4:

        addi $t1, $t1, 1

        blt  $t1, $s1, Calculate_Values

    jr $ra

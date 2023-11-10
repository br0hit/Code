# HEADER #

# Assignment Number: 1
# Problem number : 1
# Semester: 5
# Group no. 29
# Bannuru Rohit Kumar Reddy - 21CS30011
# Dumpala Hashmitha - 21CS10023

    .globl  main

    .data

# Creating an array to store the first permutation : 
p1:
    .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

# Creating an array to store the first permutation : 
p2:
    .word 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

result_array:
    .space  40          # Assuming 10 integers, each 4 bytes

output_format: .asciiz "%d "





# program output text constants

prompt:
    .asciiz " Enter no of cycles in permutation :"
cycle:
    .asciiz "Enter number of integers in  cycle "
format:
    .asciiz ": "
number:
    .asciiz "Enter integer in  cycle "
result:
    .asciiz "Product permutation cycle "
newline:
    .asciiz "\n"


    .text

# main program

main:

    li      $v0, 4          # User Interface for calculating the exponential 
    la      $a0, prompt
    syscall

    li      $v0, 5          # get number of cycles in the first permutation from user
    syscall
    move    $s0, $v0

    # This variable is initially 1, and we will increment every time we run the loop 
    li $s1, 0


cycle_input:

    addi $s1, $s1, 1

    bgt     $s1, $s0, main_2

    li      $v0, 4          # User Interface for printing "Enter number of integers in  cycle "
    la      $a0, cycle
    syscall

    li      $v0, 1          # User Interface for printing cycle number 
    move      $a0, $s1
    syscall

    li      $v0, 4          # Formatting
    la      $a0, format
    syscall


    li      $v0, 5          # Taking the number of intgers input 
    syscall
    move    $s2, $v0


    li $s3, 1


number_input:


    bgt     $s3, $s2, cycle_input

    li      $v0, 4          # User Interface for printing "Enter integer in cycle "
    la      $a0, number
    syscall

    li      $v0, 1          # User Interface for printing cycle number 
    move      $a0, $s1
    syscall

    li      $v0, 4          # Formatting
    la      $a0, format
    syscall


    li      $v0, 5          # Taking the number input  
    syscall
    move    $s7, $v0


    li $t0, 1

    # Store first input in $s6 when s3 is 1
    beq     $s3, $t0, store_first_input

    # Load base address of the p1 array into $t8
    la $t8, p1

    # Calculate the memory address of the element indicated by the previous input
    # Each element occupies 4 bytes (size of a word)
    # So, to access the element at the previous position, we add (prev * 4) to the base address
    sll $t4, $s5, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t8, $t4  # Calculate the memory address

    # Store the current input value ($s7) into the calculated memory address
    sw $s7, ($t9)


    # Store last input in the arry
    beq     $s3, $s2, store_last_input

    move    $s5, $s7         # Store previous input in $s5


    addi $s3, $s3, 1

    b number_input

store_first_input:

    move    $s6, $s7         # Store first input
    move    $s5, $s7         # Store previous input in $s5

    addi $s3, $s3, 1

    b number_input

store_last_input:

    # Load base address of the p1 array into $t8
    la $t8, p1

    # Calculate the memory address of the element indicated by the previous input
    # Each element occupies 4 bytes (size of a word)
    # So, to access the element at the previous position, we add (prev * 4) to the base address
    sll $t4, $s7, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t8, $t4  # Calculate the memory address

    # Store the current input value ($s7) into the calculated memory address
    sw $s6, ($t9)

    lw $t5, 0($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 4($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 8($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 12($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 16($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 20($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    li      $v0, 4          # print  newline
    la      $a0, newline
    syscall

    move    $s5, $s7         # Store previous input in $s5
    addi $s3, $s3, 1
    b number_input


main_2:

    li      $v0, 4          # User Interface for calculating the exponential 
    la      $a0, prompt
    syscall

    li      $v0, 5          # get number of cycles in the first permutation from user
    syscall
    move    $s0, $v0

    # This variable is initially 1, and we will increment every time we run the loop 
    li $s1, 0


cycle_input_2:

    addi $s1, $s1, 1

    bgt     $s1, $s0, main_3



    li      $v0, 4          # User Interface for printing "Enter number of integers in  cycle "
    la      $a0, cycle
    syscall

    li      $v0, 1          # User Interface for printing cycle number 
    move      $a0, $s1
    syscall

    li      $v0, 4          # Formatting
    la      $a0, format
    syscall


    li      $v0, 5          # Taking the number of intgers input 
    syscall
    move    $s2, $v0


    li $s3, 1


number_input_2:


    bgt     $s3, $s2, cycle_input_2

    li      $v0, 4          # User Interface for printing "Enter integer in cycle "
    la      $a0, number
    syscall

    li      $v0, 1          # User Interface for printing cycle number 
    move      $a0, $s1
    syscall

    li      $v0, 4          # Formatting
    la      $a0, format
    syscall


    li      $v0, 5          # Taking the number input  
    syscall
    move    $s7, $v0


    li $t0, 1

    # Store first input in $s6 when s3 is 1
    beq     $s3, $t0, store_first_input_2

    # Load base address of the p1 array into $t8
    la $t8, p2

    # Calculate the memory address of the element indicated by the previous input
    # Each element occupies 4 bytes (size of a word)
    # So, to access the element at the previous position, we add (prev * 4) to the base address
    sll $t4, $s5, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t8, $t4  # Calculate the memory address

    # Store the current input value ($s7) into the calculated memory address
    sw $s7, ($t9)


    # Store last input in the arry
    beq     $s3, $s2, store_last_input_2

    move    $s5, $s7         # Store previous input in $s5


    addi $s3, $s3, 1

    b number_input_2

store_first_input_2:

    move    $s6, $s7         # Store first input
    move    $s5, $s7         # Store previous input in $s5

    addi $s3, $s3, 1

    b number_input_2

store_last_input_2:

    # Load base address of the p2 array into $t8
    la $t8, p2

    # Calculate the memory address of the element indicated by the previous input
    # Each element occupies 4 bytes (size of a word)
    # So, to access the element at the previous position, we add (prev * 4) to the base address
    sll $t4, $s7, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t8, $t4  # Calculate the memory address

    # Store the current input value ($s7) into the calculated memory address
    sw $s6, ($t9)

    lw $t5, 0($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 4($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 8($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 12($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 16($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    lw $t5, 20($t8)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    li      $v0, 4          # print  newline
    la      $a0, newline
    syscall

    move    $s5, $s7         # Store previous input in $s5
    addi $s3, $s3, 1
    b number_input_2



main_3:

# Load base addresses of arrays p1, p2, and result_array
    la $t0, p1
    la $t1, p2
    la $t2, result_array

    
    lw $t3, 0($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    

    lw $t3, 4($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    lw $t3, 8($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    lw $t3, 12($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    lw $t3, 16($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    lw $t3, 20($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    lw $t3, 24($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    lw $t3, 28($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

    
    lw $t3, 32($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall

        
    lw $t3, 36($t0)
    sll $t4, $t3, 2  # Multiply prev by 4 (shift left by 2 bits)
    add $t9, $t1, $t4  # Calculate the memory address

    lw $t5, 0($t9)

    li      $v0, 1          # print n
    move    $a0, $t5
    syscall
    

    li      $v0, 10         # terminate the program
    syscall




























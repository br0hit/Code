# HEADER #

# Assignment Number: 1
# Problem number : 1
# Semester: 5
# Group no. 29
# Bannuru Rohit Kumar Reddy - 21CS30011
# Dumpala Hashmitha - 21CS10023


    .globl  main

    .data

# program output text constants
prompt:
    .asciiz "Enter a positive integer for calculating e^x: "
result1:
    .asciiz "The approximate exponential power of the given input is  "
result2:
    .asciiz "The number of iterations aftter which the exponential value doesn't change is :"
newline:
    .asciiz "\n"




    .text

# main program
#
# program variables
#   n:   $s0
#   sum: $s1
#   i:   $s2
#
main:

    li      $v0, 4          # User Interface for calculating the exponential 
    la      $a0, prompt
    syscall

    li      $v0, 5          # get n from user
    syscall
    move    $s0, $v0


    # Initializing the variables required to run the loop 

    li $s1, 1        # initialize the value of n to 1
    li $s2, 1        # initializing the factorial of the corresponding n
    li $s3, 1      # initialize the value of s3 to 1, This will be the corresponding power of x (to calculate x^n)
    li $s4, 1        # initialize sum to  (first term of series)
    li $s5, 1        # initialize temporary sum to 1 ( This will be pressent sum + x^n/n! )

for:



    mul     $s3, $s3, $s0    # x^n
    mul     $s2, $s2, $s1    # n!

    div     $s6, $s3, $s2    # x^n/n!
    mflo    $s6


    #  Current sum + x^n/n!
   add     $s5, $s4, $s6   

    # exit loop if the previous temporrary sum and the current sum are the same 
    beq     $s4, $s5, endf  


    # Updating the value of the current sum to Current sum + x^n/n!    
    add     $s4, $s4, $s6

    add     $s1, $s1, 1     #     n++
    b       for             # continue loop

endf:

    li      $v0, 4          # print "The number of iterations aftter which the exponential value doesn't change is "
    la      $a0, result2
    syscall

    li      $v0, 1          # print n
    move    $a0, $s1
    syscall

    li      $v0, 4
    la      $a0, newline    # print  newlines
    syscall


    li      $v0, 4          # print "The approximate exponential power of the given input is  "
    la      $a0, result2
    syscall

    li      $v0, 1          # print sum
    move    $a0, $s4
    syscall

    li      $v0, 4          # print  newline
    la      $a0, newline
    syscall

    li      $v0, 10         # terminate the program
    syscall
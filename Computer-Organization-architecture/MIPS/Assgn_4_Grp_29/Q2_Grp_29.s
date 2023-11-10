# HEADER #

# Assignment Number: 4
# Problem number : 2
# Semester: 5
# Group no. 29
# Bannuru Rohit Kumar Reddy - 21CS30011
# Dumpala Hashmitha - 21CS10023



# Entering the Data Elements :

.data

    prompt: .asciiz "Input an positive integer N:\n"
    result: .asciiz "The Number of steps required to reach 1: "
    Sanity_check: .asciiz "Given Input is not a Positive Integer, Please enter the value of n again : "
    newline: .asciiz "\n"  



.text
.globl main


main:

    # show prompt
    li        $v0, 4
    la        $a0, prompt
    syscall

    # read x
    li        $v0, 5
    syscall

    # First check whether the user has entered a positive integer or Not: 
    bgt $v0,$zero,main_program

    la $a0,Sanity_check                    
    li $v0,4                                # prints the string
    syscall

    la $a0,newline                       
    li $v0,4                                # prints the string
    syscall

    j main


main_program:

    # function call
    move      $a0, $v0
    jal      Collatz_conjecture       # Jump to the recursive function and save position to $ra
    move      $t0, $v0        # $t0 = $v0

    # show prompt
    li        $v0, 4
    la        $a0, result
    syscall

    # print the result
    li        $v0, 1        # system call #1 - print int
    move      $a0, $t0        # $a0 = $t0
    syscall                # execute

    # return 0
    li        $v0, 10        # $v0 = 10
    syscall



Collatz_conjecture:

    # Creating Space in the stack to store values 
    addi $sp,$sp,-8   

    # Sotring the values of ra and a0 in the stack                           
    
    sw   $ra,4($sp)                             
    sw   $a0,0($sp)                            

    slti $t0,$a0,2                              # if n>1 jump to recurse
    beq  $t0,$zero,recursion_loop

    add $v0,$zero,$zero                        # if (n<2) return 0

    lw   $a0,0($sp)                           # getting n back
    lw   $ra,4($sp)                           # getting the return address back

    addi $sp,$sp,8                            # popping items in the stack as they are of no use for base condition
    jr   $ra

recursion_loop:

    # Checking $a0 is odd or even by checking the reminder : 

    li $t0, 2           
    div $a0, $t0        
    mfhi $t1

    li $t2, 1
    li $t3, 0            

    beq $t1, $t2, odd   
    beq $t1, $t3, even   

even:  

    # Calculating the return value which is f(n/2)+1
   
    li $t5,2            # calculating a0=n/2
    div $a0,$t5
    mflo $a0

    jal Collatz_conjecture    # calling f(n/2)

    j return_val
   
odd:  

    # Calculating the return value whichis  f(3*n+1)

    li $t6,3            # calculating a0=3*n+1
    mul $a0,$a0,$t6
    add $a0,$a0,1

    jal Collatz_conjecture    # calling f(3*n+1)

    j return_val

return_val:

    lw $a0,0($sp)       #  n
    lw $ra,4($sp)       #  return address
    addi $sp,$sp,8      # popping the stack back

    addi $v0,$v0,1      # returning the corresponding value by adding 1, To keep the total count of functions called 
    jr $ra
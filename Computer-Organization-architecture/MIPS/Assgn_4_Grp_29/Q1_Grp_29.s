# HEADER #

# Assignment Number: 4
# Problem number : 1
# Semester: 5
# Group no. 29
# Bannuru Rohit Kumar Reddy - 21CS30011
# Dumpala Hashmitha - 21CS10023



# Entering the Data Elements :

.data

    prompt: .asciiz "Input an positive integer N:\n"
    result: .asciiz "The sum of the series is:  "
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

    # function call
    move      $a0, $v0
    jal      Find_sum       # jump to the Recursive function and save position to $ra
    move      $t0, $v0        # $t0 = $v0

    # show result text 
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


.text
Find_sum:

    # base case -- still in parent's stack segment
    # adjust stack pointer to store return address and argument
    
    addi    $sp, $sp, -8
    
    # save $s0 and $ra
    sw      $s0, 4($sp)
    sw      $ra, 0($sp)
    bne     $a0, 0, else
    addi    $v0, $zero, 0    # return 1
    j sum_return

else:
    # backup $a0
    move    $s0, $a0
    addi    $a0, $a0, -1 # x -= 1
    jal     Find_sum
   
    # when we get here, we already have the sum from 1 - (n-1)^(n-1) store in $v0

    # Calculate the value of n^n for a given n 
    # Note : n is being stored in $s0

    li $t1, 0           # t1 is the index which goes from 1 - n
    li $t2, 1           # t2 is the power of n 
    
    power_n:

        mul $t2, $t2, $s0           # Mulitply by n every loop
        addi $t1, $t1, 1            # Increase index by 1
        blt $t1, $s0, power_n       # If index is less than $s0 which has the value of n, we multiply again 

    # Add the calculated value of n to $v0 which has all the previous sum  

    add $v0, $v0, $t2             

sum_return:

    lw      $s0, 4($sp)
    lw      $ra, 0($sp)
    addi    $sp, $sp, 8
    jr      $ra
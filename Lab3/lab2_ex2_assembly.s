.data
source:
	.word	3
	.word	1
	.word	4
	.word	1
	.word	5
	.word	9
	.word	0
dest:
	.word	1
	.word	1
	.word	1
	.word	1
	.word	1
	.word	1
	.word	0
	.word	0
	.word	0
	.word	0

.text
main:
	addi t0, x0, 0 	# t0=0
	la t1, source 	# t1=&source
	la t2, dest		# t2=&dest
loop:
	slli t3, t0, 2 	# t3=t0*4	4*k
	add t4, t1, t3 	# t4=t1+t3	source[k]
	lw t5, 0(t4) 	# t5=t4(0)	t5=source[k]
	beq t5, x0, exit # if t5==x0, exit
	add t6, t2, t3	# t6=t2+t3	dest[k]
	add t5 t5 t5	# t5*=2
	sw t5, 0(t6)	# dest[k]=t5=source[k]
	addi t0, t0, 2  # k+=2
	jal x0, loop 	# for again
exit:
	jal ra, print_lists
	addi a0, x0, 10 # a0=10, exit——ends the program
	add a1, x0, x0	# a1=0
	ecall # Terminate ecall

# For this part of the lab, you don't need to understand anything
# below this line.
print_lists:
	# Save the ra in the stack since it will be overwritten
	addi sp, sp, -4
	sw ra, 0(sp)

	# Pass source array address to print_list
	la a0, source
	jal ra, print_list

	# Print a newline
	addi a1, x0, '\n'
	addi a0, x0, 11
	ecall

	# Pass dest array address to print_list
	la a0, dest
	jal ra, print_list

	# Get back saved return address from stack and go to it
	lw ra, 0(sp)
	addi sp, sp, 4
	jr ra
print_list:
	# Stop recursing when the value at 0(a0) is 0
	lw t0, 0(a0)
	bne t0, x0, printMeAndRecurse
	jr ra
printMeAndRecurse:
	# Print integer pointed to by address in a0
	add t0, a0, x0
	lw a1, 0(t0)
	addi a0, x0, 1
	ecall

	# Print a space
	addi a1, x0, ' '
	addi a0, x0, 11
	ecall

	# Go to next array element
	addi a0, t0, 4
	jal x0, print_list

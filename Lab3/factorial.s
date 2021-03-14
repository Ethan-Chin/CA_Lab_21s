.data
test_input: .word 3 6 7 8

.text
main:
	add t0, x0, x0 # t0=0
	addi t1, x0, 4 # t1=4
	la t2, test_input # t2=&test_input
main_loop:
	beq t0, t1, main_exit # if t0==t1 then main_exit
	slli t3, t0, 2 # t3=t0*4
	add t4, t2, t3 # t4=test_input[t0]
	lw a0, 0(t4) # a0=test_input[t0]

	addi sp, sp, -20 # sp-=20
	sw t0, 0(sp) # sp[0]=t0
	sw t1, 4(sp) # sp[1]=t1
	sw t2, 8(sp) # sp[2]=t2
	sw t3, 12(sp) # sp[3]=t3
	sw t4, 16(sp) # sp[4]=t4

	jal ra, factorial # factorial(), just call a0 inside it, result save to a0

	lw t0, 0(sp)
	lw t1, 4(sp)
	lw t2, 8(sp)
	lw t3, 12(sp)
	lw t4, 16(sp)
	addi sp, sp, 20

	addi a1, a0, 0 # a1=a0
	addi a0, x0, 1 # a0=1
	ecall # Print Result--print(a1)
	addi a1, x0, ' ' # a1=' '
	addi a0, x0, 11 # print(' ')
	ecall
	
	addi t0, t0, 1 # t0++
	jal x0, main_loop
main_exit:  
	addi a0, x0, 10 # a0=10
	ecall # Exit

factorial:
	add t0, x0, a0 # t0=a0, number to fractorial
	addi a0, x0, 1 # a0=1, init result
    addi t1, x0, 1 # t1=1
loop:
	mul a0, a0, t0 # a0*=t0
	addi t0, t0, -1 # t0--
	beq t0, t1, exitfac # if t5==t1==1, exit factorial
	jal x0, loop 	# for again
exitfac:
	jr ra
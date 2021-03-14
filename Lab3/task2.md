**Task 2 :**

- The register representing the variable `k`.

  - t0

- The registers acting as pointers to the `source` and `dest` arrays.

  - t1=&source
  - t2=&dest

- The assembly code for the loop found in the C code.

  - loop:

- How the pointers are manipulated in the assembly code.

  - In every loop, t3=4*k, and extract source[k], make dest[k]=source[k], then k++

    ```
    loop:
    	slli t3, t0, 2 	# t3=t0*4	4*k
    	add t4, t1, t3 	# t4=t1+t3	source[k]
    	lw t5, 0(t4) 	# t5=t4(0)	t5=source[k]
    	beq t5, x0, exit # if t5==x0, exit
    	add t6, t2, t3	# t6=t2+t3	dest[k]
    	sw t5, 0(t6)	# dest[k]=t5=source[k]
    	addi t0, t0, 1  # k++
    	jal x0, loop 	# for again
    ```

    
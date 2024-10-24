# put your names here
	.text
.globl swap
	.type	swap, @function
swap:
	pushl	%ebp                # set up swap's stack frame
	movl	%esp, %ebp
	subl	$16, %esp

	movl 8(%ebp), %ecx      # Put the memory address of x in %ecx.
	movl 12(%ebp), %edx     # Put the memory address of y in %edx
	movl (%ecx), %eax       # Put the value x points to in %eax
	movl (%edx), %ecx       # Put the value y points to in %ecx (Can we?)
	movl %eax, (%edx)       # Put the old x value in the memory address of y
	movl %ecx, %eax         # Put the old y value in %eax
	movl 8(%ebp), %ecx      # Put back the memory address of x in %ecx
	movl %eax, (%ecx)       # Put the old y value in the memory address of x
	movl %ecx, 8(%ebp)      # Move the memory address of x back
	movl %edx, 12(%ebp)     # Move the memory address of y back

	leave                     # tear down swap's stack frame and return
	ret

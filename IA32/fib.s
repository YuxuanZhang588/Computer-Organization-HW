# put your names here
	.text
.globl fib
	.type	fib, @function
fib:
	pushl	%ebp                 # set up fib's stack frame
	movl	%esp, %ebp
	subl	$16, %esp
	pushl   %ebx               # store the values in the callee-saved registers
	pushl   %esi
	pushl   %edi

	movl $1, %eax              # Put the curr value in %eax.
	movl $0, %ebx              # Put the prev value in %ebx
	movl $1, %ecx              # Put the i value in %ecx
	label1: 
	cmpl %ecx, 8(%ebp)         # Compare the value of i and n
	je label2                  # If n=i, reach the nth term, so return.
	movl %eax, %edx            # Store the old curr value in %edx
	addl %ebx, %eax            # Update: curr=prev+curr
	movl %edx, %ebx            # prev=old curr value
	incl %ecx                  # Increment I
	jmp label1                 # Loop 
	label2:  
	nop                        

	popl   %edi                # restore the values of the callee-saved registers
	popl   %esi
	popl   %ebx
	leave                      # tear down fib's stack frame and return
	ret

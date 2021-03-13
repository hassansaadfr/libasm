segment .text
	global ft_read

extern	__errno_location

ft_read:
	mov 	rax, 0x0						; on met l'appel a read dans rax
	syscall									; syscall a rax
	cmp		rax, 0							; on check si le return du syscall read est 0
	jl		exit_error						; Si oui on jump a exit_error
	ret

exit_error:
	neg		rax
	push	rax
    call 	__errno_location wrt ..plt
    pop  	qword [rax]
    mov  	rax, -1
    ret

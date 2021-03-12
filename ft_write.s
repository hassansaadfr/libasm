global _ft_write
_ft_write:
	mov		r8, rdx			; on stocke arg3 dans r8
	mov		rax, 0x2000004	; syscall a write
	syscall
		jc	error_exit		; si erreur jump error_exit
	jmp		exit_success	; sinon exit success

error_exit:
	mov rax, -1				; rax ( valeur de retour ) devient -1
	ret						; return

exit_success:
	mov		rax, r8			; rax ( valeur de retour ) devient nombre de characteres print
	ret						; return


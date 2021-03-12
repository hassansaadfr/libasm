segment .text
	global _ft_read

_ft_read:
	mov 	rax, 0x2000003	; on met l'appel a read dans rax
	syscall					; syscall a rax
		jc exit_error		; Si erreur exit_error
	jmp exit				; Sinon jump exit

exit_error:
	mov 	rax, -1			; rax (valeur de retour) devient -1
	ret						; return

exit:
	ret						; return

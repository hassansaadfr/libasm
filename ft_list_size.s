global ft_list_size

ft_list_size :
		xor		rax, rax		; initialise compteur rax
		cmp		rdi, 0			; compare arg à NULL
		je		exit

	count :
		inc		rax				; rax + 1

	while :
		mov		r8, [rdi + 8]	; r8 = lst->next
		mov		rdi, r8			; current =  current->next
		cmp		rdi, 0			; if (current == NULL)
		je		exit			; jump exit
		jmp		count			; re-loop

	exit :
		ret						; return RAX

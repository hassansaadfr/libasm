global ft_strcpy

ft_strcpy:
	xor		rcx, rcx				; initialisation variable compteur
	jmp		copy					; jump dans copy

copy:
	cmp		byte [rsi + rcx], 0		; si caractere actuel est \0
	jz		exit					; jump exit
	mov		dl, [rsi + rcx]			; copie le charactere qui est rsi (arg1) + compteur donc arg1[i] dans DL qui fait 1 octet
	mov		[rdi + rcx], dl			; copie dans le char* s[i] le charactere qui se trouve dans DL
	inc		rcx						; incremente compteur
	jmp		copy					; re jump en haut de la boucle
exit:
	mov		BYTE [rdi + rcx], 0		; ajout du \0
	mov		rax, rdi				; copie de rdi dans rax
	ret								; return

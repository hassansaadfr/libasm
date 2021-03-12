global _ft_strlen

_ft_strlen:
	xor		rcx, rcx					; Initialise une variable compteur a zero
	jmp		count						; jump dans count

count:
	cmp 	BYTE [rdi + rcx], 0			; si rdi[rcx] (param1[compteur]) est \0
	je		exit						; si resultat de l'expression precedente est 1 jump exit
	inc		rcx							; incremente rcx (compteur)
	jmp		count						; jump au debut de la loop

exit:
	mov rax, rcx						; copie de rcx (compteur) dans rax qui correspond a ce qui sera return
	ret									; return

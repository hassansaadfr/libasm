
global _ft_strcmp
_ft_strcmp:
	xor		rcx, rcx					; Initialise une variable compteur a zero
	xor		rax, rcx					; Initialise une variable compteur a zero

compare:
	cmp		BYTE [rdi + rcx], 0			; check si le charactere de arg1 + i est \0
	jz		exit						; jump exit si instruction precedente = 1
	cmp		BYTE [rsi + rcx], 0			; check si le charactere de arg2 + i est \0
	jz		exit						; jump exit si instruction precedente = 1
	mov		al, BYTE [rsi + rcx]		; on met le charactere de arg2[i] dans al pour la comparaison a venir
	cmp		BYTE [rdi + rcx], al		; comparaison entre arg1[i] et ce qui est dans al arg2[i]
	jnz		exit						; si comparaison != 1 jump exit
	inc		rcx							; incremente compteur
	jmp		compare						; recommence
exit:
	movzx	rax, BYTE[rdi + rcx]		; copie le contenu de droite 8bits dans rax 64bits
	movzx	rdx, BYTE[rsi + rcx]		; copie le contenu de droite 8bits dans rax 64bits
	sub		rax, rdx					; rax - rdx
	ret									; return rax

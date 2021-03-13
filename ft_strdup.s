
global ft_strdup
extern malloc						; inclure fonction malloc
extern ft_strlen					; inclure fonction ft_strlen
extern ft_strcpy					; inclure fonction ft_strcpy
;extern ___error						; inclure la macro errno (mac) pour mac inclure __errno_location
extern __errno_location			; inclure la macro errno (mac) pour linux inclure __errno_location

ft_strdup:
	push	rdi						; push rax qui contient la valeur de arg1
	call	ft_strlen				; appel de la fonction ft_strlen qui renvoi son resultat dans rax
	inc		rax						; incremente le retour de ft_strlen contenu dans rax
	mov		rdi, rax				; copie rax (ft_strlen) dans rdi
	call	malloc wrt ..plt		; appel malloc avec rdi (ft_strlen + 1)
	cmp		rax, 0					; si malloc retourne une erreur
	jz		error_exit				; si la comparaison d'avant retourne 1 jump error_exit
	pop		rsi						; rsi recupere la valeur de arg1 qui avait été push
	mov		rdi, rax				; rdi = rax (arg1 = ft_strlen + 1) pour envoyer a ft_strlen
	call	ft_strcpy				; appel de ft_strcpy avec rdi en arg (ft_strlen + 1)
	ret								; return

error_exit:
	pop		rdi
	ret								; return

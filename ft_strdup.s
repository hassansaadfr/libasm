
global _ft_strdup
extern _malloc						; inclure fonction malloc
extern _ft_strlen					; inclure fonction _ft_strlen
extern _ft_strcpy					; inclure fonction _ft_strcpy
extern ___error						; inclure la macro errno (mac) pour linux inclure __errno_location
;extern __errno_location			; inclure la macro errno (mac) pour linux inclure __errno_location

_ft_strdup:
	call	_ft_strlen				; appel de la fonction ft_strlen qui renvoi son resultat dans rax
	push	rdi						; push rax qui contient la valeur de arg1
	inc		rax						; incremente le retour de ft_strlen contenu dans rax
	mov		rdi, rax				; copie rax (ft_strlen) dans rdi
	call	_malloc					; appel malloc avec rdi (ft_strlen + 1)
	cmp		rax, 0					; si malloc retourne une erreur
	jz		error_exit				; si la comparaison d'avant retourne 1 jump error_exit
	mov		rdi, rax				; rdi = rax (arg1 = ft_strlen + 1) pour envoyer a ft_strlen
	pop		rsi						; rsi recupere la valeur de arg1 qui avait été push
	call	_ft_strcpy				; appel de ft_strcpy avec rdi en arg (ft_strlen + 1)
	ret								; return

error_exit:
	neg		rax						; rax *= -1 parce que l'erreur malloc renvoi un entier negatif
	mov		rdi, rax				; rdi (arg1) = valeur de retour de malloc
	call	___error				; appel a errno
;	call	___error_location		; Gestion d'erreur pour linux
	mov		[rax], rdi				; rax devient rdi
	mov		rax, -1					; rax (valeur de retour) devient -1 car on a une erreur
	ret								; return

;ft_strlen.s
segment .text
	global ft_strcpy

ft_strlen:
	mov		rax, 0
	jmp		count

count:
	cmp BYTE [rdi + rax], 0
	je	exit
	inc	rax
	jmp	count

exit:
	ret

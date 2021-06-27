segment .text
	global	ft_read
;	extern	___error

ft_read:
	mov		rax,	0x2000003
	syscall
;	jc		exit_error
	ret

exit_error:
	push	rax
;	call	___error
	pop		rdx
	mov		[rax],	rdx
	mov		rax,	-1
	ret

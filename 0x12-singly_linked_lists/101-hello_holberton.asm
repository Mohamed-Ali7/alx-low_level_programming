section .data
	hello db 'Hello, Holberton', 0
	format db '%s', 0
	newline db 10, 0

section .text
	extern printf

	global _start

_start:
	sub rsp, 8

	mov edi, format
	mov esi, hello
	xor eax, eax

	call printf

	mov edi, format
	mov esi, newline
	xor eax, eax

	call printf

	add rsp, 8

	mov eax, 60
	xor edi, edi
	syscall

org 100h

lea si, arrayA
lea di, arrayB
lea bx, arrayC
mov cx, n*n
mov dl, i
for:
    mov ax, [di]
    mul dl
    add ax, [si]
    mov [bx], ax
    add si, 2
    add di, 2
    add bx, 2
loop for

n equ 3
i equ 2
arrayA  dw 1, 2, 3
        dw 4, 5, 6
        dw 7, 8, 9
arrayB  dw 1, 1, 1
        dw 1, 1, 1
        dw 1, 1, 1
arrayC dw n dup(n dup(?))

ret
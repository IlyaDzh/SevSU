STACKSG SEGMENT PARA 'Stack'
    db 16 dup('STACKSEG')
STACKSG ENDS

;----------------------------------------------------------------

DATASG SEGMENT PARA 'Data'
    matrix dw 1, 2, 3, 4, 5, 6, 7, 8
        dw 4, 5, 6, 7, 8, 9, 10, 11
        dw 7, 8, 9, 10, 11, 12, 13, 14
        dw 10, 11, 12, 13, 14, 15, 16, 17
        dw 13, 14, 15, 16, 17, 18, 19, 20
        dw 16, 17, 18, 19, 20, 21, 22, 23
        dw 13, 14, 15, 16, 17, 18, 19, 20
        dw 16, 17, 18, 19, 20, 21, 22, 23
    mas dw 300h
    n dw 100+10*8
    mas1 dw 400h
    mas2 dw 500h
    number dw 11
    answer dw 600h
    m dw 8
DATASG ENDS

;----------------------------------------------------------------

CODESG SEGMENT PARA 'Code'
ASSUME SS: STACKSG, CS:CODESG, DS:DATASG, ES:NOTHING
    mov ax, DATASG
    mov ds, ax
    
    WRITE_ARRAY PROC FAR
        mov di,mas
        mov bx, 0h
        mov cx, n
        For:
            add bx, 1
            mov ds:di,bx
            add di, 2
        loop For
    WRITE_ARRAY ENDP
    
    ;----------------------------------------------------------------
    
    SEND_ARRAY PROC FAR
        mov bx, mas1
        mov di, mas2
        mov cx, mas
        add cx, n
        add cx, n
        sub cx, bx
        Next:
            mov ax, ds:bx
            mov ds:di, ax
            add bx, 2
            add di, 2
            sub cx, 1
        loop Next
    SEND_ARRAY ENDP
    
    ;----------------------------------------------------------------
    
    SEARCH_ELEM PROC FAR
        mov di, mas
        mov bx, 0
        mov cx, n
        Search:
            mov ax, ds:di
            cmp ax, number
            jz EndSearch
            add di, 2
            add bx, 1
        loop Search
        EndSearch:
            mov di, answer
            mov ds:di, bx
    SEARCH_ELEM ENDP
    
    ;----------------------------------------------------------------
    
    _MATRIX PROC FAR
        mov ax, 2020h
        mov es, ax
        mov di, 300h
        lea bx, matrix
        mov cx, m
        While:
            mov es:di, [bx]
            add bx, m
        loop While
    _MATRIX ENDP
    
CODESG ENDS
End
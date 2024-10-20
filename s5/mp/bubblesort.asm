.model small
.stack 100h


.data
  arr db 02h,08h,03h,50h,01h,09h
  arrlen db 06h
  i db 00h
  j db 00h

.code
  main proc
    mov ax,@data
    mov ds,ax
    
    outerLoop:
      mov ax,0000h
      mov al, arrlen
      mov bl, i
      cmp bl,al
      jae exit
      mov j, 00h
      innerLoop:
        mov al,arrlen
        sub al, i
        sub al, 1h
        mov bl, j
        cmp bl,al
        jae nextOuter
        
        lea bx,arr
        mov al,  j
        mov si, ax
        mov cl, [bx+si]
        add ax,1h
        mov si, ax
        mov dl, [bx+si]

        cmp cl,dl
        jbe incre
        mov [bx+si], cl
        mov ax, si
        sub ax,1h
        mov si, ax
        mov [bx+si], dl
        incre:
          inc j
        jmp innerLoop  
        
        nextOuter:
        inc i
        jmp outerLoop

  exit:
    mov ah, 4ch
    int 21h

  main endp
  
.model small
.stack 100h

.data
    str db "Hello World", 0
    strLen dw 000Bh         ; Length of "Hello World" (11 characters)
    substr dw "lor", 0     ; Substring to search for
    found db "Substring found$", 0
    not_found db "Not substring$", 0
    i dw 0000h               ; Outer loop index
    j dw 0000h               ; Inner loop index

.code
main proc
    ; Initialize data segment
    mov ax, @data
    mov ds, ax

    outerloop:
        ; Check if end of the main string has been reached
        mov ax, i
        mov bx, strLen
        cmp ax,bx
        jae notFound        ; If `i` >= `strLen`, jump to notFound
        
        ; Reset inner loop index
        mov j, 0000h
        
        innerloop:
            ; Compare characters from str[i + j] and substr[j]
            lea bx, substr
            mov si, j
            mov cl,[bx+si]
            
            lea bx, str
            mov ax, i
            add ax, j 
            mov si, ax
            mov al,[bx+si]
            
            ; Check if we've reached the end of the substring
            cmp cl, 0
            je foundPrint   ; Substring found if end of substring reached
            
            ; Check if we've reached the end of the main string
            cmp al, 0
            je notFound     ; If end of main string, substring is not found
            
            ; Compare current characters from str and substr
            cmp al, cl
            jne next_outer  ; If characters don't match, move to the next position
            
            ; If characters match, continue comparing the next ones
            inc j
            jmp innerloop   ; Keep comparing substr[j] with str[i + j]
        
        next_outer:
            ; Move to the next character in the main string
            inc i
            jmp outerloop   ; Restart the outer loop
        
    notFound:
        lea dx, not_found   ; Load address of not_found message
        mov ah, 09h         ; DOS print string function
        int 21h             ; Interrupt to print the message
        jmp exit            ; Exit the program
    
    foundPrint:
        lea dx, found       ; Load address of found message
        mov ah, 09h         ; DOS print string function
        int 21h             ; Interrupt to print the message
        
    exit:
        mov ah, 4ch         ; Exit the program
        int 21h
    
main endp
end main
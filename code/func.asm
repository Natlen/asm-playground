extern printf:proc
extern dummyfunc:proc

.data
    format  db  "%s", 0
    msg     db  "test from asm function calling printf", 13, 10 , 0
    
.code

public func
func proc
    sub rsp,56                      ; allocate shadowspace - 32 - save rcx, rdx, r8, r9 | (56-32) for other stack sapce

    mov [rsp+32], rcx               ; store parm at stack
    lea rcx,format
    lea rdx,msg
    call printf

    mov rsi, [rsp+32]               ; load param from stack
    mov rcx, [rsi]                  ; load dummy.x              <int>
    mov rdx, [rsi+4]                ; dummy.func_ptr            <bool (*)(const Dummy&, const Dummy)>
    movsd xmm2, qword ptr [rsi+12]  ; load dummy.y              <double>
    mov r9, [rsi+20]                ; load dummy.t              <const char*>
    mov rax, [rsi+28]               ; temp load dummy.u on reg 
    mov [rsp+32],rax                ; load dummy.u on stack     <unsinged long long>
    mov rax, [rsi+36]               ; temp load dummy.z on reg
    mov [rsp+40],rax                ; load dummy.u on stack     <void*>
    mov [rsp+48],rsi                ; load dummy on stack       <const Dummy&>
    call dummyFunc                  ;returns double at xmm0     <double>
                                    
    add rsp,56                      ; deallocate shadowspace
    ret
func endp

end
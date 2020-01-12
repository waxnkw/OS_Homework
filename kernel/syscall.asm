
; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;                               syscall.asm
; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
;                                                     Forrest Yu, 2005
; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

%include "sconst.inc"

INT_VECTOR_SYS_CALL equ 0x90
_NR_get_ticks       equ 0
_NR_write	    equ 1
_NR_disp_str_me     equ 2
_NR_process_sleep   equ 3
_NR_sleep           equ 4
_NR_wakeup          equ 5
_NR_sem_p           equ 6
_NR_sem_v           equ 7

; 导出符号
global	get_ticks
global	write
global  disp_str_me
global  process_sleep
global  sleep
global  wakeup
global  sem_p
global  sem_v

bits 32
[section .text]

; ====================================================================
;                              get_ticks
; ====================================================================
get_ticks:
	mov	eax, _NR_get_ticks
	int	INT_VECTOR_SYS_CALL
	ret

; ====================================================================================
;                          void write(char* buf, int len);
; ====================================================================================
write:
        mov     eax, _NR_write
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

; ====================================================================================
;                          void disp_str_me(char* str, int color);
; ====================================================================================
disp_str_me:
        mov     eax, _NR_disp_str_me
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

; ====================================================================================
;                        void process_sleep(int milli_seconds, PROCESS* )
; ====================================================================================
process_sleep:
        mov     eax, _NR_process_sleep
        mov     ebx, [esp + 4]
        ;mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

; ====================================================================================
;                      void sleep(PROCESS* list[], int wait)
; ====================================================================================
sleep:
        mov     eax, _NR_sleep
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

; ====================================================================================
;                      void wakeup(PROCESS* list[], int wait)
; ====================================================================================
wakeup:
        mov     eax, _NR_wakeup
        mov     ebx, [esp + 4]
        mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

; ====================================================================================
;                     void sem_p(SEMAPHORE* sem)
; ====================================================================================
sem_p:
        mov     eax, _NR_sem_p
        mov     ebx, [esp + 4]
        ;mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

; ====================================================================================
;                     void sem_v(SEMAPHORE* sem)
; ====================================================================================
sem_v:
        mov     eax, _NR_sem_v
        mov     ebx, [esp + 4]
        ;mov     ecx, [esp + 8]
        int     INT_VECTOR_SYS_CALL
        ret

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            global.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#define GLOBAL_VARIABLES_HERE

#include "type.h"
#include "const.h"
#include "protect.h"
#include "tty.h"
#include "console.h"
#include "proc.h"
#include "global.h"
#include "proto.h"


PUBLIC	PROCESS	proc_table[NR_TASKS + NR_PROCS];

PUBLIC	TASK	task_table[NR_TASKS] = {
	{task_tty, STACK_SIZE_TTY, "tty"}};

PUBLIC  TASK    user_proc_table[NR_PROCS] = {
	{TestA, STACK_SIZE_TESTA, "TestA"},
	{Barber, STACK_SIZE_TESTB, "Barber"},
	{Customer1, STACK_SIZE_TESTC, "Customer1"},
	{Customer2, STACK_SIZE_TESTD, "Customer2"},
	{Customer3, STACK_SIZE_TESTE, "Customer3"},
	};

PUBLIC	char		task_stack[STACK_SIZE_TOTAL];

PUBLIC	TTY		tty_table[NR_CONSOLES];
PUBLIC	CONSOLE		console_table[NR_CONSOLES];

PUBLIC	irq_handler	irq_table[NR_IRQ];

PUBLIC	system_call	sys_call_table[NR_SYS_CALL] = {sys_get_ticks, sys_write, 
sys_disp_str, sys_process_sleep, sys_sleep, sys_wakeup, sys_sem_p, sys_sem_v};


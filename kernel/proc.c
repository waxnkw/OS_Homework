
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               proc.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "tty.h"
#include "console.h"
#include "string.h"
#include "proc.h"
#include "global.h"
#include "proto.h"

/*======================================================================*
                              schedule
 *======================================================================*/
PUBLIC void schedule()
{
	PROCESS* p;
	int	 greatest_ticks = 0;

	while (!greatest_ticks) {
		for (p = proc_table; p < proc_table+NR_TASKS+NR_PROCS; p++) {
			if(p->is_sleeping){
				continue;
			}
			//有睡眠时间就睡眠
			if (p->sleep_ticks>0){
				p->sleep_ticks--;
				continue;
			}
			if (p->ticks > greatest_ticks) {
				greatest_ticks = p->ticks;
				p_proc_ready = p;
				//disp_str(p_proc_ready->p_name);
			}
		}

		if (!greatest_ticks) {
			for(p=proc_table;p<proc_table+NR_TASKS+NR_PROCS;p++) {
				p->ticks = p->priority;
			}
		}
	}
}

/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	return ticks;
}

/*======================================================================*
                           sys_sleep
 *======================================================================*/
PUBLIC void sys_sleep(PROCESS* list[], int wait, PROCESS* p_proc){
	p_proc->is_sleeping = 1;
	list[wait] = p_proc;
}


/*======================================================================*
                           sys_wakeup
 *======================================================================*/
PUBLIC void sys_wakeup(PROCESS* list[], int wait){
	int i=0;
	list[0]->is_sleeping = 0;
	for(i=1; i<wait; i++){
		list[i-1] = list[i];
	}
	list[wait] = 0;
}

/*======================================================================*
                           sys_sem_p
 *======================================================================*/
PUBLIC void sys_sem_p(SEMAPHORE* sem){
	sem->value--;
	if(sem->value<0){
		sleep(sem->list, -sem->value-1);
	}
}


/*======================================================================*
                           sys_sem_v
 *======================================================================*/
PUBLIC void sys_sem_v(SEMAPHORE* sem){
	sem->value++;
	if(sem->value<=0){
		wakeup(sem->list, -sem->value);
	}
}
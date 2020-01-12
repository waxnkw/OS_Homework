
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                            proto.h
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* klib.asm */
PUBLIC void	out_byte(u16 port, u8 value);
PUBLIC u8	in_byte(u16 port);
PUBLIC void	disp_str(char * info);
PUBLIC void	disp_color_str(char * info, int color);
PUBLIC void disp_color_int(int input, int color);

/* protect.c */
PUBLIC void	init_prot();
PUBLIC u32	seg2phys(u16 seg);

/* klib.c */
PUBLIC void	delay(int time);

/* kernel.asm */
void restart();

/* main.c */
void TestA();
void Barber();
void Customer1();
void Customer2();
void Customer3();

/* i8259.c */
PUBLIC void put_irq_handler(int irq, irq_handler handler);
PUBLIC void spurious_irq(int irq);

/* clock.c */
PUBLIC void clock_handler(int irq);
PUBLIC void init_clock();

/* keyboard.c */
PUBLIC void init_keyboard();

/* tty.c */
PUBLIC void task_tty();
PUBLIC void in_process(TTY* p_tty, u32 key);

/* console.c */
PUBLIC void out_char(CONSOLE* p_con, char ch);
PUBLIC void scroll_screen(CONSOLE* p_con, int direction);

/* printf.c */
PUBLIC  int     printf(const char *fmt, ...);

/* vsprintf.c */
PUBLIC  int     vsprintf(char *buf, const char *fmt, va_list args);

/* 以下是系统调用相关 */

/* 系统调用 - 系统级 */
/* proc.c */
PUBLIC  int     sys_get_ticks();
PUBLIC  int     sys_write(char* buf, int len, PROCESS* p_proc);
PUBLIC  void    sys_disp_str(char * str, int color);
PUBLIC  void    sys_process_sleep(int milli_seconds);
PUBLIC  void    sys_sleep(PROCESS* list[], int wait, PROCESS* p_proc);
PUBLIC  void    sys_wakeup(PROCESS* list[], int wait);
PUBLIC  void    sys_sem_p(SEMAPHORE* sem);
PUBLIC  void    sys_sem_v(SEMAPHORE* sem);
/* syscall.asm */
PUBLIC  void    sys_call();             /* int_handler */

/* 系统调用 - 用户级 */
PUBLIC  int     get_ticks();
PUBLIC  void    write(char* buf, int len);
PUBLIC  void    disp_str_me(char* str, int color);
PUBLIC  void    process_sleep(int milli_seconds);
PUBLIC  void    sleep(PROCESS* list[], int wait);
PUBLIC  void    wakeup(PROCESS* list[], int wait);
PUBLIC  void    sem_p(SEMAPHORE* sem);
PUBLIC  void    sem_v(SEMAPHORE* sem);


/*  */
PUBLIC void customer_process_func(int color);
PUBLIC void customer_wait(int color);
PUBLIC void customer_get_haircut(int color);
PUBLIC void customer_leave(int color);
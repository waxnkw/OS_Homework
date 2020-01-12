cmake_minimum_required(VERSION 3.10)
project(o)

set(CMAKE_CXX_STANDARD 11)

include_directories(boot/include)
include_directories(include)

add_executable(o
        boot/include/fat12hdr.inc
        boot/include/load.inc
        boot/include/pm.inc
        boot/boot.asm
        boot/loader.asm
        include/console.h
        include/const.h
        include/global.h
        include/keyboard.h
        include/keymap.h
        include/proc.h
        include/protect.h
        include/proto.h
        include/sconst.inc
        include/string.h
        include/tty.h
        include/type.h
        kernel/clock.c
        kernel/console.c
        kernel/global.c
        kernel/i8259.c
        kernel/kernel.asm
        kernel/keyboard.c
        kernel/main.c
        kernel/printf.c
        kernel/proc.c
        kernel/protect.c
        kernel/start.c
        kernel/syscall.asm
        kernel/tty.c
        kernel/vsprintf.c
        lib/klib.c
        lib/kliba.asm
        lib/string.asm
        a.img
        bochsrc
        Makefile)

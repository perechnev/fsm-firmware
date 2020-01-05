#include <stdio.h>

int __attribute__((section(".app_kill"))) entry(int state) {
    puts("Hello from kill application.\n");
    return 0;
}

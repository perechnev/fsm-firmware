#include <kernel.h>

int __kcall(int call, int p1) {
    int result = 0;

    __asm__("PUSH {r0-r7}");
    __asm__("MOV r0, %0" : : "r" (call));
    __asm__("MOV r1, %0" : : "r" (p1));
    __asm__("SVC #0x00");
    __asm__("MOV %0, r7" : "=r" (result));
    __asm__("POP {r0-r7}");

    return result;
}

void * kc_allocate(int size) {
    return (void *)__kcall(KCALL_ALLOCATE, size);
}

int kc_retain(void * address) {
    return __kcall(KCALL_RETAIN, (int)address);
}

int kc_release(void * address) {
    return __kcall(KCALL_RELEASE, (int)address);
}

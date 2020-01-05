#ifndef __LIBKERNEL_KCALL_H__
#define __LIBKERNEL_KCALL_H__

#include <kernel/kernel.h>

void * kc_alloc(int size);
int kc_retain(void * address);
int kc_release(void * address);
int kc_spawn(void * entry);
int kc_kill(int id);
int kc_send(k_mail_t * message);
k_mail_t * kc_receive(int process_id);

#endif /* __LIBKERNEL_KCALL_H__ */

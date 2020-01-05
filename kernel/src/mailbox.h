#ifndef __KERNEL_MAILBOX_H__
#define __KERNEL_MAILBOX_H__

#include <kernel.h>

int mailbox_send(k_mail_t * message);
k_mail_t * mailbox_receive(int process_id);

#endif /* __KERNEL_MAILBOX_H__ */

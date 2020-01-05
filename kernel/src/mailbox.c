#include <kernel.h>
#include "mailbox.h"
#include "memory.h"

#define MAX_MAILS   5

k_mail_t * mailbox[MAX_MAILS];

int mailbox_send(k_mail_t * message) {
    for (int i = 0; i < MAX_MAILS; i++) {
        if (mailbox[i] == K_NULL) {
            memory_retain(message);
            memory_retain(message->data);
            mailbox[i] = message;
            return 0;
        }
    }
    return -1;
}

k_mail_t * mailbox_receive(int process_id) {
    for (int i = 0; i < MAX_MAILS; i++) {
        if (mailbox[i] == K_NULL) {
            continue;
        }
        if (mailbox[i]->receiver_id == process_id) {
            k_mail_t * mail = mailbox[i];
            mailbox[i] = K_NULL;
            return mail;
        }
    }
    return K_NULL;
}

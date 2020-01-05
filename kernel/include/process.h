#ifndef __KERNEL_PROCESS_H__
#define __KERNEL_PROCESS_H__

typedef int process_entry(int state);

int process_spawn(process_entry * entry);
int process_kill(int process_id);

#endif /* __KERNEL_PROCESS_H__ */

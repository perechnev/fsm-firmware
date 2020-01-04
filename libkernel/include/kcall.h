#ifndef __LIBKERNEL_KCALL_H__
#define __LIBKERNEL_KCALL_H__

void * kc_alloc(int size);
int kc_retain(void * address);
int kc_release(void * address);

#endif /* __LIBKERNEL_KCALL_H__ */

## Kernel calls

### System
* `void kc_reset();` _Not implemented_

### Memory

* `void * kc_allocate(int size);`
Finds a free block of memory of `size` bytes and retains it.
Returns a pointer to allocated memory or `NULL` if no free block was found.

* `int kc_retain(void * address);`
Retains the block of memory pointed in `address`.
Returns the result number of block retains.

* `int kc_release(void * address);`
Releases the block of memory pointed in `address` and deallocates it if number of retains becomes zero.
Returns the result number of block retains.

### Process

* `int kc_spawn(void * entry);`
Spawns a new process with entry point at `entry`.
Returns process identifier if process spawned successfully. Otherwise returns `-1`.

* `int kc_kill(int process_id);`
Kills process with identifier specified in `process_id`.
Returns `0` if process was successfully killed.

### Mailbox

* `int kc_send(k_mail_t * message);`
Puts mail to mailbox.
Returns `0` in case of success.

* `k_mail_t * kc_receive(int process_id);`
Takes the first mail found for process specified in `process_id`.
Returns a pointer to mail or NULL in case of no mail found.

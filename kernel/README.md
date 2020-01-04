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
* `kc_spawn();` _Not implemented_
* `kc_kill();` _Not implemented_
* `kc_send();` _Not implemented_
* `kc_receive();` _Not implemented_

### Node
* `kc_write();` _Not implemented_
* `kc_read();` _Not implemented_

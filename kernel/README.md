## Kernel calls

### System
* `void kc_reset();`

### Memory
* `void * kc_alloc(int size);`
* `int kc_retain(void * address);`
* `int kc_release(void * address);`

### Process
* `kc_spawn();`
* `kc_kill();`
* `kc_send();`
* `kc_receive();`

### Node
* `kc_write();`
* `kc_read();`

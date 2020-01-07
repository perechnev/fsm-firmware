#include <kernel/kcall.h>
#include "stddef.h"

void * calloc(size_t nmemb, size_t size) {
    return kc_allocate(size * nmemb);
}

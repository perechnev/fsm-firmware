#include "process.h"

typedef struct {
    process_entry * entry;
    int state;
} process_t;

#define MAX_PROCESS_COUNT   10

process_t process_list[MAX_PROCESS_COUNT];

int process_init() {
    for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
        process_list[i].entry = 0;
    }
}

int process_spawn(process_entry * entry) {
    for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
        if (process_list[i].entry == 0) {
            process_list[i].entry = entry;
            process_list[i].state = 1;
            return i;
        }
    }

    return -1;
}

int process_kill(int process_id) {
    process_list[process_id].entry = 0;
    return 0;
}

void process_schedule() {
    while (1) {
        for (int i = 0; i < MAX_PROCESS_COUNT; i++) {
            if (process_list[i].entry != 0) {
                process_list[i].state = process_list[i].entry(process_list[i].state);

                if (process_list[i].state == 0) {
                    process_kill(i);
                }
            }
        }
    }
}

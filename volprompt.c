// volprompt.c
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <poll.h>

#define NUM_DEVS    2
static const char *devices[NUM_DEVS] = {
    "/dev/input/event2",  // where KEY_VOLUMEUP appears
    "/dev/input/event0"   // where KEY_VOLUMEDOWN appears
};

#define KEY_VOLUP    115
#define KEY_VOLDOWN  114

int main(void) {
    struct pollfd fds[NUM_DEVS];
    struct input_event ev;
    int i, ret;

    // open each device for reading
    for (i = 0; i < NUM_DEVS; i++) {
        int fd = open(devices[i], O_RDONLY);
        if (fd < 0) {
            perror(devices[i]);
            return 2;
        }
        fds[i].fd = fd;
        fds[i].events = POLLIN;
    }

    // prompt (prints to recovery console)
    printf("Press Volume-Up for YES or Volume-Down for NO...\n");

    // wait for events
    while (1) {
        ret = poll(fds, NUM_DEVS, -1);
        if (ret <= 0) {
            perror("poll");
            return 3;
        }
        for (i = 0; i < NUM_DEVS; i++) {
            if (fds[i].revents & POLLIN) {
                if (read(fds[i].fd, &ev, sizeof(ev)) != sizeof(ev)) {
                    perror("read");
                    return 4;
                }
                if (ev.type == EV_KEY && ev.value == 1) {
                    if (ev.code == KEY_VOLUP) {
                        printf("Detected Volume-Up → YES\n");
                        return 0;  // YES
                    }
                    if (ev.code == KEY_VOLDOWN) {
                        printf("Detected Volume-Down → NO\n");
                        return 1;  // NO
                    }
                }
            }
        }
    }
    return 0;
}

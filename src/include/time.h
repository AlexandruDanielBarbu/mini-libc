#ifndef __TIME_H__
#define __TIME_H__	1

struct timespec {
    long long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *duration, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#endif

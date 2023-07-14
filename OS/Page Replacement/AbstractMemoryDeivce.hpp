#ifndef ABS_MEM_DEV_H_
#define ABS_MEM_DEV_H_

class AbstractMemeoryDevice {
public:
    AbstractMemeoryDevice(int max_cap) : MAX_CAP(max_cap) {}
    AbstractMemeoryDevice& operator=(const AbstractMemeoryDevice&) = delete;
    virtual void get(int) = 0;
    virtual void put(int, int&&) = 0;
protected:
    const int MAX_CAP;
};

#endif
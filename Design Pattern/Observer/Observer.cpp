#include <iostream>
#include <algorithm>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>

// Interface for the Observer
class Observer {
public:
    virtual void update(int state) = 0;
};

// Concrete Observer
class ConcreteObserver final : public Observer {
public:
    void update(int state) override {
        this->state = state;
        std::cout << "Observer received state update: " << state << std::endl;
    }

private:
    std::atomic<int> state;
};

// Interface for the Subject
class Subject {
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject
class ConcreteSubject final : public Subject {
public:
    void set_state(int state) {
        std::lock_guard<std::mutex> lock(mtx);
        this->subject_state = state;
        std::cout << "Subject state changed to: " << state << std::endl;
        this->notify();
        std::cout << "Observered notified" << std::endl;
    }

    int get_state() {
        std::lock_guard<std::mutex> lock(mtx);
        return this->subject_state;
    }

    void attach(Observer *observer) override {
        std::lock_guard<std::mutex> lock(mtx);
        this->observers.push_back(observer);
        std::cout << "Observer attached" << std::endl;
    }

    void detach(Observer *observer) override {
        std::lock_guard<std::mutex> lock(mtx);
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        std::cout << "Observer detached" << std::endl;
    }

private:
    std::mutex mtx;
    int subject_state;
    std::vector<Observer*> observers;

    void notify() override {
        for (auto observer : this->observers) {
            observer->update(this->subject_state);
        }
    }
};

void change_state(ConcreteSubject &subject, int state) {
    subject.set_state(state);
}

int main() {
    ConcreteSubject subject;
    ConcreteObserver observer1, observer2;

    subject.attach(&observer1);
    subject.attach(&observer2);

    std::thread t1(change_state, std::ref(subject), 10);
    std::thread t2(change_state, std::ref(subject), 20);

    t1.join();
    t2.join();

    subject.detach(&observer1);
    change_state(subject, 42);

    return 0;
}
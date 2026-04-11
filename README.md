*This project has been created as part of the 42 curriculum by maralves.*

# 🍝 Philosophers

## 📌 Description

The **Philosophers** project is a classic concurrency problem that explores thread synchronization, race conditions, and resource sharing.

The goal is to simulate a group of philosophers sitting at a table, alternating between:
- thinking 🤔
- eating 🍝
- sleeping 😴

Each philosopher needs two forks to eat, but forks are shared resources.  
This creates challenges such as:
- avoiding **deadlocks**
- preventing **data races**
- ensuring **timely death detection**

The simulation stops when:
- a philosopher dies ☠️  
- or all philosophers have eaten a specified number of times (optional argument)

---

## ⚙️ Instructions

### 🛠 Compilation
```bash
make
```
▶️ Execution
```bash
./philosophers number_of_philos time_to_die time_to_eat time_to_sleep [must_eat]
```

📥 Arguments

number_of_philos	Number of philosophers (and forks)
time_to_die	Time (ms) before a philosopher dies without eating
time_to_eat	Time (ms) spent eating
time_to_sleep	Time (ms) spent sleeping
must_eat (optional)	Number of times each philosopher must eat


🧪 Examples

Basic test
```bash
./philosophers 5 800 200 200
```
With must_eat condition
```bash
./philosophers 5 800 200 200 5
```
Edge case (1 philosopher)
```bash
./philosophers 1 800 200 200
```

🔍 Testing with Valgrind

Memory leak check
```bash
valgrind ./philosophers 5 500 200 200
```

With must_eat
```bash
valgrind ./philosophers 5 800 200 200 5
```

## 🧠 Key Concepts

- Threads (pthread)
- Mutexes (mutual exclusion)
- Race conditions
- Deadlock prevention
- Time-sensitive monitoring
- Resource sharing

---

## 🏗️ Project Structure

```
.
├── philosophers.c
├── monitoring.c
├── eat_sleep_rave_repeat.c
├── philosophers_routine.c
├── parse_input.c
├── table_control.c
├── time_control.c
├── print_control.c
├── aux_functions.c
├── philosophers.h
└── Makefile
```

---

## ⚡ Features

- Thread-safe simulation
- Precise death monitoring (≤ 10ms constraint)
- Clean shutdown of all threads
- Proper memory management (no leaks)
- Handles edge cases (like 1 philosopher)

---

## 📚 Resources

### 📖 Documentation & References

- The Dining Philosophers Problem
- POSIX Threads Programming
- Mutex explanation

---

## ✅ Final Notes

This project is a deep dive into multithreading and synchronization, requiring careful handling of shared data and timing.

Small mistakes can lead to:

- race conditions  
- deadlocks  
- incorrect outputs  
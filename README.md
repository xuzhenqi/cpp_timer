# cpp_timer
An efficient, convenient and header-only timer for cpp.

## Intro
Cpp_timer is useful for cpp programmers to profile their code's performance. It's implemented using std::chrono in c++11. Here are some features supported:
* Header only. So it's easy to be used in your code.
* Easy to turned off/on. The timer can be invoked by '-DCPPTIMER' when compiling. You need not comment out your timer code if you don't want them.
* Macros to profile a block of codes.
* Macros to profile blocks of codes in different position.

## Usage
To profile a block of codes, just add `TIMER_INIT(name)` and `TIMER_ELAPSED(name)` in your code.

```
TIMER_INIT(name)
// some codes here
TIMER_ELAPSED(name)
```

We also provide accumulate timers for blocks of codes.
```
TIMER_INIT(name1)
TIMER_INIT(name2)
for (int i = 0; i < 10; ++i) {
    TIMER_RESET(name1)
    // some code here
    TIMER_COUNT(name1)
    TIMER_RESET(name2)
    // some code here
    TIMER_COUNT(name2)
}
TIMER_REPORT_COUNT(name1)
TIMER_REPORT_COUNT(name2)
```

To use the timer, compile your code with
```
g++ -std=c++11 -DCPUTIMER
```
If you don't want to the code to print out something in your screen, just leave `-DCPUTIMER` out. It's convenint for you to release your code.

## Installation
It's header only, so just copy to the include folder in your project.

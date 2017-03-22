/* Copyright(c). All Rights Reserved
 * Author: Xu Zhenqi
 * Email: xuzhenqi@gmail.com
 */

#ifndef CPP_TIMER_H_
#define CPP_TIMER_H_

#ifdef CPPTIMER
#include <chrono>
#include <iostream>
class CppTimer {
  typedef std::chrono::high_resolution_clock high_resolution_clock;
  typedef std::chrono::milliseconds milliseconds;
 public:
  CppTimer(): sum_(0) { Reset(); }
  void Reset() { start_ = high_resolution_clock::now(); }
  int64_t Elapsed() {
    return std::chrono::duration_cast<milliseconds>(
        high_resolution_clock::now() - start_).count();
  }
  int64_t Count() {
    sum_ += Elapsed();
    return sum_;
  }
  
  int64_t sum() { return sum_; }

 private:
  std::chrono::time_point<high_resolution_clock> start_;
  int64_t sum_;
};

#define TIMER_INIT(x) CppTimer x;
#define TIMER_RESET(x) x.Reset();
#define TIMER_ELAPSED(x) std::cout << "Timer " #x " Elapsed: " <<  x.Elapsed() \
    << "ms." << std::endl;
#define TIMER_COUNT(x) x.Count();
#define TIMER_REPORT_COUNT(x) std::cout << "Timer " #x " Count: " << x.sum() \
    << "ms." << std::endl;
#else  // CPPTIMER
#define TIMER_INIT(x)
#define TIMER_RESET(x)
#define TIMER_ELAPSED(x)
#define TIMER_COUNT(x)
#define TIMER_REPORT_COUNT(x)
#endif  // CPPTIMER

#endif  // CPP_TIMER_H_

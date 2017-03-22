/* Copyright(c). All Rights Reserved
 * Author: Xu Zhenqi
 * Email: xuzhenqi@gmail.com
 */

#include "cpp_timer.h"
#include <thread>
#include <chrono>

int main() {
  TIMER_INIT(a)
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  TIMER_ELAPSED(a)
  TIMER_INIT(b)
  TIMER_INIT(c)
  for (int i = 0; i < 10; ++i) {
    TIMER_RESET(b)
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    TIMER_COUNT(b)
    TIMER_RESET(c)
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    TIMER_COUNT(c)
  }
  TIMER_REPORT_COUNT(b)
  TIMER_REPORT_COUNT(c)
  return 0;
}

//
// File: Time.hpp
// Author: NgocPT <kyvophonge@gmail.com>
// Created: 2025-10-28 09:08:05
//

#ifndef TIME_HPP
#define TIME_HPP

struct Time {
  double time;
  double deltaTime;

  Time(double, double);
  void update();
};

#endif // TIME_HPP

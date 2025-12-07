#pragma once

#include "istatistics.h"

#include <limits>

class Mean : public IStatistics {
public:
  Mean() : m_sum{0.0}, m_nof{0} {}

  void update(double next) override {
    m_nof++;
    m_sum += next;
  }

  double eval() const override {
    return m_sum / static_cast<double>(m_nof);
  }

  const char * name() const override {
    return "mean";
  }

private:
  double m_sum;
  int m_nof;
};
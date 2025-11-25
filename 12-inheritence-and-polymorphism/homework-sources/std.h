#pragma once

#include "istatistics.h"
#include "mean.h"

#include <cmath>
#include <limits>
#include <vector>

class Std : public IStatistics {
public:
  Std() : m_mean{} {}

  void update(double next) override {
    m_mean.update(next);
    values.push_back(next);
  }

  double eval() const override {
    double sum = 0.0;
    double mean = m_mean.eval();
    for (int i = 0; i < values.size(); ++i) {
      sum += pow(values[i] - mean, 2);
    }
    return sqrt(sum / static_cast<double>(values.size()));
  }

  const char * name() const override {
    return "std";
  }

private:
  std::vector<double> values;
  Mean m_mean;
};
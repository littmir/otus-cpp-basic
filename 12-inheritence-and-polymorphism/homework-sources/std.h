#pragma once

#include "istatistics.h"
#include "mean.h"

#include <cmath>
#include <limits>
#include <vector>

class Std : public IStatistics {
public:
	Std() : m_mean{}, m_std{0}, m_sum{0}, m_nof{0} {}

	void update(double next) override {
    m_mean.update(next);
    double mean = m_mean.eval();

    values.push_back(next);
    
    m_nof++;

    m_sum = 0;
    for (int i = 0; i < m_nof; ++i) {
      m_sum += pow(values[i] - mean, 2);
    }
    
    m_std = sqrt(m_sum / static_cast<double>(m_nof));
	}

	double eval() const override {
		return m_std;
	}

	const char * name() const override {
		return "std";
	}

private:
  std::vector<double> values;
  Mean m_mean;
  double m_std;
  double m_sum;
  int m_nof;
};
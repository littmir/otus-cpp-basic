#pragma once

#include "istatistics.h"

#include <limits>

class Mean : public IStatistics {
public:
	Mean() : m_mean{0}, m_sum{0}, m_nof{0} {}

	void update(double next) override {
    m_nof++;
    m_sum += next;
    m_mean = (m_sum) / static_cast<double>(m_nof);
	}

	double eval() const override {
		return m_mean;
	}

	const char * name() const override {
		return "mean";
	}

private:
	double m_mean;
  double m_sum;
  int m_nof;
};
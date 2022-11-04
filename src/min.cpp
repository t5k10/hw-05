#include <limits>
#include "i_statistics.hpp"

class Min : public IStatistics {
  public:
    Min() : m_min{std::numeric_limits<double>::max()}, counter{0} {}

    void update(double next) override { 
        ++counter;
        if (next < m_min) { m_min = next; } 
    }

    double eval() const override { return counter == 0 ? 0.0 : m_min; }

    const char *name() const override  { return "min"; }

  private:
    double m_min;
    int counter;
};

#include <limits>
#include "i_statistics.hpp"

class Max: public IStatistics {
  public:
    Max() : m_max{std::numeric_limits<double>::min()}, counter{0} {}

    void update(double next) override {
        ++counter;
        if (next > m_max) { m_max = next; } 
    }

    double eval() const override { return counter == 0 ? 0.0 : m_max; }

    const char *name() const override  { return "max"; }

  private:
    double m_max;
    int counter;
};

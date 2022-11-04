#include "i_statistics.hpp"

class Mean : public IStatistics {
  public:
    Mean() : sum{0.0}, counter(0) {}

    void update(double next) override { 
        sum += next;
        ++counter;
    }

    double eval() const override { 
        if (counter == 0) return 0.0; 
        return sum / counter;
    }

    const char *name() const override  { return "mean"; }

  private:
   double sum;
   int counter;
};

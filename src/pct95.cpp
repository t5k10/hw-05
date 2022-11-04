#include <vector>
#include <algorithm>
#include <cmath>
#include "i_statistics.hpp"

class Pct95 : public IStatistics {
  public:
    Pct95() {}

    void update(double next) override { 
        values.push_back(next);
        std::sort(values.begin(), values.end()); 
    }

    double eval() const override { 
        if (values.size() == 0) return 0.0; 
        return values.at(std::ceil((0.95 * values.size()) - 1)) ;
    }

    const char *name() const override  { return "pct95"; }

  private:
   std::vector<double> values;
};

#include <vector>
#include <cmath>
#include "i_statistics.hpp"

class Std_deviation : public IStatistics {
  public:
    Std_deviation() : sum{0.0}, counter(0) {}

    void update(double next) override { 
        ++counter;
        sum += next;
        values.push_back(next);
    }

    double eval() const override { 
        if (counter == 0) return 0.0; 
        double average = sum / counter;
        double sum_of_diff = 0.0;
        for (double d : values) { 
            sum_of_diff += pow(fabs(d - average), 2);  
        }
        return sqrt(sum_of_diff / counter);
    }

    const char *name() const override  { return "std"; }

  private:
   double sum;
   int counter;
   std::vector<double> values;
};

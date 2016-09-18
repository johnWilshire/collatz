
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
DataFrame collatz(NumericVector x) {
  std::vector<int> lengths;
  std::vector<double> values;
  std::map<double, int> table;

  NumericVector::iterator it;
  for(it = x.begin(); it != x.end(); ++it) {
    double n = *it;
    values.push_back(n);
    double start = n;
    double count = 0;
    
    if(fmod(start,1) != 0){
      start = -1;
    }
    while(start > 1){
      if(table[start] != 0){
        count += table[start];
        start = 0;
      } else {
        count++;
        if (fmod(start, 2) == 0){
          start /= 2;
        } else {
          count++;
          start = (start*3 + 1)/2;
        }
      }
    }
    lengths.push_back(count);
    table[*it] = count;
  }
  
  return DataFrame::create(
    _["number"] = values,
    _["stopping_time"] = lengths 
  );
}
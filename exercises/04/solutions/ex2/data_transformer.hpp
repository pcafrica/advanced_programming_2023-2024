#ifndef DATA_TRANSFORMER_HPP__
#define DATA_TRANSFORMER_HPP__

#include "data_source.hpp"

class DataTransformer {
public:
  DataTransformer(DataSource &source) : source(source) {}

  virtual ~DataTransformer() {}

  virtual void apply() const = 0;

protected:
  DataSource &source;
};

class LinearScaler : public DataTransformer {
public:
  LinearScaler(DataSource &source, const double scaling_factor)
      : DataTransformer(source), scaling_factor(scaling_factor) {}

  void apply() const override;

private:
  const double scaling_factor;
};

class LogTransformer : public DataTransformer {
public:
  LogTransformer(DataSource &source) : DataTransformer(source) {}

  void apply() const override;
};

class StandardScaler : public DataTransformer {
public:
  StandardScaler(DataSource &source) : DataTransformer(source) {}

  void apply() const override;
};

#endif /* DATA_TRANSFORMER_HPP__ */

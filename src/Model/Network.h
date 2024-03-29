#ifndef S21_CCP7_MLP_MODEL_NETWORK_H
#define S21_CCP7_MLP_MODEL_NETWORK_H
#include <algorithm>
#include <chrono>
#include <memory>
#include <utility>

#include "Input.h"
#include "PerceptronMatrix.h"
#include "neuron.h"

namespace s21 {

class Network {
 public:
  virtual char PredictLetter(const vector_ &) const noexcept = 0;
  virtual void CrossValidation(Input &, const size_t &) = 0;
  virtual void WriteToFileWeights(const std::string &) = 0;
  virtual void ReadFromFileWeights(const std::string &) = 0;
  virtual void TrainNetwork(Input &, const size_t &) = 0;
  virtual void TrainWithoutEpochs(Input &) = 0;
  virtual vector_ PredictVector(vector_ data) = 0;
  virtual void set_count_hidden_layer(const size_t &) = 0;
  virtual ~Network() = default;
};
}  // namespace s21
#endif  // S21_CCP7_MLP_MODEL_NETWORK_H
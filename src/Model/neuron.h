#ifndef S21_CCP7_MLP_MODEL_NEURON_H
#define S21_CCP7_MLP_MODEL_NEURON_H
#define SIZE_END 26
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

namespace s21 {

class GraphNeuron {
  //  GraphNeuron() = delete;
 public:
  double get_rand_number() noexcept;
  double get_value() const noexcept;
  void set_error(const double&) noexcept;
  double get_error() const noexcept;
  void set_weights_delta(const double&) noexcept;
  double get_weights_delta() const noexcept;
  void set_value(const double&) noexcept;
  GraphNeuron(const double&);
  void set_weght_default(const size_t&);
  void PushBackPrev(GraphNeuron*);
  void PushBackNext(GraphNeuron*);
  std::vector<GraphNeuron*>& get_prev();
  std::vector<double>& get_weights() noexcept;

 private:
  double value = 0;
  double error = 0;
  double weights_delta = 0;
  std::vector<GraphNeuron*> prev;
  std::vector<GraphNeuron*> next;
  std::vector<double> weights;
  double get_function_value(const double& val) const noexcept;
  friend class GraphLayer;
  friend class GraphPreceptron;
};

class GraphLayer {
 public:
  //   GraphLayer() = delete;
  //  GraphLayer(const GraphLayer&) = delete;
  GraphLayer(const std::vector<double>&);
  GraphLayer(const size_t&);
  std::vector<GraphNeuron>& get_neurons() noexcept;

 private:
  std::vector<GraphNeuron> neurons;
  friend class GraphPreceptron;
};

class GraphPreceptron {
 public:
  GraphPreceptron() = delete;
  GraphPreceptron(const GraphPreceptron&) = delete;
  GraphPreceptron(const size_t&, const size_t&, const size_t& = 1,
                  const size_t& = 1);
  GraphNeuron* BeginOutputLayer() noexcept;
  void InitializingFirstLayer();
  void InitializingShadowLayer();
  void InitializingOutputLayer();
  void DirectPassage();
  void Predict(const std::vector<double>& vec);
  void train(const std::vector<double>&, const std::vector<double>&,
             const double& = 0.05);
  void TrainAll(const double& = 0.05);
  void InputEnterLayer(const std::vector<double>&);
  std::vector<double> get_output_vector() noexcept;
  void print() {
    // for (int i = 0; i !=  output_layer.neurons.size(); ++i)
    //     std::cout << output_layer.neurons[i].value << "\n";
    for (int i = 0; i != shadow_layers[0].neurons.size(); ++i)
      std::cout << shadow_layers[0].neurons[i].value << "\n";
  }
  void sh_paint() {
    for (int i = 0; i < shadow_layers.size(); i++) {
      for (int j = 0; j != shadow_layers[i].neurons.size(); ++j)
        std::cout << shadow_layers[i].neurons[j].value
                  << shadow_layers[i].neurons[j].weights.size() << "\n";
      std::cout << "========\n";
    }
    // std::cout << shadow_layers[0].neurons[0].value;
    // for (auto v : shadow_layers[0].get_neurons()[0])
    //   std::cout << v.value << " ";
    // auto s = enter_layer.get_neurons()[0].next[0];
    // s = s->prev[1];
    // std::cout << s->get_value();
    //  auto v = shadow_layers[0].get_neurons()[0].prev;
    //  for (int i = 0; i < v.size(); i++) {
    //   std::cout << v[i] << "\n";
    //  }
  }
  void paint() {
    for (auto i = 0; i < enter_layer.get_neurons().size(); ++i) {
      std::cout << enter_layer.get_neurons()[i].get_value() << "\n";
    }
    std::cout << "====== shadow=====\n";
    for (auto i = 0; i < shadow_layers.size(); i++) {
      for (auto j = 0; j < shadow_layers[i].get_neurons().size(); ++j) {
        std::cout << shadow_layers[i].get_neurons()[j].get_error() << "\n";
      }
    }
    std::cout << "====== output=====\n";
    for (auto i = 0; i < output_layer.get_neurons().size(); ++i) {
      std::cout << output_layer.get_neurons()[i].get_value() << "\n";
    }
    std::cout << "====== ves=====\n";
    for (auto i = 0; i < enter_layer.get_neurons()[0].weights.size(); i++) {
      std::cout << output_layer.get_neurons()[0].weights[i] << "\n";
    }
    std::cout << "=============\n";
    //    std::cout << output_layer.get_neurons()[0].get  << "\n";
  }

 private:
  size_t size;
  GraphLayer enter_layer;
  std::vector<GraphLayer> shadow_layers;
  GraphLayer output_layer;
  double get_function_value(const double&) const noexcept;
};

}  // namespace s21

#endif  // S21_CCP7_MLP_MODEL_NEURON_H
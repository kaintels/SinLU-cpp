#pragma once
#include "sinlu.h"

namespace model{

typedef struct ModelImpl : torch::nn::Module {
    ModelImpl(int kSize): 
        linear1(torch::nn::LinearOptions(kSize, 5)),
        sinlu1(1),
        linear2(torch::nn::LinearOptions(5, 2))
    {
    register_module("linear1", linear1);
    register_module("sinlu1", sinlu1);
    register_module("linear2", linear2);
    }

    torch::Tensor forward(torch::Tensor x) {
        x = linear1(x);
        x = sinlu1(x);
        x = linear2(x);
        return torch::sigmoid(x);
    }

    torch::nn::Linear linear1, linear2;
    sinlu::SinLU sinlu1;
    }ModelImpl;
    TORCH_MODULE(Model);
}
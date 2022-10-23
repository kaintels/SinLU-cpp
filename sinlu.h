#pragma once
#include <torch/torch.h>
#include <torch/nn.h>

namespace sinlu{
typedef struct SinLUImpl : torch::nn::Module {
    SinLUImpl(int64_t N=1)
    {
        a = register_parameter("a", torch::ones(N), true);
        b = register_parameter("b", torch::ones(N), true);
    }
    torch::Tensor forward(torch::Tensor x) {
        return torch::sigmoid(x)*(x+a*torch::sin(b*x));
        }
    torch::Tensor a, b;
    }SinLUImpl;
    TORCH_MODULE(SinLU);
}
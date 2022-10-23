#include "sinlu.h"
#include "model.h"

int main() {
    
    int i;
    torch::manual_seed(1234);
    model::Model model(10);
    
    torch::optim::Adam optimizer(
        model->parameters());

    torch::Tensor feature = torch::rand({1, 10});
    torch::Tensor target = torch::rand({1, 2});
    for (i = 0; i < 100; i++){
        model->zero_grad();
        torch::Tensor out = model->forward(feature);       
        torch::Tensor loss = torch::binary_cross_entropy(out, target);
        loss.backward();
        optimizer.step();
        std::printf("\r Epoch : %d, Loss : %f\n", i, loss.item<float>());
    }

    return 0;
}
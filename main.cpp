#include "./util.hpp"

using namespace cc;

float potential_delta(float x) {
    // 仮にN(3, 5)の正規分布のデルタとする
    return (2.0f * x - 6.0f) / 50.0f;
}

int main(int argc, char *argv[]) {
    try {
        std::vector<float> samples;
        const int          n_loop = 1000000;

        const float step = 0.1f;
        float       x    = 0.0f;
        for (int i = 0; i < n_loop; i++) {
            x = x - step * potential_delta(x) + gaussian_rand(0.0f, std::sqrt(2.0f * step));
            samples.push_back(x);
        }

        // バーンイン期間を破棄する
        const int n_burnin = samples.size() / 10;
        std::rotate(samples.begin(), samples.begin() + n_burnin, samples.end());
        samples.resize(samples.size() - n_burnin);

        // プロットする
        std::ofstream ofs("output");
        for (auto v : samples) {
            ofs << format_str("%f", v) << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << colorant('y', format_str("error: %s", e.what())) << std::endl;
    }
}

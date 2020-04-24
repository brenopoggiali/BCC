#include <bits/stdc++.h>

bool sortByFirstThenBySecond(const std::tuple<float,float, int> &a, const std::tuple<float,float, int> &b) {
    return (std::get<0>(a) == std::get<0>(b)) ?
        std::get<1>(a) > std::get<1>(b) : std::get<0>(a) > std::get<0>(b);
}

/* Create vector of cost_benefit O(M) */
void getCostBenefit(std::vector <std::tuple<float, float, int>> &cost_benefit, std::vector<std::pair<int, int>> islands, int N) {
    float i_cost_benefit, day_price, points, days;
    for (int i=0; i < islands.size(); ++i) { /* O(M) */
        day_price = islands[i].first; points = islands[i].second;
        i_cost_benefit = points/day_price;
        days = (N/day_price);
        cost_benefit.push_back(std::make_tuple(i_cost_benefit, days, i));
    }
}

std::pair<int, int> getMaxPointsAndDaysWithRepeat (std::vector <std::tuple<float, float, int>> cost_benefit, std::vector<std::pair<int, int>> islands, int N) {
    std::pair <int, int> island;
    std::tuple <float, float, int> tuple;
    int node, i, max_points, max_days;
    i = max_points = max_days = 0;

    for (i = 0; i < cost_benefit.size(); ++i) { /* O(M) */
        tuple = cost_benefit[i];
        node = std::get<2>(tuple);
        island = islands[node];
        if (island.first <= N) {
            max_days += (N/island.first);
            max_points += (N/island.first) * island.second;
            N -= (N/island.first) * island.first;
        }
    }
    return std::make_pair(max_points, max_days);
}

std::pair<int, int> greedyAlgorithm(std::vector <std::pair<int, int>> islands, int N) {
    std::vector <std::tuple<float, float, int>> cost_benefit;
    getCostBenefit(cost_benefit, islands, N); /* O(M) */
    std::sort(cost_benefit.begin(), cost_benefit.end(), sortByFirstThenBySecond); /* O(M log M) */
    return getMaxPointsAndDaysWithRepeat(cost_benefit, islands, N); /* O(M) */
}

std::pair<int,int> operator+(const std::pair<int, int>& x, const std::pair<int, int>& y) {
    return std::make_pair(x.first+y.first, x.second+y.second);
}

std::pair<int, int> getMaxPointsAndDaysWithoutRepeat (int N, int M, std::vector<int> costs, std::vector<int> points) {
    std::vector<std::vector<std::pair<int, int>>> points_days(M+1, std::vector<std::pair<int, int>>(N+1));
    for (int i=0; i < M+1; ++i) { /* O(M*N) */
        for (int j=0; j < N+1; ++j) {
            if (i == 0 || j == 0) {
                points_days[i][j] = std::make_pair(0, 0);
            }
            else if (costs[i-1] <= j) {
                std::pair <int, int> point_day = std::make_pair(points[i-1], 1);
                points_days[i][j] = max(point_day + points_days[i-1][j-costs[i-1]], points_days[i-1][j]);
            }
            else {
                points_days[i][j] = points_days[i-1][j];
            }
        }
    }
    return points_days[M][N];
}

std::pair<int, int> dynamicProgramming(std::vector <std::pair<int, int>> islands, int N, int M) {
    std::vector <int> costs, points;
    for (int i = 0; i < islands.size(); ++i) { /* O(M) */
        costs.push_back(islands[i].first);
        points.push_back(islands[i].second);
    }
    return getMaxPointsAndDaysWithoutRepeat(N, M, costs, points); /* O(M*N) */
}

void reduceIslandsCostsByGCD(std::vector<std::pair<int, int>>& islands, int *N) {
    int gcd = islands[0].first;
    for (int i = 0; i < islands.size(); ++i) { /* O(M) */
        gcd = std::__gcd(gcd, islands[i].first);
    }
    for (int i = 0; i < islands.size(); ++i) { /* O(M) */
        islands[i] = std::make_pair(islands[i].first/gcd, islands[i].second);
    }
    *N /= gcd;
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Ops.. o número de argumentos passados está incorreto =/" << std::endl;
        return 1;
    }

    std::ifstream entrada = std::ifstream(std::string(argv[1]));
    int N, M;
    entrada >> N >> M;

    int D, P;
    std::vector <std::pair<int, int>> islands;
    for (int i=0; i<M; ++i) { /* O(M) */
        entrada >> D >> P;
        islands.push_back(std::make_pair(D, P));
    }
    reduceIslandsCostsByGCD(islands, &N); /* O(M) */
    std::pair<int, int> ans1 = greedyAlgorithm(islands, N); /* O(M log M) */
    std::pair<int, int> ans2 = dynamicProgramming(islands, N, M); /* O(M*N) */

    std::cout << ans1.first << " " << ans1.second << std::endl;
    std::cout << ans2.first << " " << ans2.second << std::endl;

    return 0;
}

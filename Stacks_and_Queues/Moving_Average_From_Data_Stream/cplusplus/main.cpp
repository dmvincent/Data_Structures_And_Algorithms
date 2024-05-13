#include <iostream>
#include <queue>

class MovingAverage {
public:
    std::queue<int> q1;
    int wSize;
    int sum = 0;
    int count = 1;

    MovingAverage(int size) {
        wSize = size;         
    }
    
    double next(int val) {
        double average;
        if(q1.size() == wSize) {
            sum -= q1.front();
            q1.pop();
        }
        sum += val;
        q1.push(val);        
        if(count < wSize) {
            average = (double)sum/count;
            count++;
        } else {
            average = (double)sum/wSize;
        }
        return average;
    }
};

int main() {
    int size = 3;

    // Provide the input
    MovingAverage* obj = new MovingAverage(size);
    double ans1 = obj->next(1);
    double ans2 = obj->next(10);
    double ans3 = obj->next(3);
    double ans4 = obj->next(5);

    // Provide some STDOUT
    std::cout << ans1 << std::endl;
    std::cout << ans2 << std::endl;
    std::cout << ans3 << std::endl;
    std::cout << ans4 << std::endl;

    return 0;
}

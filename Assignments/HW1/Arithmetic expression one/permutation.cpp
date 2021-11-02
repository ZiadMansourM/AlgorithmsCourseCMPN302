#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define LOG(x) std::cout << x << std::endl

class Operation
{
    public:
    virtual int run(int leftOp, int rightOp) = 0;
};

class Addation : public Operation
{
    public:
    int run(int leftOp, int rightOp) override;
};

class Substraction : public Operation
{
    public:
    int run(int leftOp, int rightOp) override;
};

class Multiplication : public Operation
{
    public:
    int run(int leftOp, int rightOp) override;
};

void CheckValidty(std::vector<int>& vec, std::queue<Operation*> opQueue, bool& isPossible);

void RecCall(std::vector<int>& vec, std::queue<Operation*> opQueue, bool& isPossible, Operation* op);

int main()
{
    int a, b, c, d, e;
    bool isPossible = false;
    std::cin >> a >> b >> c >> d >> e;
    std::vector<int> vec{a, b, c, d, e};
    sort(vec.begin(), vec.end());
    do{
        std::queue<Operation*> opQueue;
        CheckValidty(vec, opQueue, isPossible);
    } while (std::next_permutation(vec.begin(), vec.end()));
    if (isPossible)
        LOG("Possible");
    else
        LOG("Impossible");
    return 0;
}

void RecCall(std::vector<int>& vec, std::queue<Operation*> opQueue, bool& isPossible, Operation* op)
{
    opQueue.push(op);
    CheckValidty(vec, opQueue, isPossible);
}

void CheckValidty(std::vector<int>& vec, std::queue<Operation*> opQueue, bool& isPossible)
{
    // shall we continue?
    if (isPossible)
        return;
    // check reached target
    if (opQueue.size() == 4)
    {
        // calculate result
        int i = 1, result=vec[0];
        do{
            Operation* op = opQueue.front();
            result = op->run(result, vec[i]);
            opQueue.pop();
            i++;
        } while (!opQueue.empty());
        // check
        if (result == 27)
            isPossible = true;
        return;
    }
    // addation
    RecCall(vec, opQueue, isPossible, new Addation());
    // substraction
    RecCall(vec, opQueue, isPossible, new Substraction());
    // multiplication
    RecCall(vec, opQueue, isPossible, new Multiplication());
}

int Addation :: run(int leftOp, int rightOp)
{
    return leftOp + rightOp;
}

int Substraction :: run(int leftOp, int rightOp)
{
    return leftOp - rightOp;
}

int Multiplication :: run(int leftOp, int rightOp)
{
    return leftOp * rightOp;
}
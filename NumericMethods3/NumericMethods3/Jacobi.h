#pragma once

#include <iostream>
#include <vector>

using namespace std;

void solve(const vector<float> a,
    const vector<float> b,
    vector<float>& x,
    const float allowed_error);

void Jacobi();
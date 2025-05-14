#include<bits/stdc++.h>
using namespace std;


// "string goes boom. tell me how big the boom is after the heat death of the universe" kind of question
class Solution {
public:
    using ll = long long;
    using Matrix = vector<vector<ll>>;
    const int MOD = 1e9 + 7;
    const int ALPHA = 26;

    // for multiplication of matrix
    Matrix mul(const Matrix &A, const Matrix &B) {
        Matrix C(ALPHA, vector<ll>(ALPHA, 0));
        for (int i = 0; i < ALPHA; ++i)
            for (int k = 0; k < ALPHA; ++k)
                if (A[i][k])
                    for (int j = 0; j < ALPHA; ++j)
                        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        return C;
    }

    // matrix A ^ exp using binary expon.
    Matrix matPow(Matrix A, int exp) {
        Matrix res(ALPHA, vector<ll>(ALPHA, 0));
        for (int i = 0; i < ALPHA; ++i) res[i][i] = 1; 
        while (exp) {
            if (exp & 1) res = mul(res, A);
            A = mul(A, A);
            exp >>= 1;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        // base transformation matrix
        Matrix base(ALPHA, vector<ll>(ALPHA, 0));

        
        for (int i = 0; i < ALPHA; ++i) {
            for (int step = 1; step <= nums[i]; ++step) {
                int to = (i + step) % ALPHA;
                base[i][to]++;
            }
        }
        Matrix powered = matPow(base, t);

        vector<ll> freq(ALPHA, 0);
        for (char ch : s) freq[ch - 'a']++;

        vector<ll> result(ALPHA, 0);
        for (int i = 0; i < ALPHA; ++i)
            for (int j = 0; j < ALPHA; ++j)
                result[j] = (result[j] + freq[i] * powered[i][j]) % MOD;

        ll total = 0;
        for (ll x : result) total = (total + x) % MOD;
        return total;
    }
};
// Time complexity - O(S + log t)
// Space complexity - constant
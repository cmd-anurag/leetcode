#include <string>
#include <vector>
#include <algorithm>
using std::string, std::vector, std::sort;

struct ValidCoupon
{
    string code;
    string businessLine;
    bool isActive;
    ValidCoupon(string c, string bl, bool ia)
    {
        this->code = c;
        this->businessLine = bl;
        this->isActive = ia;
    }
};

bool compare(const ValidCoupon &a, const ValidCoupon &b)
{
    if (a.businessLine != b.businessLine)
    {
        return a.businessLine < b.businessLine;
    }
    else
    {
        return a.code < b.code;
    }
}

class Solution
{
public:
    vector<string> validateCoupons(vector<string> &code,
                                   vector<string> &businessLine,
                                   vector<bool> &isActive)
    {

        int n = code.size();
        vector<ValidCoupon> temp;

        for (int i = 0; i < n; ++i)
        {
            string c = code[i];
            string bl = businessLine[i];
            bool ia = isActive[i];
            if (c.empty())
                continue;

            if (isAlnum(c) && validBL(bl) && ia)
            {

                ValidCoupon vc(c, bl, ia);
                temp.push_back(vc);
            }
        }

        sort(temp.begin(), temp.end(), compare);

        vector<string> result;
        for (auto entry : temp)
        {
            result.push_back(entry.code);
        }
        return result;
    }

private:
    bool isAlnum(string &code)
    {
        for (char c : code)
        {
            if (c == '_')
                continue;

            int ascii = c;

            bool isDigit = ascii >= 48 && ascii <= 57;
            bool isLower = ascii >= 97 && ascii <= 122;
            bool isUpper = ascii >= 65 && ascii <= 90;

            if (!isDigit && !isLower && !isUpper)
                return false;
        }
        return true;
    }
    bool validBL(string &bl)
    {
        if (bl == "electronics" || bl == "grocery" || bl == "pharmacy" ||
            bl == "restaurant")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
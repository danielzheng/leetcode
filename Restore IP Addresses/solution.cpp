class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        restorIpAddress(vector<string>(), s, 0);
        for (const auto &v : ips)
        {
            result.push_back(v[0] + "." + v[1] + "." + v[2] + "." + v[3]);
        }
        return result;
    }
private:
    void restorIpAddress(vector<string> ip, const string& str, size_t index)
    {
        if (str.length() <= index)
        {
            return;
        }
        if (ip.size() == 3)
        {
            string seg = str.substr(index);
            if (isValidSegment(seg))
            {
                ip.push_back(seg);
                ips.push_back(ip);
            }
        }
        else
        {
            for (size_t i = 1; i <= 3; i++)
            {
                if (str.length() - index >= i)
                {
                    string seg = str.substr(index, i);
                    if (isValidSegment(seg))
                    {
                        ip.push_back(seg);
                        restorIpAddress(ip, str, index + i);
                        ip.pop_back();
                    }
                }
            }
        }
    }

    bool isValidSegment(const string& value)
    {
        if (value.size() > 1 && value[0] == '0')
        {
            return false;
        }
        int v = atoi(value.c_str());
        if (value.size() <= 3 && v >=0 && v <= 255)
        {
            return true;
        }
        return false;
    }
    vector<vector<string>> ips;
};

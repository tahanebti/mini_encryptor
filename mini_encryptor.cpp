/*
*       mini encryptor 
*       Author : Taha Nebti
*       github : github.com/tahanebti
*/

#include <iostream>

namespace _tn
{
    
class Encryptor {
    bool m_isIncremental;
    int m_count;
public:
    Encryptor() {
        m_isIncremental = 0;
        m_count = 1;
    }
    Encryptor(bool isInc, int count) {
        m_isIncremental = isInc;
        m_count = count;
    }
    std::string operator()(std::string data) {
        for (int i = 0; i < data.size(); i++)
            if ((data[i] >= 'a' && data[i] <= 'z')
                    || (data[i] >= 'A' && data[i] <= 'Z'))
                if (m_isIncremental)
                    data[i] = data[i] + m_count;
                else
                    data[i] = data[i] - m_count;
        return data;
    }

};

}

std::string buildCompleteMessage(std::string rawData,
        _tn::Encryptor encyptorFuncObj) {
    // Add some header and footer to data to make it complete message
    rawData = "[HEADER]" + rawData + "[FooTER]";

    // Call the callBack provided i.e. function pointer to encrypt the
    rawData = encyptorFuncObj(rawData);

    return rawData;
}



int main() {
    std::string msg = buildCompleteMessage("SampleString", _tn::Encryptor(true, 1));
    std::cout << msg << std::endl;

    msg = buildCompleteMessage("SampleString", _tn::Encryptor(true, 2));
    std::cout << msg << std::endl;

    msg = buildCompleteMessage("SampleString", _tn::Encryptor(false, 1));
    std::cout << msg << std::endl;

    return 0;
}

#pragma once


#include <cmath>
#include <type_traits>

template <class OrderType, class ArgType>
ArgType bessel_j_asympz(OrderType v, const ArgType z) {
    using RealType = double;
    
    constexpr RealType PI = 4 * std::atan(1.0);
    RealType mu = 4.0 * v * v;
    RealType pnumerator = 1.0;
    ArgType p = 1.0;
    RealType qnumerator = mu - 1.0;
    OrderType denominator = 8.0;
    ArgType q = qnumerator / (denominator * z);
    int nterms = 14;
    RealType zraised = z;
    
    
    for (auto i = 1.0; i <= nterms; i++) {
        zraised *= z;
        pnumerator = - qnumerator * (mu - (4 * i - 1.0) * (4 * i - 1.0));
        denominator *= 2 * i * 8.0;
        p += pnumerator / (denominator * zraised);
        
        zraised *= z;
        qnumerator = pnumerator * (mu - (4 * i + 1.0) * (4 * i + 1.0));
        denominator *= (2 * i + 1) * 8.0;
        q += qnumerator / (denominator * zraised);
    }
    
    const RealType chi = z -  PI * (0.5 * v + 0.25);
    
    return std::sqrt(2 / (PI * z)) * (p * std::cos(chi) - q * std::sin(chi));
}
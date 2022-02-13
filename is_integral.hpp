#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP


// Checks whether T is an integral type. Provides the member constant value which is equal to true, 
// if T is the type 
// bool, char, char8_t, char16_t, char32_t, wchar_t, short, int, long, long long, or 
// any implementation-defined extended integer types, including any signed, unsigned, and cv-qualified variants. 
// Otherwise, value is equal to false
//example piece of code to test
// https://docs.w3cub.com/cpp/types/is_integral
namespace ft
{
    template <class T> struct is_integral {static const bool value = false;};
    template <> struct is_integral<bool> {static const bool value = true;};
    template <> struct is_integral<char> {static const bool value = true;};
    template <> struct is_integral<char16_t> {static const bool value = true;};
    template <> struct is_integral<char32_t> {static const bool value = true;};
    template <> struct is_integral<wchar_t> {static const bool value = true;};
    template <> struct is_integral<signed char> {static const bool value = true;};
    template <> struct is_integral<short int> {static const bool value = true;};
    template <> struct is_integral<int> {static const bool value = true;};
    template <> struct is_integral<long int> {static const bool value = true;};
    template <> struct is_integral<long long int> {static const bool value = true;};
    template <> struct is_integral<unsigned char> {static const bool value = true;};
    template <> struct is_integral<unsigned short int> {static const bool value = true;};
    template <> struct is_integral<unsigned int> {static const bool value = true;};
    template <> struct is_integral<unsigned long int> {static const bool value = true;};
    template <> struct is_integral<unsigned long long int> {static const bool value = true;};
}


#endif
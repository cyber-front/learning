#include "array.hpp"

#include <sstream>

/// @brief This is a helper function used to allocate and initialize a C-style array
/// on the heap.  All elements in the list are set to the value specified and the
/// resulting initialized array is returned to the calling routine.
/// @param len Length of the array to create
/// @param value Value to set each element of the array
/// @return Pointer to the created array
double *init(std::size_t len, double value)
{
    double *ret_val = new double[len];
    std::fill_n(ret_val, len, value);
    return ret_val;
}

/// @brief This is a helper function used to allocate and initialize a C-style array
/// on the heap based on the given length and given C-style array.
/// Caution: This is only safe if the length of the allocated values input has at
/// least len elements.
/// @param len Length of the array to create
/// @param values Array of values to use to initialize the array
/// @return Pointer to the created array
double *init(std::size_t len, const double *values)
{
    double *ret_val = new double[len];
    std::copy(values, values + len, ret_val);
    return ret_val;
}

/// @brief This is a helper function used to allocate and initialize a C-style array
/// on the heap based on the given initializer list.  The length and values are
/// both specified in the initializer list.
/// @param values Initializer list used to generate an array
/// @return Pointer to the created array
double *init(std::initializer_list<double> values)
{
    double *ret_val = new double[values.size()];
    std::copy(values.begin(), values.end(), ret_val);
    return ret_val;
}

/// @brief Constructor used to create an array with the given value in each element
/// @param len Number of elements to allocate in the array
/// @param value Value to set each element of the array
array::array(std::size_t len, double value) : _len(len), _arr(init(len, value)) {}

/// @brief Constructor used to create an array with the values specified in the
/// initializer list provided.
/// @param values List of values to set each corresponding element fo the array
array::array(std::initializer_list<double> values) : _len(values.size()), _arr(init(values)) {}

/// @brief Copy constructor used to initialize all elements of the array to the value
/// specified in the src.  This is a deep copy meaning the array is copied, and not merely
/// referenced.
/// @param src Source array to copy
array::array(const array &src) : _len(src.size()), _arr(init(src.size(), src._arr)) {}

/// @brief Class destructor which deallocates the array when the destructor is called
array::~array() { delete[] this->_arr; }

/// @brief Generates and returns a string representation of the array
/// @return String representation of the array
std::string array::to_string() const
{
    char delim = '[';
    std::stringstream ss;
    const double *ptr = this->_arr;

    for (std::size_t i = 0; i < this->size(); ++i, ++ptr)
    {
        ss << delim << *ptr;
        delim = ',';
    }
    ss << ']';

    return ss.str();
}

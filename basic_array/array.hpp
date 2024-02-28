
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <cassert>
#include <string>
#include <initializer_list>

/// @brief The array class contains a simple container used to provide insight
/// into several aspects of the C++ language.  This class should not be used
/// for other purposes.  There are other standard C++ classes which are generally
/// better suited for whatever problem you're trying to solve with this in
/// real world systems.
class array
{
private:
    /// @brief Pointer to the array values
    double *_arr;

    /// @brief Number of elements the array contains
    std::size_t _len;

public:
    /// @brief Constructor used to create an array with the given value in each element
    /// @param len Number of elements to allocate in the array
    /// @param value Value to set each element of the array
    array(std::size_t len, double value = 0.0);

    /// @brief Constructor used to create an array with the values specified in the
    /// initializer list provided.
    /// @param values List of values to set each corresponding element fo the array
    array(std::initializer_list<double> values);

    /// @brief Copy constructor used to initialize all elements of the array to the value
    /// specified in the src.  This is a deep copy meaning the array is copied, and not merely
    /// referenced.
    /// @param src Source array to copy
    array(const array &src);

    /// @brief Class destructor which deallocates the array when the destructor is called
    virtual ~array();

    /// @brief Retrieve the length of the array
    /// @return Length of the array
    inline std::size_t size() const { return this->_len; }

    /// @brief Retrieve a reference to an array element.  This allows the element to be
    /// used as either an lvalue or rvalue.
    /// @param index Index of array element to reference
    /// @return Reference to the selected element.
    inline double &operator[](std::size_t index)
    {
        assert(index < this->_len);
        return this->_arr[index];
    }

    /// @brief Retrieve the value of an array element.  This restricts the element to
    /// be used only as an rvalue
    /// @param index Index of element to retrieve
    /// @return Value of the selected element
    inline double get(std::size_t index) const
    {
        assert(index < this->_len);
        return this->_arr[index];
    }

    /// @brief Generates and returns a string representation of the array
    /// @return String representation of the array
    std::string to_string() const;
};

#endif
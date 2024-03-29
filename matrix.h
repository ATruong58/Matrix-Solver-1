/*!Name: Alan Truong                                 
 *Date: 3/10/2019                                   
 *Course: Object Orient Numerical Method            
 *Purpose: Learn how to use OOP to make a matrix class
           and to implement the Guassian method       
 */     

#ifndef MATRIX_H
#define MATRIX_H

#include "vector.h"


/*! mymatrix class
 *
 * mymatrix class with overloaded operator
 *
 */
template <class T>
class mymatrix
{
    private:
        myvector<myvector<T>> m_matrix;
        int m_column_size;
        int m_row_size;
    
    public:
        /*! Constructs an 3X3 matrix fill with zero.
         *
         * \pre T = 0 must be implemented
         * 
         * \post m_vector of myvector<T> with column and row size of 3 is created
         */
        mymatrix();

        /*! Destructor
         *
         * \post Deallocate the class
         */
        ~mymatrix(){}

        /*! Paramatized Constructor
         *
         * \pre T = 0 must be implemented
         * 
         * \post Creates a new matrix with passed in column and row sizes
         *       with value all equal to 0
         */
        mymatrix(const int column_size, const int row_size);

        /*! Copy Constructor
         *
         * \pre T = T must be implemented
         * 
         * \post Creates a new matrix with copies of elements from source
         *       and underlying storage size equal to that of source's storage.
         */
        mymatrix(const mymatrix &source);
        
        /*! Operator =
         *
         * \pre T = T must be define
         * 
         * \post Set lhs matrix with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        mymatrix<T>& operator=(const mymatrix<T> &source);

        /*! Operator = (move constructor)
         *
         * \pre T = T must be define
         *      move must be define
         * 
         * \post Set lhs matrix with copies of elements from rhs
         *       and underlying storage size equal to that of rhs's storage.
         */
        mymatrix<T>& operator=(mymatrix<T> &&source);
        

        /*! Binary + 
         *
         * \param source mymatrix class to subtract lhs mymatrix class value to
         * \return A mymatrix class with the sum of the two 
         *
         * \pre Rhs mymatrix class and lhs mymatrix class must have the same 
         *      row and column size and value assign to all index in the array 
         *      T + T must be defined
         *      T = T must be implemented
         *      Parametized constructor (int,int) must be implemented
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        mymatrix<T> operator+(const mymatrix<T> &source)const;

        /*! Binary - 
         *
         * \param source mymatrix class to subtract lhs mymatrix class value to
         * \return A mymatrix class with the difference of the two 
         *
         * \pre Rhs mymatrix class and lhs mymatrix class must have the same 
         *      row and column size and value assign to all index in the array 
         *      T - T must be defined
         *      T = T must be implemented
         *      Parametized constructor (int,int) must be implemented
         * 
         * \throws std::invalid_argument is thrown if size is not the same
         * 
         */
        mymatrix<T> operator-(const mymatrix<T> &source)const;

        /*! Binary * between two matrix
         *
         * \param source mymatrix class to subtract lhs mymatrix class value to
         * \return A mymatrix class with the product of the two with the size of the rhs column
         *         and lhs row
         *
         * \pre Rhs mymatrix class column size and lhs mymatrix class row size must be the same 
         *      and value assign to all index in the array 
         *      Parametized constructor (int,int) must be implemented
         *      T = T must be implemented
         *      Transpose must be define
         *      Must have vector dot product function define
         * 
         * \throws std::invalid_argument is thrown if rhs column size and lhs row size are not the same
         * 
         */
        mymatrix<T> operator*(const mymatrix<T> &source)const;

        /*! Binary * between a matrix and a vector
         *
         * \param rhs mymatrix class to subtract lhs mymatrix class value to
         * \return A myvector class with the product of the two with the size of the lhs column size 
         *
         * \pre Rhs mymatrix class column size and lhs mymatrix class row size must be the same 
         *      and value assign to all index in the array 
         *      T = T must be implemented
         *      Must have vector dot product function define
         *      Parametized constructor (int,int) must be implemented
         * 
         * \throws std::invalid_argument is thrown if rhs size and lhs row size are not the same
         * 
         */
        myvector<T> operator*(const myvector<T> &rhs)const;

        /*! Scalar multiplication
         *
         * \param scale a number to muliply all element of the matrix by
         * \return A myvector class with the all element in the matrix class multiply by the scale
         *
         * \pre Value assign to all index in the array 
         *      T = T must be implemented
         *      T * T must be implemented
         *      Parametized constructor (int,int) must be implemented
         * 
         * \throws std::invalid_argument is thrown if rhs size and lhs row size are not the same
         * 
         */
        mymatrix<T> operator*(const int scale)const;

        /*! Return a myvector class of T of the element 
         *
         * \param index the index of the vector to return in the matrix class.
         * \return The vector at position idx is returned with reference so it is changable
         *
         * \pre idx is within the range [0, length()).
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        myvector<T>& operator[](int index);
        
        /*! Return a myvector class of T of the element
         *
         * \param index the index of the vector to return in the matrix class.
         * \return The element at position idx is returned.
         * 
         * \pre idx is within the range [0, length()).
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        myvector<T> operator[](int index)const;
        
        /*! Transpose the calling matrix
         *
         * \return A matrix class with its value equal to the calling matrix transpose
         * 
         * \pre T = T must be implmented
         *      Parametized constructor (int,int) must be implemented
         * 
         * \throws std::invalid_argument is thrown if idx is out of range.
         */
        mymatrix<T> transpose()const;

        /*! Getter for m_column_size
         *
         * \return m_column_size
         */
        int getColumnSize()const;

        /*! Getter for m_row_size
         *
         * \return m_row_size
         */
        int getRowSize()const;

};

/*! Stream insertion operator for mymatrix class.
         *
         * \pre Stream insertion operator is defined.
         *      myvector class insert must be defined
         * 
         * \post The contents of the matrix are printed to the ouptut stream.
         * 
         * \return the modified output stream.
         *
         */
template <typename U>
std::ostream& operator<<(std::ostream& os, const mymatrix<U> &obj);


/*! Stream output operator for myvector class.
         *
         * \pre Stream output operator is defined.
         *      myvector output must be defined
         * 
         * \post The contents of the vector are read into the given variable
         * 
         * \return the modified input stream.
         *
         */
template <typename U>
std::istream& operator>>(std::istream& in, mymatrix<U> &obj);

#include "matrix.hpp"


#endif 
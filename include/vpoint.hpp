#ifndef VPOINT_HPP
#define VPOINT_HPP

#include <cmath>
#include <random>

/**
 * @brief Vector implemented as Point
 * 
 */
class VPoint {
    public:
    float x;
    float y;
    
    // /**
    //  * @brief Construct a VPoint with zeroes
    //  * 
    //  */
    // VPoint();
    
    // /**
    //  * @brief Construct a new VPoint object
    //  * 
    //  * @param x 
    //  * @param y 
    //  */
    // VPoint(const float& x, const float& y);
    
    // /**
    //  * @brief Construct a new VPoint object
    //  * 
    //  * @param other
    //  */
    // VPoint(const VPoint& other);
    
    // /**
    //  * @brief Copy and return
    //  * 
    //  * @return copy of this 
    //  */
    // VPoint clone() const;
    
    // //----------------------
    // // VPoint Operations
    // //----------------------
    
    // /**
    //  * @brief Sum of x and y
    //  * 
    //  * @param other 
    //  * @return sum
    //  */
    // float sum() const;
    
    // /**
    //  * @brief Magnitude of the distance from the origin
    //  * 
    //  * @return sqrt(x*x + y*y)
    //  */
    // float mag() const;
    
    // /**
    //  * @brief Angle from origin
    //  * 
    //  * @return atan2(y, x)
    //  */
    // float angle() const;
    
    // /**
    //  * @brief Distance between 2 VPoints
    //  * 
    //  * @param other 
    //  * @return euclidian distance
    //  */
    // float dist(const VPoint& other) const;
    
    // /**
    //  * @brief Normalized version of VPoint
    //  * 
    //  * @return this / magnitutide
    //  */
    // VPoint norm() const;
    
    // /**
    //  * @brief Unit vector from angle
    //  * 
    //  * @return VPoint(cos(angle), sin(angle))
    //  */
    // static VPoint fromAngle(const float& angle);
    
    // static VPoint random();
    
    //-----------------------
    // Operator Overloading
    //-----------------------
    
    /**
     * @brief Add other float
     * 
     * @param other 
     * @return sum 
     */
    VPoint add(const float& f) const {
        return VPoint(x+f, y+f);
    }
    
    /**
     * @brief Add other VPoint
     * 
     * @param other 
     * @return sum 
     */
    VPoint add(const VPoint& other) const {
        return VPoint(x+other.x, y+other.y);
    }
    
    /**
     * @brief Subtract float
     * 
     * @param other 
     * @return difference 
     */
    VPoint subtract(const float& f) const {
        return VPoint(x-f, y-f);
    }
    
    /**
     * @brief Subtract other VPoint
     * 
     * @param other 
     * @return difference 
     */
    VPoint subtract(const VPoint& other) const {
        return VPoint(x-other.x, y-other.y);
    }
    
    /**
     * @brief Multiply float
     * 
     * @param other 
     * @return product 
     */
    VPoint multiply(const float& f) const {
        return VPoint(x*f, y*f);
    }
    
    /**
     * @brief Multiply other VPoint
     * 
     * @param other 
     * @return product 
     */
    VPoint multiply(const VPoint& other) const {
        return VPoint(x*other.x, y*other.y);
    }
    
    /**
     * @brief Divide float
     * 
     * @param other 
     * @return quotient 
     */
    VPoint divide(const float& f) const {
        return VPoint(x/f, y/f);
    }
    
    /**
     * @brief Divide other VPoint
     * 
     * @param other 
     * @return quotient 
     */
    VPoint divide(const VPoint& other) const {
        return VPoint(this->x/other.x, this->y/other.y);
    }
    
    /**
     * @brief Negative
     * 
     * @return VPoint(-x, -y)
     */
    VPoint operator-() const {
        return VPoint(-this->x, -this->y);
    }
    
    VPoint& operator+=(const float& f) {
        x += f;
        y += f;
        return *this;
    }
    
    VPoint& operator+=(const VPoint& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    
    VPoint& operator-=(const float& f) {
        x -= f;
        y -= f;
        return *this;
    }
    
    VPoint& operator-=(const VPoint& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    
    VPoint& operator*=(const float& f) {
        x *= f;
        y *= f;
        return *this;
    }
    
    VPoint& operator*=(const VPoint& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }
    
    VPoint& operator/=(const float& f) {
        x /= f;
        y /= f;
        return *this;
    }
    
    VPoint& operator/=(const VPoint& other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }
    
    friend VPoint operator+(const VPoint& p, const float& f) {
        return p.add(f);
    }

    friend VPoint operator+(const float& f, const VPoint& p) {
        return p.add(f);
    }

    friend VPoint operator+(const VPoint& p1, const VPoint& p2) {
        return p1.add(p2);
    }

    friend VPoint operator-(const VPoint& p, const float& f) {
        return p.subtract(f);
    }

    friend VPoint operator-(const float& f, const VPoint& p) {
        return p.subtract(f);
    }

    friend VPoint operator-(const VPoint& p1, const VPoint& p2) {
        return p1.subtract(p2);
    }

    friend VPoint operator*(const VPoint& p, const float& f) {
        return p.multiply(f);
    }

    friend VPoint operator*(const float& f, const VPoint& p) {
        return p.multiply(f);
    }

    friend VPoint operator*(const VPoint& p1, const VPoint& p2) {
        return p1.multiply(p2);
    }

    friend VPoint operator/(const VPoint& p, const float& f) {
        return p.divide(f);
    }

    friend VPoint operator/(const float& f, const VPoint& p) {
        return p.divide(f);
    }

    friend VPoint operator/(const VPoint& p1, const VPoint& p2) {
        return p1.divide(p2);
    }
    
    //----------------
    // Constructors
    //----------------

    VPoint() : x(0.0f), y(0.0f) {}
    VPoint(const float& x, const float& y) : x(x), y(y) {}
    VPoint(const VPoint& other) : x(other.x), y(other.y) {}
    VPoint clone() const { return VPoint(*this); }

    //--------------------
    // VPoint operations
    //--------------------

    float sum() const {
        return x + y;
    }

    float mag() const {
        return sqrtf(x*x + y*y);
    }

    float angle() const {
        return atan2f(y, x);
    }

    float dist(const VPoint& other) const {
        VPoint diff = subtract(other);
        return (diff*diff).mag();
    }

    VPoint norm() const {
        return divide(mag());
    }

    static VPoint fromAngle(const float& angle) {
        return VPoint(cosf(angle), sinf(angle));
    }

    static VPoint random(){
        const float PI_F = M_PI;
        float randAngle = ((float(rand()))/float(RAND_MAX)) * 2.0f * PI_F - PI_F;
        return fromAngle(randAngle);
    }
};

#endif
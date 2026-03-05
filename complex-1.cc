#include <iostream>
#include <cmath>

// ----- Complex class definition and implementation -----
class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Complex-Complex operations
    Complex operator+(const Complex& o) const {
        return Complex(real + o.real, imag + o.imag);
    }

    Complex operator-(const Complex& o) const {
        return Complex(real - o.real, imag - o.imag);
    }

    Complex operator*(const Complex& o) const {
        return Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real);
    }

    Complex operator/(const Complex& o) const {
        double denom = o.real * o.real + o.imag * o.imag;
        return Complex((real * o.real + imag * o.imag) / denom,
                       (imag * o.real - real * o.imag) / denom);
    }

    // Complex-double operations
    Complex operator+(double d) const {
        return Complex(real + d, imag);
    }

    Complex operator-(double d) const {
        return Complex(real - d, imag);
    }

    Complex operator*(double d) const {
        return Complex(real * d, imag * d);
    }

    Complex operator/(double d) const {
        return Complex(real / d, imag / d);
    }

    // Assignment operator from double
    Complex& operator=(double d) {
        real = d;
        imag = 0.0;
        return *this;
    }

    // Stream insertion
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << "(" << c.real << (c.imag >= 0 ? " + " : " - ") << std::abs(c.imag) << "i)";
        return os;
    }

    // Friend double-Complex operations
    friend Complex operator+(double d, const Complex& c) {
        return c + d;
    }

    friend Complex operator-(double d, const Complex& c) {
        return Complex(d - c.real, -c.imag);
    }

    friend Complex operator*(double d, const Complex& c) {
        return c * d;
    }

    friend Complex operator/(double d, const Complex& c) {
        double denom = c.real * c.real + c.imag * c.imag;
        return Complex((d * c.real) / denom, (-d * c.imag) / denom);
    }

private:
    double real, imag;
};

// ----- Main function for testing -----
int main() {
    Complex a(1, 2);
    Complex b(2, -1);
    double d = 5;

    std::cout << a << " + " << b << " = " << a + b << "\n";
    std::cout << a << " - " << b << " = " << a - b << "\n";
    std::cout << a << " * " << b << " = " << a * b << "\n";
    std::cout << a << " / " << b << " = " << a / b << "\n";

    std::cout << a << " + " << d << " = " << a + d << "\n";
    std::cout << d << " + " << a << " = " << d + a << "\n";
    std::cout << a << " - " << d << " = " << a - d << "\n";
    std::cout << d << " - " << a << " = " << d - a << "\n";
    std::cout << a << " * " << d << " = " << a * d << "\n";
    std::cout << d << " * " << a << " = " << d * a << "\n";
    std::cout << a << " / " << d << " = " << a / d << "\n";
    std::cout << d << " / " << a << " = " << d / a << "\n";

    return 0;
}

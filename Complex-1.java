class Complex {

    private double real;
    private double imag;

    public Complex() {
        this(0.0, 0.0);
    }

    public Complex(double real) {
        this(real, 0.0);
    }

    public Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    public Complex add(Complex o) {
        return new Complex(this.real + o.real, this.imag + o.imag);
    }

    public Complex add(double d) {
        return new Complex(this.real + d, this.imag);
    }

    public Complex sub(Complex o) {
        return new Complex(this.real - o.real, this.imag - o.imag);
    }

    public Complex sub(double d) {
        return new Complex(this.real - d, this.imag);
    }

    public Complex mul(Complex o) {
        double r = this.real * o.real - this.imag * o.imag;
        double i = this.real * o.imag + this.imag * o.real;
        return new Complex(r, i);
    }

    public Complex mul(double d) {
        return new Complex(this.real * d, this.imag * d);
    }

    public Complex div(Complex o) {
        double denom = o.real * o.real + o.imag * o.imag;
        double r = (this.real * o.real + this.imag * o.imag) / denom;
        double i = (this.imag * o.real - this.real * o.imag) / denom;
        return new Complex(r, i);
    }

    public Complex div(double d) {
        return new Complex(this.real / d, this.imag / d);
    }

    public static Complex add(double d, Complex c) {
        return new Complex(d + c.real, c.imag);
    }

    public static Complex sub(double d, Complex c) {
        return new Complex(d - c.real, -c.imag);
    }

    public static Complex mul(double d, Complex c) {
        return new Complex(d * c.real, d * c.imag);
    }

    public static Complex div(double d, Complex c) {
        double denom = c.real * c.real + c.imag * c.imag;
        double r = (d * c.real) / denom;
        double i = (-d * c.imag) / denom;
        return new Complex(r, i);
    }

    @Override
    public String toString() {
        return "(" + real + (imag >= 0 ? " + " : " - ") + Math.abs(imag) + "i)";
    }
}


public class Main {
    public static void main(String[] args) {
        Complex a = new Complex(1, 2);
        Complex b = new Complex(2, -1);
        double d = 5.0;

        System.out.println(a + " + " + b + " = " + a.add(b));
        System.out.println(a + " - " + b + " = " + a.sub(b));
        System.out.println(a + " * " + b + " = " + a.mul(b));
        System.out.println(a + " / " + b + " = " + a.div(b));

        System.out.println(a + " + " + d + " = " + a.add(d));
        System.out.println(d + " + " + a + " = " + Complex.add(d, a));
        System.out.println(a + " - " + d + " = " + a.sub(d));
        System.out.println(d + " - " + a + " = " + Complex.sub(d, a));
        System.out.println(a + " * " + d + " = " + a.mul(d));
        System.out.println(d + " * " + a + " = " + Complex.mul(d, a));
        System.out.println(a + " / " + d + " = " + a.div(d));
        System.out.println(d + " / " + a + " = " + Complex.div(d, a));
    }
}

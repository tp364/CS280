class Complex:
  def __init__(self, real=0.0, imag=0.0):
      self.real = real
      self.imag = imag

  def __add__(self, other):
      if isinstance(other, Complex):
          return Complex(self.real + other.real, self.imag + other.imag)
      return Complex(self.real + other, self.imag)

  def __radd__(self, other):
      return self + other

  def __sub__(self, other):
      if isinstance(other, Complex):
          return Complex(self.real - other.real, self.imag - other.imag)
      return Complex(self.real - other, self.imag)

  def __rsub__(self, other):
      return Complex(other - self.real, -self.imag)

  def __mul__(self, other):
      if isinstance(other, Complex):
          return Complex(self.real * other.real - self.imag * other.imag,
                         self.real * other.imag + self.imag * other.real)
      return Complex(self.real * other, self.imag * other)

  def __rmul__(self, other):
      return self * other

  def __truediv__(self, other):
      if isinstance(other, Complex):
          denom = other.real**2 + other.imag**2
          return Complex((self.real * other.real + self.imag * other.imag) / denom,
                         (self.imag * other.real - self.real * other.imag) / denom)
      return Complex(self.real / other, self.imag / other)

  def __rtruediv__(self, other):
      denom = self.real**2 + self.imag**2
      return Complex((other * self.real) / denom, (-other * self.imag) / denom)

  def __str__(self):
      return f"({self.real} {'+' if self.imag >= 0 else '-'} {abs(self.imag)}i)"


if __name__ == "__main__":
  a = Complex(1, 2)
  b = Complex(2, -1)
  i = 5

  print(f"{a} + {b} = {a + b}")
  print(f"{a} - {b} = {a - b}")
  print(f"{a} * {b} = {a * b}")
  print(f"{a} / {b} = {a / b}")

  print(f"{a} + {i} = {a + i}")
  print(f"{i} + {a} = {i + a}")
  print(f"{a} - {i} = {a - i}")
  print(f"{i} - {a} = {i - a}")
  print(f"{a} * {i} = {a * i}")
  print(f"{i} * {a} = {i * a}")
  print(f"{a} / {i} = {a / i}")
  print(f"{i} / {a} = {i / a}")

clear;
m = 4;
n = 2^m-1;
x =randint(n,1,m); % Random vector
y = fft(x); % Transform of x
z = ifft(y); % Inverse transform of y
ck = isequal(z,x) ;% Check that ifft(fft(x)) recovers x.
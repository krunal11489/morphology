close all;
I = imread('football.jpg');
J = rgb2gray(I);
figure,imshow(J);
[m,n]=size(J);
a=1;
gamma=.4;
for i=1:m;
    for j=1:n;
        c(i,j)=0;
        x=J(i,j);
        x=double(x);
        c(i,j)=a*x^gamma;
    end
end
p=max(max(c));
level=2^nextpow2(p);
c1=c./(level-1);
K=uint8(255*c1);
figure,imshow(K);
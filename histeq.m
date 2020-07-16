close all;
J = imread('fig1.tif');
%J = rgb2gray(K);
figure,imshow(J);
[m,n]=size(J);
l=256;
k=0:255;
for p=1:256
    c(p)= 0;
    d(p)= 0;
    s(p)= 0;
end
for i=1:m;
    for j=1:n;
        x=J(i,j);
        c(x+1)=c(x+1)+1;
    end
end
figure,stem(k,c);
title('histogarm');
xlabel('intensity'),ylabel('number of pixels');
a=(l-1)/(m*n);
s(1)=a*c(1);
t(1)=c(1);
for i=1:(l-1);
    %for j=1:i;
    t(i+1)=t(i)+c(i+1);
    %end
    s(i+1)=a*t(i+1);
end
si=uint8(s);
for i=1:m;
    for j=1:n;
        x=J(i,j);
        I(i,j)=si(x);
        x=I(i,j);
        d(x+1)=d(x+1)+1;
    end
end
figure,imshow(I);
figure,stem(k,d);
title('equlized histogarm');
xlabel('intensity'),ylabel('number of pixels');
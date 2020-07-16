close all;
J = imread('fig1.tif');
%J = rgb2gray(K);
figure,imshow(J);
title('original image');
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
title('original histogarm');
xlabel('intensity'),ylabel('number of pixels');
a=(l-1)/(m*n);
s(1)=a*c(1);
t(1)=c(1);
for i=1:(l-1);
    t(i+1)=t(i)+c(i+1);
    s(i+1)=a*t(i+1);
end
si=uint8(s);
figure,plot(si);
title('Transformation Function');
xlabel('old intensity'),ylabel('new intensity');
for i=1:m;
    for j=1:n;
        x=J(i,j);
        I(i,j)=si(x);
        x=I(i,j);
        d(x+1)=d(x+1)+1;
    end
end
figure,imshow(I);
title('equlized image');
figure,stem(k,d);
title('equlized histogarm');
xlabel('intensity'),ylabel('number of pixels');
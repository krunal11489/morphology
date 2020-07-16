close all;
clear;
J = imread('fig1.tif');
%J = rgb2gray(I);
figure,imshow(J);
[m,n]=size(J);
k=0:255;
 for p=1:256
     c(p)= 0;
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
%figure,imhist(J);
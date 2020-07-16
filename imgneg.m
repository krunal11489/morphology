close all;
clear;
J = imread('partial_body_scan.tif');
%J = rgb2gray(I);
figure,imshow(J);
[m,n]=size(J);
 for i=1:m;
     for j=1:n;
         x=J(i,j);
         K(i,j)=255-x;
     end
 end
 figure,imshow(K);

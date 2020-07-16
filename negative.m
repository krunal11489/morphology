close all;
clear;
I = imread('partial_body_scan.tif');
[m,n]=size(I);
for i=1:m;
     for j=1:n;
         J(i,j)=255-I(i,j);
           
     end
end
figure,imshow(I); 
figure,imshow(J); 
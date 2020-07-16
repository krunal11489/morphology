close all;
I = imread('football.jpg');
J = rgb2gray(I);
figure,imshow(J);
[m,n]=size(J);
for i=1:m;
    for j=1:n;
        c(i,j)=0;
        x=J(i,j);
        c(i,j)=255-x;
    end
end
figure,imshow(uint8(c));
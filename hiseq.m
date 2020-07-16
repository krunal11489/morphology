close all;
I = imread('lor22d.jpg');
J = rgb2gray(I);
figure,imshow(J);
I2 = histeq(J);
figure,imshow(I2);
figure, imhist(I2);
figure, imhist(J)
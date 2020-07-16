clear;
close all;
I=true(500,500);
se=true(11,11);
figure,imshow(I);
J=erosion(I,se);
figure,imshow(J);
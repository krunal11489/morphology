clear;clc;
close all;
I = imread('I1.jpg');
 I=I(:,:,1);
J=bwmorph(I,'erode',2);
imshow(J);
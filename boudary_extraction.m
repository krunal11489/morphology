close all;
clear;clc;
I = imread('man.tif');
disp('enter s.e. according to thickness of boundry');
b=stlm;
J=ero_m(I,b);
K=I-J;
subplot(1,2,1),imshow(I);
subplot(1,2,2),imshow(K);
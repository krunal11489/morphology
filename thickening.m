clear;close all;clc;
I=imread('thick.tif');
J=cplmnt(I);
K=thin_f(J);
L=cplmnt(K);
M=disconnect(L);
figure,imshow(I);
figure,imshow(J);
figure,imshow(K);
figure,imshow(L);
figure,imshow(M);
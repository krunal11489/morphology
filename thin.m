% clear;close all;clc;
% I=imread('rgn_fill.tif');
% se=[0,0,0;2,1,2;1,1,1];
function[L]=thin(I,se)
J=pat_dec(I,se);
K=cplmnt(J);
L=intersection(I,K);
end
% figure,imshow(I);
% figure,imshow(J);
% figure,imshow(K);
% figure,imshow(L);
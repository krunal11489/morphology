% clear;close all;clc;
% I=imread('rgn_fill.tif');
% se=[0,0,0;2,1,2;1,1,1];
function[L]=thick(I,se)
J=pat_dec(I,se);
L=union(I,J);
end
% figure,imshow(I);
% figure,imshow(J);
% figure,imshow(K);
% figure,imshow(L);
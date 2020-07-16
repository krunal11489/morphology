clear;clc;close all;
I=imread('prune.tif');
J=bwmorph(I,'spur',3);
imshow(J);


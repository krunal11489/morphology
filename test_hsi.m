clear;
clc;
close all;
I = imread('football.jpg');
J=rgb2hsv(I);
figure,imshow(J);
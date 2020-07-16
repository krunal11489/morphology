clc;
clear;
close all;
f=50;
fs=100000;
t=0:1/fs:0.1;
w=2*pi*f;
x=2*sin(w.*t);
plot(t,x);

fs1=800;
t1=0:1/fs1:0.1;
x1=2*sin(w.*t1);
plot(t1,x1);
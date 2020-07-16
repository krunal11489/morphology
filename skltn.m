clear;clc;close all;
A=imread('circles.png');
figure,imshow(A);
[m,n]=size(A);
S(1:m,1:n)=false;
R(1:m,1:n)=false;
B(1:3,1:3)=true;
k=max_kero(A,B);
for i=0:k
    t1=k_ero(A,B,i);
    t2=opening(t1,B);
    t3=t1-t2;
    %figure,imshow(t3);
    d(:,:,i+1)=t3;
    S=union(S,t3);
end 
figure,imshow(S);
for i=0:k
    t4=k_dil(d(:,:,i+1),B,i);
    %figure,imshow(t4);
    R=union(R,t4);
end
figure,imshow(R);
    
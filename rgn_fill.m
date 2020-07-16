clear;clc;close all;
I=imread('rgn_fill.tif');
J=gry_to_bin(I,127);
K=cplmnt(J);
L=label(K);
[N,p]=hole_points(L,1000);
[m,n]=size(N);
b=[1,1,1;1,1,1;1,1,1];
while(1)
  M=N;  
  N=dil_m(N,b);
  N=intersection(N,K);
  %figure,imshow(N);
  if(N==M)
      break;
  end
end
O=union(N,J);
% figure,imshow(I);
% figure,imshow(L);
% figure,imshow(K);
subplot(1,3,2),imshow(N);
subplot(1,3,3),imshow(O);
subplot(1,3,1),imshow(J);
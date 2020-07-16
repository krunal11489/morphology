close all;
clear;
J = imread('dollar.tif');
%J = rgb2gray(I);
figure,imshow(J);
[m,n]=size(J);
for q=0:7;
    t=dec2bin(2^q);
    l=length(t);
    if(l<8)
        k(1:8-l)=48;    
    end
    k(8-l+1:8)=t(1:l);
    k=k-48;
    for i=1:m;
     for j=1:n;
         x=J(i,j);
         y=dec2bin(x);
         l=length(y);
         if(l<8)
             p(1:8-l)=48;
         end
         p(8-l+1:8)=y(1:l);
         p=p-48;
         z=k&p;
         if(z==0)
            J1(i,j)=0;
         else
            J1(i,j)=2^q;
         end
     end
    end
    figure,imshow(J1);
end
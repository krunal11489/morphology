close all;clear;
I = imread('football.jpg');
J = rgb2gray(I);
figure,imshow(J);
[m,n]=size(J);
for i=1:m;
     for j=1:n;
        K(i,j)=0;
     end
end 
for i=1:m;
     for j=1:n;
         if(j==320)
             x=J(i,j);
             x=y;
         end
         if(j~=320)
         x=J(i,j);
         y=J(i,j+1);
         end
         z=x-y;
         if(z>10)
             K(i,j)=255;
         end
     end
end
figure,imshow(K);
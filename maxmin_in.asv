close all;
J = imread('girl.tif');
%J = rgb2gray(I);
figure,imshow(J);
max_in=0;
min_in=255;
[m,n]=size(J);
 for i=1:m;
     for j=1:n;
         x=J(i,j);
         if(x<min_in)
             min_in=x;
         end
         if(x>max_in)
             max_in=x;
         end
     end
 end
 
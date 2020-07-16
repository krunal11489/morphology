close all;
I = imread('lor22d.jpg');
J = rgb2gray(I);
figure,imshow(J);
[m,n]=size(J);
for i=1:m;
     for j=1:n;
        K(i,j)=000;
     end
end 
 for i=1:m;
     for j=1:n;
         x=J(i,j);
         if(x>128)
             K(i,j)=255;    
         end   
     end
 end
 figure,imshow(K);
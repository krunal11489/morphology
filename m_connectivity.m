% clear;clc;close all;
% I=imread('thinned.tif');
% figure,imshow(I);
function[I]=m_connectivity(I)
[m n]=size(I);
J(1:m+2,1:n+2)=false;
for i=1:m
    for j=1:n
        J(i+1,j+1)=I(i,j);
    end
end
for i=2:m+1
    for j=2:n+1
        if(J(i,j)==true)
           if(J(i+1,j-1)==true)
               if(J(i,j-1)==true)
                   J(i,j-1)=false;I(i-1,j-2)=false;
               end
               if(J(i+1,j)==true)
                   J(i+1,j)=false;I(i,j-1)=false;
               end
           end
           if(J(i+1,j+1)==true)
               if(J(i+1,j)==true)
                   J(i+1,j)=false;I(i,j-1)=false;
               end
               if(J(i,j+1)==true)
                   J(i,j+1)=false;I(i-1,j)=false;
               end
           end
        end
    end
end
end
%figure,imshow(I);
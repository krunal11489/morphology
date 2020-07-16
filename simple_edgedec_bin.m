%clear;clc;close all;
%I=imread('rgn_fill.tif');
%J1=gry_to_bin(I,127);
%I=stlm;
function[K]=simple_edgedec_bin(I)
[m n]=size(I);
J(m+2,n+2)=false;
K(m,n)=false;
for i=1:m;
    for j=1:n;
        J(i+1,j+1)=I(i,j);
    end
end
for i=2:m+2;
    for j=2:n+2;
        if(J(i,j)~=J(i,j-1))
            if(J(i,j)==true)
                K(i-1,j-1)=true;
            else
                K(i-1,j-2)=true;
            end
        end
        if(J(i,j)~=J(i-1,j))
            if(J(i,j)==true)
                K(i-1,j-1)=true;
            else
                K(i-2,j-1)=true;
            end
        end
    end
end
end
% figure,imshow(I);
% %figure,imshow(J);
% figure,imshow(K);
close all;
clear;
K = imread('kakafull.jpg');
J = rgb2gray(K);
figure,imshow(J);
title('original image');
[m,n]=size(J);
J1(m+2,n+2)=0;
J2(m,n)=0;
w=[0 1 0;1 -4 1;0 1 0];
for i=1:m+2;
    for j=1:n+2;
        if(i>1 && i<m+2)
            if(j>1 && j<n+2)
                J1(i,j)=J(i-1,j-1);
            end
        end
    end
end
for i=2:m+1;
    for j=2:n+1;
        sum=0;
        for k=-1:1;
            for l=-1:1;
                sum=sum+w(k+2,l+2)*J1(i+k,j+l);
            end
        end
        J2(i-1,j-1)=sum;
    end
end
J3=uint8(J2);
figure,imshow(J3);
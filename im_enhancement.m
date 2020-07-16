close all;
clear;
J = imread('partial_body_scan.tif');
%J = rgb2gray(K);
figure,imshow(J);
title('original image');
[m,n]=size(J);
J1(m+2,n+2)=0;
J2(m,n)=0;
w=[1 1 1;1 -8 1;1 1 1];
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
% [m1,n1]=size(J);
% [m2,n2]=size(J3);
% m3=max(m1,m2);
% n3=max(n1,n2);
% J1(m1:m3,n1:n3)=0;
% J2(m2:m3,n2:n3)=0;
for i=1:m
    for j=1:n
            J4(i,j)=J(i,j)+J3(i,j);
    end 
end
J4=uint8(J4);
figure,imshow(uint8(J4));
J1(m+2,n+2)=0;
J2(m,n)=0;
w=[-1 -2 -1;0 0 0;1 2 1];
for i=1:m+2;
    for j=1:n+2;
        if(i>1 && i<m+2)
            if(j>1 && j<n+2)
                J1(i,j)=J4(i-1,j-1);
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